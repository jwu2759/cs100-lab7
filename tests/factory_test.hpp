#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/factory.hpp"
#include "../src/base.hpp"

TEST(FactoryTest, FactoryTestAdd){
	Factory f;
	char* exp[] = {"","2","+","3"};
	char** expr = exp;
	Base* b = f.parse(expr, 5);
	EXPECT_EQ(b->evaluate(), 5);
	EXPECT_EQ(b->stringify(), "(2+3)");
}

TEST(FactoryTest, FactoryTestSub){
        Factory f;
        char* exp[] = {"","6","-","3"};
        char** expr = exp;
        Base* b = f.parse(expr, 5);
        EXPECT_EQ(b->evaluate(), 3);
	EXPECT_EQ(b->stringify(), "(6-3)");
}

TEST(FactoryTest, FactoryTestMult){
        Factory f;
        char* exp[] = {"","2","*","2"};
        char** expr = exp;
        Base* b = f.parse(expr, 5);
        EXPECT_EQ(b->evaluate(), 4);
        EXPECT_EQ(b->stringify(), "(2*2)");
}

TEST(FactoryTest, FactoryTestDiv){
        Factory f;
        char* exp[] = {"","10","/","4"};
        char** expr = exp;
        Base* b = f.parse(expr, 5);
        EXPECT_EQ(b->evaluate(), 2.5);
        EXPECT_EQ(b->stringify(), "(10/4)");
}

TEST(FactoryTest, FactoryTestPow){
        Factory f;
        char* exp[] = {"","4","**","2"};
        char** expr = exp;
        Base* b = f.parse(expr, 5);
        EXPECT_EQ(b->evaluate(), 16);
        EXPECT_EQ(b->stringify(), "(4**2)");
}

TEST(FactoryTest, FactoryTestNull){
        Factory f;
        char* exp[] = {"","6","-","*"};
        char** expr = exp;
        Base* b = f.parse(expr, 5);
        ASSERT_EQ(b, nullptr);
}


#endif
