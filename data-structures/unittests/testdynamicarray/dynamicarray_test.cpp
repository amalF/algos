#include <limits.h>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "dynamicarray.h"
#include "dynamicarray_test.h"

using ds::DynamicArray;

TEST(DynamicArrayTest, EmptyListTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	EXPECT_EQ(a1.isEmpty(),true);
}

TEST(DynamicArrayTest, RemoveFromEmptyListTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	ASSERT_THROW(a1.removeAt(0), std::out_of_range);

}


TEST(DynamicArrayTest, RemoveOutOfBoundTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	a1.add(1);
	a1.add(2);
	a1.add(3);
	ASSERT_THROW(a1.removeAt(3), std::out_of_range);
}

TEST(DynamicArrayTest, RemoveOutOfBoundTest2){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	for (int i=0;i<10;i++){ a1.add(i);}
	ASSERT_THROW(a1.removeAt(10), std::out_of_range);
}

TEST(DynamicArrayTest, RemoveOutOfBoundTest3){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	for (int i=0;i<10;i++){ a1.add(i);}
	ASSERT_THROW(a1.removeAt(-1), std::out_of_range);
}

TEST(DynamicArrayTest, RemovingTest){
	DynamicArray<std::string> a1 = DynamicArray<std::string>();
	std::string strs[] = {"a", "b", "c","d","e","g","h"};
	for (std::string s : strs){a1.add(s);}
	//ASSERT_NO_THROW(
	a1.remove("c");//);
	EXPECT_EQ(a1.size(),6);

	ASSERT_THROW(a1.remove("z"),std::invalid_argument);
}

TEST(DynamicArrayTest, FindTest){
	DynamicArray<char> a1 = DynamicArray<char>(10);
	char chars[] = {'a', 'b', 'c','d','e','g','h'};
	for (const char &c : chars){a1.add(c);}
	EXPECT_EQ(a1.find('a'),0);
	EXPECT_EQ(a1.find('c'),2);
	EXPECT_EQ(a1.find('g'),5);
	EXPECT_EQ(a1.find('v'),-1);
}

TEST(DynamicArrayTest, AddTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	for (int i=0;i<10;i++){ a1.add(i);}
	for (int i=0;i<10;i++){EXPECT_EQ(a1[i],i);}
}

TEST(DynamicArrayTest, AddGrowSizeTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	for (int i=0;i<15;i++){ a1.add(i);}
	for (int i=0;i<15;i++){EXPECT_EQ(a1[i],i);}
	EXPECT_EQ(a1.maxSize(),20);
}


TEST(DynamicArrayTest, InsertTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	for (int i=0;i<10;i++){ a1.add(i);}
	a1.insert(50,5);
	EXPECT_EQ(a1[5],50);
	EXPECT_EQ(a1.size(),11);
	EXPECT_EQ(a1.maxSize(),20);
}

TEST(DynamicArrayTest, AddAndRemoveTest){
	DynamicArray<float> a1 = DynamicArray<float>(10);
	for (int i=0;i<10;i++){ a1.add(1.0);}
	for (int i=0;i<10;i++){ a1.remove(1.0);}
	EXPECT_EQ(a1.isEmpty(),true);

	for (int i=0;i<10;i++){ a1.add(1.0);}
	for (int i=0;i<10;i++){ a1.removeAt(0);}
	EXPECT_EQ(a1.isEmpty(),true);
}

TEST(DynamicArrayTest, AddModifyValuesTest){

	DynamicArray<float> a1 = DynamicArray<float>(10);

	for (int i=0;i<10;i++){ a1.add(1.0);}
	for (int i=0;i<10;i++){ a1[i]=2.0;}
	for (int i=0;i<10;i++){ EXPECT_EQ(a1[i],2.0);}
}

TEST(DynamicArrayTest, GetSizeTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);

	for (int i=0, l=1;i<10;i++,l++){
		a1.add(1.0);
		EXPECT_EQ(a1.size(),l);
	}
}


TEST(DynamicArrayTest, GetCapacityTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	EXPECT_EQ(a1.maxSize(),10);

}

TEST(DynamicArrayTest, GrowSizeTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	EXPECT_EQ(a1.maxSize(),10);
	a1.growSize();
	EXPECT_EQ(a1.maxSize(),20);
}

TEST(DynamicArrayTest, ShrinkSizeTest){
	DynamicArray<int> a1 = DynamicArray<int>(10);
	for (int i=0;i<5;i++){a1.add(i);}
	EXPECT_EQ(a1.maxSize(),10);
	a1.shrinkSize();
	EXPECT_EQ(a1.maxSize(),5);
}
