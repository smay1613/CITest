#include "gtest/gtest.h"

int Current = 0;
char OrderString[5]={0};
class K
{
 int x;
 public:
 K(int x): x(x) { OrderString[Current++] = 'K';}
};
class L
{
 int x;
 public:
 L(int x): x(x) { OrderString[Current++] = 'L';}
};
class M
{
 int x;
 public:
 M(int x): x(x) { OrderString[Current++] = 'M';}
};
class FooOrderCall
{
 K a;
 L b;
 M c;
 public:
  FooOrderCall(int a,int b,int c):
   c(c),a(a),b(b) {}
};


TEST(Module7,OrderCallConstructors)
{
	FooOrderCall v(1,2,3);
	ASSERT_STREQ(OrderString,"KLM");
}

char OrderStringWrongInit[5] = {0};
int  log_ = 0;
class FooOrderCallWithWrongInit
{
public:
	FooOrderCallWithWrongInit() {
		OrderStringWrongInit[log_++] = 'A';
    }
};
class BarOrderCallWithWrongInit
{
	FooOrderCallWithWrongInit tag;
public:
	BarOrderCallWithWrongInit()
   {
		tag = FooOrderCallWithWrongInit();
   }
};
TEST(Module7,OrderCallConstructorsWithWrongInitialization)
{
	BarOrderCallWithWrongInit v;
	ASSERT_STREQ(OrderStringWrongInit,"AA");
}
