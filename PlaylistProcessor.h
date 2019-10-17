#pragma once
#include <vector>
#include <string>

class PlaylistProcessor
{
public:
    std::pair<bool,
              std::vector<std::string>> process(const std::string& playlistFilePath) const;
};