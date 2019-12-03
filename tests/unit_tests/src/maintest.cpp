#include "maintest.h"
#include "impl.h"


TEST(Lab3,QuadroIsOk)
{
    int a = 2;
    int b = 8;
    int c = 4;

    double expectedX1 = -0.5857;
    double expectedX2 = -3.4142;
    double x1;
    double x2;

    ASSERT_TRUE(Quadro(a,b,c,x1,x2));

    ASSERT_NEAR(x1,expectedX1,0.01);
    ASSERT_NEAR(x2,expectedX2,0.01);
}


TEST(Lab3,QuadroIsNotSolution)
{
    int a = 8;
    int b = 1;
    int c = 9;

    double x1;
    double x2;

    ASSERT_FALSE(Quadro(a,b,c,x1,x2));
}
