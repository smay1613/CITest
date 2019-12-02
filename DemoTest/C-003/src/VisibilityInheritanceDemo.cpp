#include "gtest/gtest.h"

class X
{
protected:
	int Secret;
public:
	int Free;
	X() : Secret(4),Free(2) {}
	int MakeIt() { return Free + Secret;}
};
class Y1: private X
{
public:
	int MakeIt() { return Free + Secret; }
};
class Z1: public Y1
{
public:
	//int MakeIt() { return Free + Secret;}
};
TEST(Module8,PrivateInheritance)
{
  X x;
  Y1 y;
  Z1 z;
  ASSERT_EQ(x.MakeIt(),6);
  ASSERT_EQ(y.MakeIt(),6);
  //ASSERT_EQ(z.MakeIt(),6);
}

class Y2: protected X
{
public:
	int MakeIt() { return Free + Secret; }

};

class Z2: public Y2
{
public:
	int MakeIt() { return Free + Secret; }
};

TEST(Module8, ProtectedInheritance)
{
	  X x;
	  Y2 y;
	  Z2 z;
	  ASSERT_EQ(x.MakeIt(),6);
	  ASSERT_EQ(y.MakeIt(),6);
	  ASSERT_EQ(z.MakeIt(),6);
	  //ASSERT_EQ(z.Free,2);
	  ASSERT_EQ(x.Free,2);

}

class Y3: public X
{
public:
	int MakeIt() { return Free + Secret; }

};

class Z3: public X
{
public:
	int MakeIt() { return Free + Secret; }

};

TEST(Module8,PublicInteritance)
{
	  X x;
	  Y3 y;
	  Z3 z;
	  ASSERT_EQ(x.MakeIt(),6);
	  ASSERT_EQ(y.MakeIt(),6);
	  ASSERT_EQ(z.MakeIt(),6);
	  ASSERT_EQ(z.Free,2);
	  ASSERT_EQ(x.Free,2);
}


