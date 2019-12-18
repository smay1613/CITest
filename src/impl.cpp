#include "impl.h"
#include <iostream>
#include <istream>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <unordered_set>

std::vector<std::string> uniqueWord(const std::string string)
{
    std::string text = std::move(string);
 
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c){ return std::tolower(c); });
    std::istringstream iss(text);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
    std::unordered_set<std::string> set(std::move(results.begin()), std::move(results.end()));
    std::vector<std::string> ret(set.begin(), set.end());
    for (auto iter = ret.begin(); iter != ret.end(); iter++)
        std::cout << (*iter) << std::endl;
    return ret;
}