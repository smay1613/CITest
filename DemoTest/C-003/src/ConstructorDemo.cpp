/*
 * ConstructorDemo.cpp
 *
 *  Created on: 21 сент. 2017 г.
 *      Author: Паша
 */

#include "gtest/gtest.h"

class FooWithInitList
{
public:
	char* Buf;
	FooWithInitList(std::initializer_list<char> src);
};
FooWithInitList::FooWithInitList(std::initializer_list<char> src)
{
	Buf = new char [src.size()+1];
    int i = 0;
	for(auto c : src)
		Buf[i++] = c;
	Buf[i] = '\0';
}
TEST(Module7,ConstructorWithInitList)
{
	FooWithInitList x = {'a','b','c','d'};
	ASSERT_STREQ(x.Buf,"abcd");
}

class FooUniformInit
{
 private:
	 int k;
	 float x;
 public:
	 FooUniformInit(int a,float b=5.0) : k(a),x(b) {}
	 float GetSumKX() { return k + x;}
};

TEST(Module7,UniformInitialization)
{
	FooUniformInit a{1,2.0},b(3,1.0),c{1},d(2);
	ASSERT_EQ(a.GetSumKX(),3.0);
	ASSERT_EQ(b.GetSumKX(),4.0);
	ASSERT_EQ(c.GetSumKX(),6.0);
	ASSERT_EQ(d.GetSumKX(),7.0);
}

class FooExplicitySpecifyDefault
{
private:
	int k;
public:
	FooExplicitySpecifyDefault() = default;
	FooExplicitySpecifyDefault(int a) : k(a) {}
	int GetK() { return k;}
};

TEST(Module7,ExplicitySpecifyDefault)
{
  FooExplicitySpecifyDefault a,b{2};
  //ASSERT_EQ(a.GetK(),0);
  ASSERT_EQ(b.GetK(),2);
}

class FooWithoutCopyConstructor
{
	int k;
public:
	FooWithoutCopyConstructor(int a): k(a) {};
    //FooWithoutCopyConstructor(const FooWithoutCopyConstructor & ) = delete;
    int GetK() { return k;}
};

TEST(Module7,PreventToUseCopyConstructor)
{
	FooWithoutCopyConstructor x(2);
	FooWithoutCopyConstructor y = x;
	ASSERT_EQ(x.GetK(),2);
	ASSERT_EQ(y.GetK(),2);
}

class FooWithConstructorDelegation
{
	int x;
	int y;
public:
	FooWithConstructorDelegation(int a) : x(a+2),y(a+7) {}
	FooWithConstructorDelegation() :
		FooWithConstructorDelegation(1)
			{ y = 0;}
	int GetXY() { return x+y;}
};
TEST(Module7,ConstructorDelegation)
{
  FooWithConstructorDelegation a(2);
  FooWithConstructorDelegation b;
  ASSERT_EQ(a.GetXY(),13);
  ASSERT_EQ(b.GetXY(),3);
}

class U
{
public:
    int x;
    U(int x) : x(x) {}
    U(): x(0) {}
};
class V
{
    public:
    U b;
    U c;
};
class G
{
    public:
    V a1;
    V a2;
    V d;
    G() {}
    G(int a,int b,int c,int d) {}
    G(V a1,V a2):a1(a1),a2(a2) {}
};

TEST(Module7,CallConstructorManyBrackets)
{
	G g {{{1}, {2}}, {{3}, {4}}};

	ASSERT_EQ(g.a1.b.x,1);
	ASSERT_EQ(g.a1.c.x,2);
	ASSERT_EQ(g.a2.b.x,3);
	ASSERT_EQ(g.a2.c.x,4);
}

TEST(Module7,CallConstrustorOneBracket)
{
	G g = {1,2,3,4};
	ASSERT_EQ(g.a1.b.x,0);
	ASSERT_EQ(g.a1.c.x,0);
	ASSERT_EQ(g.a2.b.x,0);
	ASSERT_EQ(g.a2.c.x,0);
	ASSERT_EQ(g.d.b.x,0);
	ASSERT_EQ(g.d.c.x,0);
}

TEST(Module7, CallConstructorForArray)
{
	G g[1];
	ASSERT_EQ(g[0].a1.b.x,0);
	ASSERT_EQ(g[0].a1.c.x,0);
	ASSERT_EQ(g[0].a2.b.x,0);
	ASSERT_EQ(g[0].a2.c.x,0);
	ASSERT_EQ(g[0].d.b.x,0);
	ASSERT_EQ(g[0].d.c.x,0);
}
