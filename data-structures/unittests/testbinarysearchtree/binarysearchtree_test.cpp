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

TEST(BSTTest, findTest){
	BSTree<int> bst;
	bst.add(5);
	bst.add(4);
	bst.add(8);
	bst.add(1);

	EXPECT_EQ(bst.find(1)->data, 1);
	EXPECT_EQ(bst.find(0), nullptr);
	EXPECT_EQ(bst.find(8)->data, 8);
	EXPECT_EQ(bst.find(2), nullptr);
	EXPECT_EQ(bst.contains(1), true);
	EXPECT_EQ(bst.contains(0), false);
	EXPECT_EQ(bst.contains(8), true);
	EXPECT_EQ(bst.contains(2), false);
}


TEST(BSTTest, RemoveTest){
	BSTree<int> bst;
	bst.add(5);
	bst.add(4);
	bst.add(8);
	bst.add(1);
	bst.add(7);
	bst.add(9);
	bst.add(10);
	
	// remove a leaf node
	EXPECT_EQ(bst.remove(1), true);
	// remove a value that doesn't exist
	EXPECT_EQ(bst.remove(0), false);
	// remove a value with a right subtree  
	EXPECT_EQ(bst.remove(9), true);
	// remove a value with 2 subtrees
	EXPECT_EQ(bst.remove(8), true);
	EXPECT_EQ(bst.size(), 4);
}

TEST(BSTTest, MinMaxTest){
	BSTree<int> bst;
	BSTree<int> bst2;
	bst.add(5);
	bst.add(4);
	bst.add(8);
	bst.add(1);



	
	EXPECT_EQ(bst.min(),1);
	EXPECT_EQ(bst.max(),8);
	ASSERT_THROW(bst2.min(), std::runtime_error);
	ASSERT_THROW(bst2.max(), std::runtime_error);
}



