#include "gtest/gtest.h"

TEST(Module3, AddressDemo)
{
	int SomeVar = 5;
	ASSERT_EQ(*&SomeVar,SomeVar);
}

