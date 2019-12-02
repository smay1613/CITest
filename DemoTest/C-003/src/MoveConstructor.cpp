/*
 * MoveConstructor.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author:Luxoft
 *
 *      !!!You need use -fno-elide-constructors gcc options for turnoff return optimization for correct demonstration
 *      of these tests
 */
#include "gtest/gtest.h"

class FooWithoutMoveConstructor
{
private:
	char *Buffer;
	int size;
public:
	static int CountCopyObjet;
    FooWithoutMoveConstructor(char *src);
    FooWithoutMoveConstructor(const FooWithoutMoveConstructor &src);
    FooWithoutMoveConstructor Copy();
    char * GetBuffer() const { return Buffer;}
};

int FooWithoutMoveConstructor::CountCopyObjet = 0;

FooWithoutMoveConstructor::FooWithoutMoveConstructor(char *src)
{
	int i = 0,j;
	for(;src[i++];);
	Buffer = new char [i];
	size = i-1;
	for(j = 0; j < size; j++)
		Buffer[j] = src[j];
	Buffer[j] = '\0';
}
FooWithoutMoveConstructor::FooWithoutMoveConstructor(const FooWithoutMoveConstructor &src) :
		size(src.size)
{
	Buffer = new char[size+1];
	int i=0;
	for(;i<size;i++)
	  Buffer[i]= src.Buffer[i];
	Buffer[i] = '\0';
	CountCopyObjet++;
}
FooWithoutMoveConstructor FooWithoutMoveConstructor::Copy()
{
  FooWithoutMoveConstructor r(Buffer);
  return r;
}


TEST(Module7,CopyConstructorPerformanceProblem)
{
  FooWithoutMoveConstructor x("123456");
  FooWithoutMoveConstructor y = x.Copy();
  ASSERT_STREQ(y.GetBuffer(),"123456");
  ASSERT_EQ(FooWithoutMoveConstructor::CountCopyObjet,2);

}
//--------------------------------------------------------------------------------------------------------

class FooMoveConstructor
{
private:
	char *Buffer;
	int size;
public:
	int static CountCopyObject;
    FooMoveConstructor(char *src);
    FooMoveConstructor(const FooMoveConstructor &src);
    FooMoveConstructor(FooMoveConstructor &&src);
    FooMoveConstructor Copy();
    char * GetBuffer() const { return Buffer;}
};

int FooMoveConstructor::CountCopyObject = 0;

FooMoveConstructor::FooMoveConstructor(char *src)
{
	int i = 0,j;
	for(;src[i++];);
	Buffer = new char [i];
	size = i-1;
	for(j = 0; j < size; j++)
		Buffer[j] = src[j];
	Buffer[j] = '\0';
}
FooMoveConstructor::FooMoveConstructor(const FooMoveConstructor &src) :
		size(src.size)
{
	Buffer = new char[size+1];
	int i=0;
	for(;i<size;i++)
	  Buffer[i]= src.Buffer[i];
	Buffer[i] = '\0';
	CountCopyObject++;
}


FooMoveConstructor::FooMoveConstructor(FooMoveConstructor &&src)
{
	Buffer = src.Buffer;
	size = src.size;
	src.Buffer = nullptr;

}

FooMoveConstructor FooMoveConstructor::Copy()
{
  FooMoveConstructor r(Buffer);

  return r;
}

TEST(Module7,UseMoveConstructor)
{
  FooMoveConstructor x("123456");
  FooMoveConstructor y(x.Copy());
  ASSERT_EQ(FooMoveConstructor::CountCopyObject,0);
}
