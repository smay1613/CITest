/*
 * PolymorphDemo.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Паша
 */
#include "gtest/gtest.h"

class Anv
{
public:
  int GetValue() { return 2;}
};
class Bnv : public Anv
{
public:
	int GetValue() { return 3;}
};

TEST(Module8,NonVirtualMethod)
{
	Anv *p = new Bnv;
	ASSERT_EQ(p->GetValue(),2);
}
//------------------------------------------------------------------------
class Avir
{
public:
	virtual int GetValue() { return 2;}
};

class Bvir : public Avir
{
public:
   int GetValue() override { return 3;}
};

TEST(Module8,VirtualMethod)
{
	Avir *p = new Bvir;
	ASSERT_EQ(p->GetValue(),3);
}
//----------------------------------------------------------------------------

class ICharProducer
{
public:
	virtual char getChar() = 0;
};
class CharA : public ICharProducer
{
public:
	char getChar() override { return 'A';}
};

class CharB : public ICharProducer
{
public:
	char getChar() override { return 'B';}
};

class StringFactory
{
private:
	ICharProducer * chars[5];
public:
	StringFactory();
	char *CreateString(char *buf);
	CharA a;
	CharB b;
};

StringFactory::StringFactory()
{

	chars[0]=&b;chars[1]=&b;chars[2]=&a;chars[3]=&b;chars[4]=&a;
}
char *StringFactory::CreateString(char *buf)
{
	int i=0;
	for(;i<5;i++)
		buf[i] = chars[i]->getChar();
	buf[i] = '\0';
	return buf;
}
TEST(Module8,UseAbstractClass)
{
	StringFactory f;
	char Buffer[6]={0};
	ASSERT_STREQ(f.CreateString(Buffer),"BBABA");
}
