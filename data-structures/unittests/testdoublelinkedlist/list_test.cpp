#include <limits.h>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "list.h"
#include "list_test.h"

using ds::List;

TEST(ListTest, EmptyListTest){
  List<int> a1 = List<int>();
  EXPECT_EQ(a1.isEmpty(),true);
  EXPECT_EQ(a1.size(),0);
}

TEST(ListTest, PushFrontEmptyListTest){
  List<int> a1 = List<int>();
  a1.push_front(1);
  EXPECT_EQ(a1.size(),1);
  EXPECT_EQ(a1.front(), 1);
  EXPECT_EQ(a1.back(), 1);
}

TEST(ListTest, PushFrontTest){
  List<int> a1 = List<int>();
  for (int i=0;i<10;i++){
    a1.push_front(i);
  }
  EXPECT_EQ(a1.size(),10);
  EXPECT_EQ(a1.front(), 9);
  EXPECT_EQ(a1.back(), 0);
}

TEST(ListTest, PushBackEmptyListTest){
  List<int> a1 = List<int>();
  a1.push_back(10);
  EXPECT_EQ(a1.front(),10);
  EXPECT_EQ(a1.back(),10);
  EXPECT_EQ(a1.size(),1);
}

TEST(ListTest, PushBackTest){
  List<int> a1 = List<int>();
  for (int i=0;i<10;i++){
    a1.push_back(i);
  }
  EXPECT_EQ(a1.size(),10);
  EXPECT_EQ(a1.front(), 0);
  EXPECT_EQ(a1.back(), 9);
}

TEST(ListTest, InsertOutOfBoundsTest){
  List<int> a1 = List<int>();
  for (int i=0;i<10;i++){
    a1.push_front(i+1);
  }
  ASSERT_THROW(a1.insert(11,15), std::out_of_range);
}

TEST(ListTest, InsertOutOfBounds2Test){
  List<int> a1 = List<int>();
  for (int i=0;i<10;i++){
    a1.push_front(i+1);
  }
  ASSERT_THROW(a1.insert(50,-1), std::out_of_range);
}

TEST(ListTest, GetTest){
  List<std::string> a1 = List<std::string>();
  std::string strs[] = {"a", "b", "c","d","e","g","h"};
  for (const std::string &s : strs){a1.push_back(s);}

  EXPECT_EQ(a1.val(0), "a");
  EXPECT_EQ(a1.val(3), "d");
  ASSERT_THROW(a1.val(10),std::out_of_range);
}

TEST(ListTest, InsertTest){
  List<int> a1 = List<int>();
  for (int i=0;i<10;i++){
    a1.push_front(i+1);
  }
  //insert at the front
  a1.insert(1,0);
  EXPECT_EQ(a1.size(),11);
  //insert in the middle
  a1.insert(10,5);
  EXPECT_EQ(a1.size(),12);
  //insert at the end
  a1.insert(20,11);

  EXPECT_EQ(a1.front(),1);
  EXPECT_EQ(a1.val(5),10);
  EXPECT_EQ(a1.back(),20);
  EXPECT_EQ(a1.size(),13);
}

TEST(ListTest, PopFromEmptyListTest){
  List<int> a1 = List<int>();
  ASSERT_THROW(a1.pop_front(), std::runtime_error);
  ASSERT_THROW(a1.pop_back(), std::runtime_error);
}


TEST(ListTest, PopTest){
  List<int> a1 = List<int>();
  for (int i=0;i<10;i++){
    a1.push_back(i+1);
  }

  a1.pop_front();
  EXPECT_EQ(a1.size(),9);
  EXPECT_EQ(a1.front(),2);
  EXPECT_EQ(a1.back(),10);

  a1.pop_back();
  a1.pop_back();

  EXPECT_EQ(a1.size(),7);
  EXPECT_EQ(a1.front(),2);
  EXPECT_EQ(a1.back(),8);

  for (int i=0;i<7;i++){
    a1.pop_back();
  }
  EXPECT_EQ(a1.isEmpty(),true);
}

TEST(ListTest, RemoveFromEmptyListTest){
  List<int> a1 = List<int>();
  ASSERT_THROW(a1.remove(0), std::out_of_range);
}

TEST(ListTest, RemoveOutOfBoundTest){
  List<int> a1 = List<int>();
  const int elements[] = {1,2,3};
  for (const int &elt : elements){
    a1.push_front(elt);
  }
  ASSERT_THROW(a1.remove(3), std::out_of_range);
}

