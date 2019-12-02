#include "gtest/gtest.h"
#include <string.h>
class Set
{
 private:
	int storage[20];
	int lastElement;
	bool find(int value) const;
 public:
	Set();
	Set(std::initializer_list<int> list);
	Set operator+(const int value);
	Set operator+(const Set op);

	friend bool operator==(const Set op1, const Set op2);
	friend bool operator!=(const Set op1, const Set op2);

};

bool operator==(const Set op1, const Set op2);
bool operator!=(const Set op1, const Set op2);

Set::Set() : lastElement(0)
{

}
Set::Set(std::initializer_list<int> list) : lastElement(0)
{
  for(auto c: list)
	if(!find(c))
		storage[lastElement++] = c;
}
bool Set::find(int value) const
{
	for(int i = 0; i < lastElement; i++)
		if(storage[i] == value)
			return true;
    return false;
}
Set Set::operator+(const int value)
{
	Set result;
	  for(int i = 0;i < lastElement;i++)
		  result.storage[result.lastElement++] = storage[i];
  if(!find(value))
	  result.storage[result.lastElement++] = value;
  return result;
}

Set Set::operator+(const Set op)
{
  Set result;
  for(int i = 0;i < lastElement;i++)
	  result.storage[result.lastElement++] = storage[i];
  for(int i = 0; i < op.lastElement; i++)
	  result = result + op.storage[i];
  return result;
}

bool operator==(const Set op1, const Set op2)
{
	for(int i = 0; i < op1.lastElement;i++)
		if(!op2.find(op1.storage[i])) return false;
	return true;

}

bool operator!=(const Set op1,const Set op2)
{
	return !operator==(op1,op2);
}

TEST(Module5, OverloadBinaryOperators)
{
  Set firstSet;
  firstSet = firstSet + 1;
  firstSet = firstSet + 2;
  firstSet = firstSet + 1;
  firstSet = firstSet + 3;
  Set secondSet{1,2};

  Set actualSet = firstSet + secondSet;

  const Set expectedSet{1,2,3};

  ASSERT_EQ(expectedSet,actualSet);
}

class AssocArray
{
private:
	struct
	{
		char key[5];
		int value;
	}storage[10];
 int lastElement;
public:

 int & operator[](const char key[]);
 AssocArray() : lastElement(0) {}
};


int & AssocArray::operator[](const char key[])
{
  for(int i = 0 ; i < lastElement;i++)
  {
	  if(strcmp(storage[i].key,key) == 0)
		  return storage[i].value;

  }
  strcpy(storage[lastElement].key,key);
  return storage[lastElement++].value;
}
TEST(Module5,OverloadBracketOperator)
{
	AssocArray myArray;
	myArray["123"] = 4;
	myArray["test"] = 5;

	ASSERT_EQ(myArray["123"],4);
	ASSERT_EQ(myArray["test"],5);

}
