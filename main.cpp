#include <map>
#include <iostream>
#include <unordered_map>

void Decoder(const char key[],char message[])
{
  int	i = 0;
  std::map<char, int> alphabet;

  for (char ch = 'a'; ch <= 'z'; ++ch)
    alphabet.insert(std::make_pair(ch, 0));
  while (key[i])
  {
    ++alphabet[key[i++]]; 
  }
  i = 0;
  std::unordered_map<char, char> ret;
  while (key[i])
  {
    ret.insert(std::make_pair(key[i], alphabet[key[i]] + 65));
    i++;
  }
  i = 0;
  for (auto it = ret.begin(); it != ret.end(); it++)
  {
    std::cout << it->second << std::endl;
    message[i] = it->second;
    i++;
  }
  
  std::cout << message << std::endl;
}

int	main()
{
  char ret[26];
  Decoder("ccaddfbbcacabaa", ret);
  return 0;
}
