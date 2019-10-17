#include "PlaylistProcessor.h"
#include "PlaylistProcessorImpl.h"
#include "PlaylistProcessingNodes.h"
#include <unordered_map>
#include <iostream>

template<class T>
struct hash {
    std::size_t operator()(const T& value, typename std::enable_if<std::is_enum<T>::value>::type* = nullptr) const noexcept
    {
        return static_cast<size_t>(value);
    }
};

namespace
{
    using plsProcessor = PlaylistProcessorChain<pls::HeaderValidator, pls::TokenFilter, PostFilterConverter>;
    using wplProcessor = PlaylistProcessorChain<wpl::HeaderValidator, wpl::TokenFilter, PostFilterConverter>;
    using m3uProcessor = PlaylistProcessorChain<m3u::TokenFilter, PostFilterConverter>;

    const std::string M3U8_PLAYLIST_FORMAT_STRING {"m3u8"};
    const std::string PLS_PLAYLIST_FORMAT_STRING {"pls"};
    const std::string WPL_PLAYLIST_FORMAT_STRING {"wpl"};
    const std::string M3U_PLAYLIST_FORMAT_STRING {"m3u"};

    enum class PlaylistFormat
    {
        M3U,
        M3U8,
        PLS,
        WPL
    };

    const std::unordered_map<std::string, PlaylistFormat> FORMATS_MAP {
        {M3U_PLAYLIST_FORMAT_STRING, PlaylistFormat::M3U},
        {M3U8_PLAYLIST_FORMAT_STRING, PlaylistFormat::M3U8},
        {PLS_PLAYLIST_FORMAT_STRING, PlaylistFormat::PLS},
        {WPL_PLAYLIST_FORMAT_STRING, PlaylistFormat::WPL}
    };

    std::string getFileExtension(const std::string& path)
    {
        const std::size_t extStartPos { path.find_last_of('.') };

        if (extStartPos == std::string::npos)
        {
            return {};
        }

        return path.substr(extStartPos + 1, path.length());
    }
}

std::pair<bool, std::vector<std::string>> PlaylistProcessor::process(const std::string& playlistFilePath) const
{
    const std::string extension {getFileExtension(playlistFilePath)};

    std::cerr << "Path: " << playlistFilePath << " Parsed extension: " << extension << std::endl;

    if (extension.empty())
    {
        std::cerr << "Extension is empty, failure" << std::endl;
        return {false, {}};
    }

    auto format = FORMATS_MAP.find(extension);
    if (format == FORMATS_MAP.end())
    {
        std::cerr << "Extension is unsupported, failure" << std::endl;
        return {false, {}};
    }

    std::pair<bool, std::vector<std::string>> result;

    switch(format->second)
    {
        case PlaylistFormat::PLS:
        {
            result = plsProcessor{}.process(playlistFilePath);
            break;
        }
        case PlaylistFormat::WPL:
        {
            result = wplProcessor{}.process(playlistFilePath);
            break;
        }
        case PlaylistFormat::M3U:
        case PlaylistFormat::M3U8:
        {
            result = m3uProcessor{}.process(playlistFilePath);
            break;
        }
        default:
        {
            std::cerr << "Unsupported format, failure. Maybe forgot to add?" << std::endl;
        }
    }

    if (!result.first)
    {
        std::cerr << "Processing failed!" << std::endl;
        return {false, {}};
    }

    for (const auto& path : result.second)
    {
        std::cerr << "Parsed: " << path << std::endl;
    }

    return std::make_pair(true,
                          std::move(result.second));
}