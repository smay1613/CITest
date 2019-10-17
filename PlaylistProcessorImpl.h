#pragma once
#include <fstream>
#include <tuple>
#include <vector>

class PlaylistProcessingInfo
{
public:
    std::vector<std::string> content;

    PlaylistProcessingInfo(std::string path)
        : m_filePath {std::move(path)},
          m_playlistStream {m_filePath},
          m_isValid {!m_playlistStream.fail()}
    {
    }

    std::ifstream& stream()
    {
        return m_playlistStream;
    }

    std::string path() const
    {
        return m_filePath;
    }

    bool isValid() const
    {
        return m_isValid;
    }
    void invalidate()
    {
        m_isValid = false;
    }

private:
    std::string m_filePath;
    std::ifstream m_playlistStream;
    bool m_isValid;
};

template<class... Nodes>
class PlaylistProcessorChain
{
public:
    PlaylistProcessorChain()
        : m_chain {}
    {
    }
    PlaylistProcessorChain(Nodes... nodes)
        : m_chain {nodes...}
    {
    }

    std::pair<bool, std::vector<std::string>> process(const std::string& path)
    {
        PlaylistProcessingInfo sharedInfo {path};
        if (!sharedInfo.isValid())
        {
            return std::make_pair(false, std::vector<std::string> {});
        }
        const bool result {for_each(m_chain, sharedInfo)};
        std::vector<std::string> content {std::move(sharedInfo.content)};
        return std::make_pair(result, content);
    }

private:
    std::tuple<Nodes...> m_chain;

    template<typename Tuple, typename Info, std::size_t I = 0,
             typename std::enable_if< I != std::tuple_size<Tuple>::value, void >::type* = nullptr>
    bool for_each(Tuple& tuple, Info& info)
    {
        const bool result {std::get<I>(tuple)(info)};
        if (!result || !info.isValid())
        {
            info.invalidate();
            return false;
        }
        return for_each<Tuple, Info, I + 1>(tuple, info);
    }

    template<typename Tuple, typename Info, std::size_t I = 0,
             typename std::enable_if< I == std::tuple_size<Tuple>::value, void >::type* = nullptr>
    bool for_each(Tuple&, Info&)
    {
        return true;
    }
};
