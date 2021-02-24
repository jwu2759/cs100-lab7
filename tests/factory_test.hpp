#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "../src/factory.hpp"
#include "../src/base.hpp"

TEST(FactoryTest, FactoryTestAdd){
	Factory f;
	char* exp[] = {"","2","+","3"};
	Base* b = f.parse(exp, 5);
	EXPECT_EQ(b->evaluate(), 5);
	EXPECT_EQ(b->stringify(), "(2+3)");
}

TEST(FactoryTest, FactoryTestSub){
        Factory f;
        char* exp[] = {"","6","-","3"};
        Base* b = f.parse(exp, 5);
        EXPECT_EQ(b->evaluate(), 3);
	EXPECT_EQ(b->stringify(), "(6-3)");
}

TEST(FactoryTest, FactoryTestMult){
        Factory f;
        char* exp[] = {"","2","*","2"};
        Base* b = f.parse(exp, 5);
        EXPECT_EQ(b->evaluate(), 4);
        EXPECT_EQ(b->stringify(), "(2*2)");
}

TEST(FactoryTest, FactoryTestDiv){
        Factory f;
        char* exp[] = {"","10","/","4"};
        Base* b = f.parse(exp, 5);
        EXPECT_EQ(b->evaluate(), 2.5);
        EXPECT_EQ(b->stringify(), "(10/4)");
}

TEST(FactoryTest, FactoryTestPow){
        Factory f;
        char* exp[] = {"","4","**","2"};
        Base* b = f.parse(exp, 5);
        EXPECT_EQ(b->evaluate(), 16);
        EXPECT_EQ(b->stringify(), "(4**2)");
}

TEST(FactoryTest, FactoryTestNull){
        Factory f;
        char* exp[] = {"","6","-","*"};
        Base* b = f.parse(exp, 5);
        ASSERT_EQ(b, nullptr);
}

TEST(FactoryTest, FactoryTestFull1){
	Factory f;
	char* exp[] = {"","2","+","3","*","4","/","5","-","3"};
	Base* b = f.parse(exp,10);
	EXPECT_EQ(b->evaluate(), 1);
	EXPECT_EQ(b->stringify(), "((((2+3)*4)/5)-3)");
}

TEST(FactoryTest, FactoryTestFull2){
	Factory f;
	char* exp[] = {"","3","**","2","+","7","/","4","-","3","*","5"};
	Base* b = f.parse(exp,12);
	EXPECT_EQ(b->evaluate(), 5);
	EXPECT_EQ(b->stringify(), "(((((3**2)+7)/4)-3)*5)");
}

#endif
