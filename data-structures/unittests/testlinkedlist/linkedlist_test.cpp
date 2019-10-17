#include <limits.h>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "linkedlist.h"
#include "linkedlist_test.h"

//using ds::LinkedList;

TEST(LinkedListTest, EmptyListTest){
  LinkedList<int> a1 = LinkedList<int>();
  EXPECT_EQ(a1.isEmpty(),true);
}

TEST(LinkedListTest, AddTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0;i<10;i++){
    a1.push_front(elements[i]);
  }
  for (int i=0;i<10;i++){
    EXPECT_EQ(a1[i],10-i);
  }
  EXPECT_EQ(a1.size(),10);
}

TEST(LinkedListTest, InsertTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0;i<10;i++){
    a1.push_front(elements[i]);
  }
  const int item_a = 50;
  const int item_b = 0;
  const int item_c = 20;
  //insert at the front
  a1.insert_at(item_b,0);
  //insert in the middle
  a1.insert_at(item_a,5);
  //insert at the end
  a1.insert_at(item_c,12);

  EXPECT_EQ(a1[0],0);
  EXPECT_EQ(a1[5],50);
  EXPECT_EQ(a1[12],20);
  EXPECT_EQ(a1.size(),13);
}

TEST(LinkedListTest, InsertOutOfBoundsTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0;i<10;i++){
    a1.push_front(elements[i]);
  }
  const int item_a = 50;
  ASSERT_THROW(a1.insert_at(item_a,15), std::out_of_range);
}

TEST(LinkedListTest, InsertOutOfBounds2Test){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0;i<10;i++){
    a1.push_front(elements[i]);
  }
  const int item_a = 50;
  ASSERT_THROW(a1.insert_at(item_a,-1), std::out_of_range);
}

TEST(LinkedListTest, AppendTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0;i<10;i++){
    a1.push_front(elements[i]);
  }
  const int item_a = 50;
  const int item_b = 0;

  a1.push_back(item_a);
  a1.push_back(item_b);

  EXPECT_EQ(a1[11],0);
  EXPECT_EQ(a1[10],50);
  EXPECT_EQ(a1.size(),12);
}

TEST(LinkedListTest, ContainsTest){
  LinkedList<char> a1 = LinkedList<char>();
  char chars[] = {'a', 'b', 'c','d','e','g','h'};
  for (const char &c : chars){a1.push_back(c);}
  EXPECT_EQ(a1.contains('a'),true);
  EXPECT_EQ(a1.contains('c'),true);
  EXPECT_EQ(a1.contains('g'),true);
  EXPECT_EQ(a1.contains('v'),false);
}

TEST(LinkedListTest, GetTest){
  LinkedList<std::string> a1 = LinkedList<std::string>();
  std::string strs[] = {"a", "b", "c","d","e","g","h"};
  for (const std::string &s : strs){a1.push_back(s);}

  EXPECT_EQ(a1[0], "a");
  EXPECT_EQ(a1[3], "d");

  ASSERT_THROW(a1[10],std::out_of_range);
}

TEST(LinkedListTest, RemoveFromEmptyListTest){
  LinkedList<int> a1 = LinkedList<int>();
  ASSERT_THROW(a1.remove_at(0), std::out_of_range);
}


TEST(LinkedListTest, RemoveOutOfBoundTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3};
  for (const int &elt : elements){
    a1.push_front(elt);
  }
  ASSERT_THROW(a1.remove_at(3), std::out_of_range);
}

TEST(LinkedListTest, RemoveOutOfBoundTest2){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (const int &elt : elements){
    a1.push_front(elt);
  }
  ASSERT_THROW(a1.remove_at(11), std::out_of_range);
}

TEST(LinkedListTest, RemoveOutOfBoundTest3){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (const int &elt : elements){
    a1.push_front(elt);
  }

  ASSERT_THROW(a1.remove_at(-1), std::out_of_range);
}

TEST(LinkedListTest, RemoveAtTest){
  LinkedList<std::string> a1 = LinkedList<std::string>();
  std::string strs[] = {"a", "b", "c","d","e","g","h"};
  for (const std::string & s : strs){a1.push_back(s);}
  ASSERT_NO_THROW(a1.remove_at(2));
  EXPECT_EQ(a1.size(),6);
}


