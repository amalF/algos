#include "gtest/gtest.h"

class StackTest : public ::testing::Test {
	protected:
		StackTest();
		~StackTest();
		virtual void SetUp(){};
		virtual void TearDown(){};
};
