/*
 * CopyConstructorDemo.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Паша
 */
#include "gtest/gtest.h"

class FooTrouble
{
private:
	char *Buffer;
	int size;
public:
    FooTrouble(char *src);
    char * GetBuffer() const { return Buffer;}
    void FillBySymbol(char sym);
};

FooTrouble::FooTrouble(char *src)
{
	int i = 0,j;
	for(;src[i++];);
	Buffer = new char [i];
	size = i-1;
	for(j = 0; j < size; j++)
		Buffer[j] = src[j];
	Buffer[j] = '\0';
}
void FooTrouble::FillBySymbol(char sym)
{
	for(int i = 0; i < size;i++)
		Buffer[i] = sym;
}

TEST(Module7, TroubleWithoutCopyConstructor)
{
	FooTrouble a("123456"), b = a;
	a.FillBySymbol('=');
	ASSERT_STREQ(a.GetBuffer(),"======");
	//ASSERT_STREQ(b.GetBuffer(),"123456");
	ASSERT_STREQ(b.GetBuffer(),"======");
}
//-----------------------------------------------------------------------------------------
class FooCopyConstructor
{
private:
	char *Buffer;
	int size;
public:
    FooCopyConstructor(char *src);
    FooCopyConstructor(const FooCopyConstructor &src);
    char * GetBuffer() const { return Buffer;}
    void FillBySymbol(char sym);
};

FooCopyConstructor::FooCopyConstructor(char *src)
{
	int i = 0,j;
	for(;src[i++];);
	Buffer = new char [i];
	size = i-1;
	for(j = 0; j < size; j++)
		Buffer[j] = src[j];
	Buffer[j] = '\0';
}
FooCopyConstructor::FooCopyConstructor(const FooCopyConstructor &src) :
		size(src.size)
{
	Buffer = new char[size+1];
	int i=0;
	for(;i<size;i++)
	  Buffer[i]= src.Buffer[i];
	Buffer[i] = '\0';
}
void FooCopyConstructor::FillBySymbol(char sym)
{
	for(int i = 0; i < size;i++)
		Buffer[i] = sym;
}

TEST(Module7, UseCopyConstructor)
{
	FooCopyConstructor a("123456"), b = a;
	a.FillBySymbol('=');
	ASSERT_STREQ(a.GetBuffer(),"======");
	ASSERT_STREQ(b.GetBuffer(),"123456");
}