TEST(LinkedListTest, RemovingTest){
  LinkedList<std::string> a1 = LinkedList<std::string>();
  std::string strs[] = {"a", "b", "c","d","e","g","h"};
  for (const std::string & s : strs){a1.push_back(s);}
  a1.remove_all("c");
  EXPECT_EQ(a1.size(),6);
}


TEST(LinkedListTest, RemovingWithDuplicatesTest){
  LinkedList<std::string> a1 = LinkedList<std::string>();
  std::string strs[] = {"a", "a", "a","b","b","b","b"};
  for (const std::string & s : strs){a1.push_back(s);}
  a1.remove_all("b");
  EXPECT_EQ(a1.size(),3);
  a1.remove_all("a");
  EXPECT_EQ(a1.isEmpty(), true);
}

TEST(LinkedListTest, AddAndRemoveTest){
  LinkedList<float> a1 = LinkedList<float>();
  const float elements[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};

  for (const float & f : elements){ a1.push_back(f);}
  for (const float & f : elements){ a1.remove_all(f);}
  EXPECT_EQ(a1.isEmpty(),true);
}

TEST(LinkedListTest, AddAndPopFrontTest){
  LinkedList<float> a1 = LinkedList<float>();
  const float elements[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};

  for (const float & f : elements){ a1.push_front(f);}
  for (int i=0;i<10;i++){a1.pop_front();}
  EXPECT_EQ(a1.isEmpty(),true);
}

TEST(LinkedListTest, GetSizeTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  int l = 0;
  for (const int & elt : elements){
    a1.push_back(elt);
    l++;
    EXPECT_EQ(a1.size(),l);
  }
}

TEST(LinkedListTest, InsertOrderedAtFrontTest){

  const int elements [] = {1,2,3,7,49};

  LinkedList<int> list0;

  for (const int & elt : elements){
    list0.push_back(elt);
  }

  LinkedList<int> list0_correct = list0;
  list0_correct.push_front(-100);

  list0.insertOrdered(-100);
  EXPECT_EQ(list0, list0_correct);
  EXPECT_EQ(list0.size(), list0_correct.size());

}

TEST(LinkedListTest, InsertOrderedAtEndTest){

  const int elements [] = {1,2,3,7,49};
  LinkedList<int> list0;
  for (const int & elt : elements){
    list0.push_back(elt);
  }
  LinkedList<int> list0_correct = list0;
  list0_correct.push_back(100);

  list0.insertOrdered(100);
  EXPECT_EQ(list0, list0_correct);
  EXPECT_EQ(list0.size(), list0_correct.size());
}

TEST(LinkedListTest, InsertOrderedAtMiddleTest){

  const int elements [] = {1,2,3,7,49};
  const int expected [] = {1,2,3,5,7,49};

  LinkedList<int> list0;
  LinkedList<int> list0_correct;

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
  EXPECT_EQ(list0[3],5);
}

TEST(LinkedListTest, InsertOrderedEmptyTest){
  LinkedList<int> l;
  auto expectedList = l;
  const int a = 100;
  expectedList.push_back(a);
  auto result = l;
  result.insertOrdered(a);
  EXPECT_EQ(result, expectedList);
  EXPECT_EQ(result.size(), expectedList.size());
}

TEST(LinkedListTest, IsSortedTest){
  const int elements [] = {1,2,3,7,49};
  LinkedList<int> list0;
  for (const int & elt : elements){
    list0.push_back(elt);
  }

  EXPECT_EQ(list0.isSorted(), true);

  const int a = 10;
  list0.push_back(a);
  EXPECT_EQ(list0.isSorted(), false);
}

TEST(LinkedListTest, SplitHalvesEvenSizeTest){
  const int elements [] = {1,2,3,7,49,5};
  const int L[] = {1,2,3};
  const int R[] = {7,49,5};
  LinkedList<int> list0;
  LinkedList<int> expectedFirstHalf;
  LinkedList<int> expectedSecondHalf;

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