TEST(ListTest, RemoveOutOfBoundTest3){
  List<int> a1 = List<int>();
  const int elements[] = {1,2,3,4};
  for (const int &elt : elements){
    a1.push_front(elt);
  }
  ASSERT_THROW(a1.remove(-1), std::out_of_range);
}

TEST(ListTest, RemoveAtTest){
  List<std::string> a1 = List<std::string>();
  std::string strs[] = {"a", "b", "c","d","e","g","h"};
  for (const std::string & s : strs){a1.push_back(s);}
  ASSERT_NO_THROW(a1.remove(2));
  EXPECT_EQ(a1.size(),6);
  EXPECT_EQ(a1.val(2),"d");
}

TEST(ListTest, ContainsTest){
  List<char> a1 = List<char>();
  char chars[] = {'a', 'b', 'c','d','e','g','h'};
  for (const char &c : chars){a1.push_back(c);}
  EXPECT_EQ(a1.contains('a'),true);
  EXPECT_EQ(a1.contains('c'),true);
  EXPECT_EQ(a1.contains('g'),true);
  EXPECT_EQ(a1.contains('v'),false);
}
TEST(ListTest, RemovingTest){
  List<std::string> a1 = List<std::string>();
  std::string strs[] = {"a", "b", "c","d","e","g","h"};
  for (const std::string & s : strs){a1.push_back(s);}
  a1.remove_all("c");
  EXPECT_EQ(a1.size(),6);
}

TEST(ListTest, RemovingWithDuplicatesTest){
  List<std::string> a1 = List<std::string>();
  std::string strs[] = {"a", "a", "a","b","b","b","b"};
  for (const std::string & s : strs){a1.push_back(s);}
  a1.remove_all("b");
  EXPECT_EQ(a1.size(),3);
  EXPECT_EQ(a1.back(),"a");
  a1.remove_all("a");
  EXPECT_EQ(a1.isEmpty(), true);
}


TEST(ListTest, GetSizeTest){
  List<int> a1 = List<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  int l = 0;
  for (const int & elt : elements){
    a1.push_back(elt);
    l++;
    EXPECT_EQ(a1.size(),l);
  }
}

TEST(ListTest, InsertOrderedAtFrontTest){

  const int elements [] = {1,2,3,7,49};

  List<int> list0;

  for (const int & elt : elements){
    list0.push_back(elt);
  }

  List<int> list0_correct = list0;
  list0_correct.push_front(-100);

  list0.insertOrdered(-100);
  EXPECT_EQ(list0, list0_correct);
  EXPECT_EQ(list0.size(), list0_correct.size());
  EXPECT_EQ(list0.front(), -100);

}

TEST(ListTest, InsertOrderedAtEndTest){

  const int elements [] = {1,2,3,7,49};
  List<int> list0;
  for (const int & elt : elements){
    list0.push_back(elt);
  }
  List<int> list0_correct = list0;
  list0_correct.push_back(100);

  list0.insertOrdered(100);
  EXPECT_EQ(list0, list0_correct);
  EXPECT_EQ(list0.size(), list0_correct.size());
  EXPECT_EQ(list0.back(),100);
}

TEST(ListTest, InsertOrderedAtMiddleTest){

  const int elements [] = {1,2,3,7,49};
  const int expected [] = {1,2,3,5,7,49};

  List<int> list0;
  List<int> list0_correct;

  for (const int & elt : elements){
    list0.push_back(elt);
  }
  for (const int & elt : expected){
    list0_correct.push_back(elt);
  }
  const int item = 5;
  list0.insertOrdered(item);
  EXPECT_EQ(list0, list0_correct);
  EXPECT_EQ(list0.size(), list0_correct.size());
  EXPECT_EQ(list0.val(3),5);
}

TEST(ListTest, InsertOrderedEmptyTest){
  List<int> l;
  auto expectedList = l;
  const int a = 100;
  expectedList.push_back(a);
  auto result = l;
  result.insertOrdered(a);
  EXPECT_EQ(result, expectedList);
  EXPECT_EQ(result.size(), expectedList.size());
}

TEST(ListTest, IsSortedTest){
  const int elements [] = {1,2,3,7,49};
  List<int> list0;
  for (const int & elt : elements){
    list0.push_back(elt);
  }

  EXPECT_EQ(list0.isSorted(), true);

  const int a = 10;
  list0.push_back(a);
  EXPECT_EQ(list0.isSorted(), false);
}

