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
    a1.push(elements[i]);
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
    a1.push(elements[i]);
  }
  const int item_a = 50;
  const int item_b = 0;
  const int item_c = 20;
  //insert at the front
  a1.insertAt(item_b,0);
  //insert in the middle
  a1.insertAt(item_a,5);
  //insert at the end
  a1.insertAt(item_c,12);

  EXPECT_EQ(a1[0],0);
  EXPECT_EQ(a1[5],50);
  EXPECT_EQ(a1[12],20);
  EXPECT_EQ(a1.size(),13);
}

TEST(LinkedListTest, InsertOutOfBoundsTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0;i<10;i++){
    a1.push(elements[i]);
  }
  const int item_a = 50;
  ASSERT_THROW(a1.insertAt(item_a,15), std::out_of_range);
}

TEST(LinkedListTest, InsertOutOfBounds2Test){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0;i<10;i++){
    a1.push(elements[i]);
  }
  const int item_a = 50;
  ASSERT_THROW(a1.insertAt(item_a,-1), std::out_of_range);
}

TEST(LinkedListTest, AppendTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0;i<10;i++){
    a1.push(elements[i]);
  }
  const int item_a = 50;
  const int item_b = 0;

  a1.append(item_a);
  a1.append(item_b);

  EXPECT_EQ(a1[11],0);
  EXPECT_EQ(a1[10],50);
  EXPECT_EQ(a1.size(),12);
}

TEST(LinkedListTest, ContainsTest){
  LinkedList<char> a1 = LinkedList<char>();
  char chars[] = {'a', 'b', 'c','d','e','g','h'};
  for (const char &c : chars){a1.append(c);}
  EXPECT_EQ(a1.contains('a'),true);
  EXPECT_EQ(a1.contains('c'),true);
  EXPECT_EQ(a1.contains('g'),true);
  EXPECT_EQ(a1.contains('v'),false);
}

TEST(LinkedListTest, GetTest){
  LinkedList<std::string> a1 = LinkedList<std::string>();
  std::string strs[] = {"a", "b", "c","d","e","g","h"};
  for (const std::string &s : strs){a1.append(s);}

  EXPECT_EQ(a1[0], "a");
  EXPECT_EQ(a1[3], "d");

  ASSERT_THROW(a1[10],std::out_of_range);
}

TEST(LinkedListTest, RemoveFromEmptyListTest){
  LinkedList<int> a1 = LinkedList<int>();
  ASSERT_THROW(a1.removeAt(0), std::out_of_range);
}


TEST(LinkedListTest, RemoveOutOfBoundTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3};
  for (const int &elt : elements){
    a1.push(elt);
  }
  ASSERT_THROW(a1.removeAt(3), std::out_of_range);
}

TEST(LinkedListTest, RemoveOutOfBoundTest2){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (const int &elt : elements){
    a1.push(elt);
  }
  ASSERT_THROW(a1.removeAt(11), std::out_of_range);
}

TEST(LinkedListTest, RemoveOutOfBoundTest3){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (const int &elt : elements){
    a1.push(elt);
  }

  ASSERT_THROW(a1.removeAt(-1), std::out_of_range);
}

TEST(LinkedListTest, RemoveAtTest){
  LinkedList<std::string> a1 = LinkedList<std::string>();
  std::string strs[] = {"a", "b", "c","d","e","g","h"};
  for (const std::string & s : strs){a1.append(s);}
  ASSERT_NO_THROW(a1.removeAt(2));
  EXPECT_EQ(a1.size(),6);
}


TEST(LinkedListTest, RemovingTest){
  LinkedList<std::string> a1 = LinkedList<std::string>();
  std::string strs[] = {"a", "b", "c","d","e","g","h"};
  for (const std::string & s : strs){a1.append(s);}
  a1.remove("c");
  EXPECT_EQ(a1.size(),6);
}


TEST(LinkedListTest, RemovingWithDuplicatesTest){
  LinkedList<std::string> a1 = LinkedList<std::string>();
  std::string strs[] = {"a", "a", "a","b","b","b","b"};
  for (const std::string & s : strs){a1.append(s);}
  a1.remove("b");
  EXPECT_EQ(a1.size(),3);
  a1.remove("a");
  EXPECT_EQ(a1.isEmpty(), true);
}

TEST(LinkedListTest, AddAndRemoveTest){
  LinkedList<float> a1 = LinkedList<float>();
  const float elements[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};

  for (const float & f : elements){ a1.append(f);}
  for (const float & f : elements){ a1.remove(f);}
  EXPECT_EQ(a1.isEmpty(),true);

  for (const float & f : elements){ a1.push(f);}
  for (int i=0;i<10;i++){a1.removeAt(0);}
  EXPECT_EQ(a1.isEmpty(),true);
}


TEST(LinkedListTest, GetSizeTest){
  LinkedList<int> a1 = LinkedList<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  int l = 0;
  for (const int & elt : elements){
    a1.append(elt);
    l++;
    EXPECT_EQ(a1.size(),l);
  }
}

