#include "gtest/gtest.h"

class HeapTest : public ::testing::Test {
	protected:
		HeapTest();
		~HeapTest();
		virtual void SetUp(){};
		virtual void TearDown(){};
};
