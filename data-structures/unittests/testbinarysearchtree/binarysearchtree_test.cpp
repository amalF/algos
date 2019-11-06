#include <limits.h>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "binarysearchtree.h"

using namespace ds;

TEST(BSTTest, isEmptyTest){
	BSTree<int> bst = BSTree<int>();
	EXPECT_EQ(bst.isEmpty(),true);
	EXPECT_EQ(bst.size(),0);
}

TEST(BSTTest, addEmptyTreeTest){
	BSTree<int> bst;
	bst.add(10);
	bst.add(2);
	bst.add(12);
	EXPECT_EQ(bst.size(),3);
}


