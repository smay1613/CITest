#include "impl.h"

#include <map>
#include <iostream>
#include <unordered_map>
#include <algorithm>

std::string		remove_duplicates(std::string str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		for (int j = 0; j < str.size(); ++j)
		{
			if (i != j)
			{
				if (str[i] == str[j])
				{
					str.erase(j, 1);
					j--;
				}
			}
		}
	}
	return str;
}

void			Decoder(const char key[],char message[])
{
	std::map<char, int> alphabet;
	std::string key_str(key);

	for (char ch = 'a'; ch <= 'z'; ++ch)
		alphabet.insert(std::make_pair(ch, 0));
	for (int i = 0; i < key_str.size(); i++)
	{
		++alphabet[key[i]]; 
	}
	key_str = remove_duplicates(key_str);
	for (int i = 0; i < key_str.size(); i++)
	{
		message[i] = (alphabet[key_str[i]] + '@');
	}
}
