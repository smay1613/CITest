#include  "gtest/gtest.h"

#define SIZEOFPOINTER sizeof(void*) == 4 ? 4:8

int & rmax(int n,int d[])
{
 int im = 0;
 for(int i=1; i < n; i++)
  im = d[im] > d[i] ? im : i;
 return d[im];
}
int Sum(int n,int d[])
{
	int sum = 0;
	for(int i = 0; i<n;i++)
		sum+=d[i];
	return sum;
}
TEST(Module5,ReferenceDemo)
{
	int n = 4;
	 int x[ ] = {10,20,30,14};
	 rmax(n,x) = 0;
     ASSERT_EQ(Sum(n,x),44);
}

TEST(Module5,ReferenceSpecialCases)
{
	unsigned int var = 5;
	//int &intRef = var;
	unsigned int & uintRef = var;
	//intRef = 4;
	uintRef = 2;
	ASSERT_EQ(var,2);
	//ASSERT_EQ(intRef,4);
	ASSERT_EQ(uintRef,2);
}

class FooWithReferenceField
{
public:
	double & refField;

};

TEST(Module5,ReferenceField)
{
	double k =2.0;
	FooWithReferenceField var = { k };
	ASSERT_EQ(sizeof(var),SIZEOFPOINTER);
	ASSERT_EQ(sizeof(var.refField),8);
	ASSERT_EQ(var.refField,k);
	ASSERT_EQ(&var.refField,&k);
}

class FooWithSimpleField
{
public:
	double  refField;

};

TEST(Module5,SimpleField)
{
	double k =2.0;
	FooWithSimpleField var = { k };
	ASSERT_EQ(sizeof(var),8);
	ASSERT_EQ(sizeof(var.refField),8);
	ASSERT_EQ(var.refField,k);
	ASSERT_NE(&var.refField,&k);// &var.refField != &k
}
