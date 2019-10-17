#pragma once
#include <vector>
#include <string>

class PlaylistProcessingInfo;

namespace pls
{
    struct HeaderValidator
    {
        bool operator()(PlaylistProcessingInfo& data) const;
    };

    struct TokenFilter
    {
        bool operator()(PlaylistProcessingInfo& info) const;
    };
}

namespace wpl
{
    struct HeaderValidator
    {
        bool operator()(PlaylistProcessingInfo& data) const;
    };

    struct TokenFilter
    {
        bool operator()(PlaylistProcessingInfo& data) const;
    };
}

namespace m3u
{
    struct TokenFilter
    {
        bool operator()(PlaylistProcessingInfo& data) const;
    };
}

struct PostFilterConverter
{
    bool operator()(PlaylistProcessingInfo& info);

private:
    void convert(std::vector<std::string>& content) const;
    void removeInvalid(PlaylistProcessingInfo& info) const;
    void normalize(PlaylistProcessingInfo& info) const;
};