TEST(ListTest, SplitHalvesEvenSizeTest){
  const int elements [] = {1,2,3,7,49,5};
  const int L[] = {1,2,3};
  const int R[] = {7,49,5};
  List<int> list0;
  List<int> expectedFirstHalf;
  List<int> expectedSecondHalf;

  for (const int & elt : elements){
    list0.push_back(elt);
  }
  for (const int & elt : L){
    expectedFirstHalf.push_back(elt);
  }

  for (const int & elt : R){
    expectedSecondHalf.push_back(elt);
  }

  auto splits = list0.splitHalves();
  EXPECT_EQ(std::get<0>(splits).size(), 3);
  EXPECT_EQ(std::get<1>(splits).size(), 3);
  EXPECT_EQ(std::get<0>(splits), expectedFirstHalf);
  EXPECT_EQ(std::get<1>(splits), expectedSecondHalf);
}

TEST(ListTest, MergeBothListEmptyTest){
  List<int> left;
  List<int> right;
  List<int> expectedList;
  auto result = left.merge(right);
  EXPECT_EQ(result.size(),0);
  EXPECT_EQ(result, expectedList);
}

TEST(ListTest, MergeLeftEmptyTest){
  const int R[] = {1, 2, 3};
  List<int> left;
  List<int> right;

  for (const int & elt : R){
    right.push_back(elt);
  }
  auto result = left.merge(right);
  //std::cout << result;
  EXPECT_EQ(result, right);
  EXPECT_EQ(result.size(),3);
}

TEST(ListTest, MergeRightEmptyTest){
  const int L[] = {5,7,49};
  List<int> left;
  List<int> right;

  for (const int & elt : L){
    left.push_back(elt);
  }

  auto result = left.merge(right);
  //std::cout << result;
  EXPECT_EQ(result, left);
  EXPECT_EQ(result.size(),3);
}

TEST(ListTest, MergeListSameSizeTest){
  const int L[] = {1,5,10,20};
  const int R[] = {2,4,11,19};
  const int elements[] = {1,2,4,5,10,11,19,20};
  List<int> left;
  List<int> right;
  List<int> expectedList;

  for (const int & elt : L){
    left.push_back(elt);
  }

  for (const int & elt : R){
    right.push_back(elt);
  }

  for (const int & elt : elements){
    expectedList.push_back(elt);
  }

  auto result = left.merge(right);

  EXPECT_EQ(result, expectedList);
  EXPECT_EQ(result.size(), 8);
}

TEST(ListTest, MergeListLeftLongerTest){
  const int L[] = {1,5,10,20};
  const int R[] = {2,4};
  const int elements[] = {1,2,4,5,10,20};
  List<int> left;
  List<int> right;
  List<int> expectedList;

  for (const int & elt : L){
    left.push_back(elt);
  }

  for (const int & elt : R){
    right.push_back(elt);
  }

  for (const int & elt : elements){
    expectedList.push_back(elt);
  }

  auto result = left.merge(right);
  EXPECT_EQ(result, expectedList);
  EXPECT_EQ(result.size(), 6);
}

TEST(ListTest, MergeListRightLongerTest){
  const int L[] = {1,20};
  const int R[] = {2,4,11,19};
  const int elements[] = {1,2,4,11,19,20};
  List<int> left;
  List<int> right;
  List<int> expectedList;

  for (const int & elt : L){
    left.push_back(elt);
  }

  for (const int & elt : R){
    right.push_back(elt);
  }

  for (const int & elt : elements){
    expectedList.push_back(elt);
  }

  auto result = left.merge(right);
  EXPECT_EQ(result, expectedList);
  EXPECT_EQ(result.size(), 6);
}

TEST(ListTest, InsertionSortTest){
  const int numbers[] = {2,4,1,19,20,11};
  const int elements[] = {1,2,4,11,19,20};
  List<int> list;
  List<int> expectedList;

  for (const int & elt : numbers){
    list.push_back(elt);
  }

  for (const int & elt : elements){
    expectedList.push_back(elt);
  }

  auto result = list.insertionSort();

  EXPECT_EQ(result, expectedList);
  EXPECT_EQ(result.size(), expectedList.size());
}

TEST(ListTest, MergeSortTest){
  const int numbers[] = {2,4,1,19,20,11};
  const int elements[] = {1,2,4,11,19,20};
  List<int> list;
  List<int> expectedList;

  for (const int & elt : numbers){
    list.push_back(elt);
  }

  for (const int & elt : elements){
    expectedList.push_back(elt);
  }

  auto result = list.mergeSort();

  EXPECT_EQ(result, expectedList);
  EXPECT_EQ(result.size(), expectedList.size());
}
