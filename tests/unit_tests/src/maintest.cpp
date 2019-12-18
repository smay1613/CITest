#include "maintest.h"
#include "impl.h"

#include <impl.h>
#include <gtest/gtest.h>

TEST(Lab9,Five)
{
    Integer v(5);

    char* actual = (char *)v;  // warning, old style cast
//    char* actual = v.operator char *();
//    char* actual = static_cast<char *>(v);

    ASSERT_STREQ(actual,"five");
}

TEST(Lab9,Seventeen)
{
    Integer v(7);

    char* actual = (char *)v;

    ASSERT_STREQ(actual,"seven");
}
