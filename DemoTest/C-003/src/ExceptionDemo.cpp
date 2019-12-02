#include "gtest/gtest.h"

class FooException
{

};

int  MakeThrow(int v)
{
	if (v > 5)
		throw FooException();
	return v + 5;
}
TEST(Module11,SimpleException)
{
	ASSERT_EQ(MakeThrow(5),10);
	ASSERT_THROW(MakeThrow(6),FooException);
}

class SubException: public FooException
{

};

int MakeInheritanceThrow(int v)
{
	if (v > 5)
		throw SubException();
	return v + 5;
}

TEST(Module11,InheritanceInException1)
{
  ASSERT_EQ(MakeThrow(5),10);
  try
  {
	  MakeInheritanceThrow(6);
  }
  catch(SubException)
  {
	  SUCCEED();
  }
  catch(FooException)
  {
	  FAIL();
  }
}

TEST(Module11,InheritanceInException2)
{
	ASSERT_EQ(MakeThrow(5),10);
	  try
	  {
		  MakeInheritanceThrow(6);
	  }
	  catch(FooException)
	  {
		  SUCCEED();
	  }
	  catch(SubException)
	  {
		  FAIL();
	  }
}
//------------------------------------------
class FooLifeCycleException
{
public:
	static int CountConstructors;
	static int CountDestructors;
	static int CountCopyConstructors;
	FooLifeCycleException()
	{CountConstructors++;}
	FooLifeCycleException(FooLifeCycleException &)
	{ CountCopyConstructors++;}
	~FooLifeCycleException()
	{CountDestructors++;}
};

int FooLifeCycleException::CountConstructors = 0;
int FooLifeCycleException::CountDestructors = 0;
int FooLifeCycleException::CountCopyConstructors = 0;

void MakeException()
{
	FooLifeCycleException e;
	throw e;
}
TEST(Module11,ObjectLifecycleInException)
{
	try
	{
		MakeException();
	}
	catch(FooLifeCycleException e)
	{
		ASSERT_EQ(FooLifeCycleException::CountConstructors,1);
		ASSERT_EQ(FooLifeCycleException::CountCopyConstructors,2);
		ASSERT_EQ(FooLifeCycleException::CountDestructors,1);
	}
}
