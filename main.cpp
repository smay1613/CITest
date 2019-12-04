#include <map>
#include <iostream>
#include <unordered_map>

void Decoder(const char key[],char message[])
{
  int	len = 0;
  std::map<char, int> alphabet;

  for (char ch = 'a'; ch <= 'z'; ++ch)
    alphabet.insert(std::make_pair(ch, 0));
  while (key[len])
  {
    ++alphabet[key[len++]]; 
  }
  std::unordered_map<char, char> ret;
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len; j++)
    {
      if (i != j)
      {
	if (key[i] == key[j])
	{
	  std::swap(key[len - 1], key[j]);
	  len--;
	}
      }
    }
  }
  for (int i = 0; i < len; i++)
  {
    //Perevesti novuya stroku v message
  }
  std::cout << message << std::endl;
}

int	main()
{
  char ret[26];
  Decoder("ccaddfbbcacabaa", ret);
  return 0;
}
