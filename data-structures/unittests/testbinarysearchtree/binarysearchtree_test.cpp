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
	std::cout << bst << std::endl;
}

TEST(BSTTest, addTreeTest){
	BSTree<int> bst;
	bst.add(5);
	bst.add(4);
	bst.add(8);
	bst.add(1);
	bst.add(7);
	bst.add(10);
	bst.add(6);
	bst.add(9);
	EXPECT_EQ(bst.size(),8);
}



