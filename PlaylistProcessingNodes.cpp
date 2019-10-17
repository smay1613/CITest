#include "PlaylistProcessingNodes.h"
#include "PlaylistProcessorImpl.h"
#include <algorithm>
#include <istream>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>

struct line : public std::string {
};

std::istream& operator>>(std::istream& source, line& target)
{
    std::getline(source, target);
    return source;
}

struct tag : public std::string {
};

std::istream& operator>>(std::istream& source, tag& target)
{
    std::getline(source, target, '>');
    return source;
}

bool startsWith(const std::string& string, const std::string& substring)
{
    return string.rfind(substring, 0) == 0;
}

template<class InputIt, class OutputIt, class UnaryP, class UnaryOp>
void transform_if(InputIt first, InputIt last, OutputIt dest, UnaryP pred, UnaryOp transform)
{
    while (first != last)
    {
        if (pred(*first))
        {
            *dest++ = transform(*first);
        }

        ++first;
    }
}

template<class EntryType>
bool validateHeader(PlaylistProcessingInfo& data, const std::string& expectedHeader)
{
    EntryType header;
    data.stream() >> header;
    std::transform(header.begin(), header.end(), header.begin(), tolower);
    return startsWith(header, expectedHeader);
}

template<class EntryType, class AttributeValidationPredicate, class ValueExtractionUnaryFunc>
bool extractTokens(PlaylistProcessingInfo& info, AttributeValidationPredicate containsAttribute, ValueExtractionUnaryFunc extractAttribute)
{
    if (info.stream().fail())
    {
        std::cerr << "Something went wrong with processed file!" << std::endl;
        return false;
    }

    using stream_iterator = std::istream_iterator<EntryType>;
    std::vector<std::string> songsDataTokens;

    transform_if(stream_iterator(info.stream()), stream_iterator {},
                 std::back_inserter(songsDataTokens), containsAttribute, extractAttribute);

    info.content.swap(songsDataTokens);

    return true;
}

namespace pls
{
bool HeaderValidator::operator()(PlaylistProcessingInfo& data) const
{
    line header;
    data.stream() >> header;
    std::transform(header.begin(), header.end(), header.begin(), tolower);
    return header == "[playlist]";
}

bool TokenFilter::operator()(PlaylistProcessingInfo& info) const
{
    const static std::string filteredAttribute {"File"};

    auto containsAttribute = [](const line& line) {
        return startsWith(line, filteredAttribute);
    };
    auto extractAttribute = [](const line& line) {
        const static boost::regex groupSeparatorExpression {"(" + filteredAttribute + ".*)" + "=" + "(.*)"};
        boost::smatch result;
        const bool matched {boost::regex_search(line, result, groupSeparatorExpression)};
        return matched ? result.str(2) : std::string {};
    };

    return extractTokens<line>(info, containsAttribute, extractAttribute);
}
} // namespace pls

bool PostFilterConverter::operator()(PlaylistProcessingInfo& info)
{
    convert(info.content);
    normalize(info);
    removeInvalid(info);

    return true;
}

void PostFilterConverter::convert(std::vector<std::string>& content) const
{
    auto toPosix = [](std::string& value) {
        std::replace(value.begin(), value.end(), '\\', '/');
    };
    for (auto& value : content)
    {
        toPosix(value);
    }
}

void PostFilterConverter::removeInvalid(PlaylistProcessingInfo& info) const
{
    boost::filesystem::path root {info.path()};
    root = root.parent_path();
    std::function<bool(std::string&)> isValidAndExists = [&root](const std::string& value) {
        boost::system::error_code status {};
        const boost::filesystem::path& normalized {boost::filesystem::canonical(value, root, status)};
        std::cerr << "Normalized path: " << normalized.string() << "Status: " << status.message() << std::endl;
        return status.value() == boost::system::errc::success;
    };
    auto& content = info.content;
    content.erase(std::remove_if(content.begin(), content.end(),
                                 std::not1(isValidAndExists)),
                  content.end());
}
void PostFilterConverter::normalize(PlaylistProcessingInfo& info) const
{
    boost::filesystem::path playlistPath {info.path()};
    auto toAbsolute = [&playlistPath](std::string& value) {
        value = boost::filesystem::absolute(value, playlistPath.parent_path()).lexically_normal().string();
    };
    for (auto& value : info.content)
    {
        boost::trim(value);
        toAbsolute(value);
    }
}

namespace wpl
{
bool HeaderValidator::operator()(PlaylistProcessingInfo& data) const
{
    return validateHeader<tag>(data, "<?wpl");
}

bool TokenFilter::operator()(PlaylistProcessingInfo& info) const
{
    const static std::string filteredAttribute {"<media|<audio|<ref"};
    const static std::string filteredValue {"src"};

    auto containsAttribute = [](const tag& tag) {
        boost::smatch result;
        const bool matched {boost::regex_search(tag, result, boost::regex {filteredAttribute})};
        return matched;
    };
    auto extractAttribute = [](const tag& line) {
        const static boost::regex groupSeparatorExpression {"(" + filteredValue + "*?=)" + "\"(.*?)\""};
        boost::smatch result;
        const bool matched {boost::regex_search(line, result, groupSeparatorExpression)};
        return matched ? result.str(2) : std::string {};
    };

    return extractTokens<tag>(info, containsAttribute, extractAttribute);
}
} // namespace wpl

namespace m3u
{
bool TokenFilter::operator()(PlaylistProcessingInfo& info) const
{
    const static std::string commentAttribute {"#"};
    auto containsAttribute = [](const line& line) {
        return !line.empty() && !startsWith(line, commentAttribute);
    };
    auto extractAttribute = [](const line& line) {
        return line;
    };

    return extractTokens<line>(info, containsAttribute, extractAttribute);
}
} // namespace m3u