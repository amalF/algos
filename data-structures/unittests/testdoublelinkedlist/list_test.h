#include "gtest/gtest.h"

class ListTest : public ::testing::Test {
	protected:
		ListTest();
		~ListTest();
		virtual void SetUp(){};
		virtual void TearDown(){};
};
