#include <limits.h>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "stack.h"
#include "stack_test.h"


TEST(StackTest, EmptyStackTest){
  Stack<int> a1 = Stack<int>();
  EXPECT_EQ(a1.isEmpty(),true);
}

TEST(StackTest, PushTest){
  Stack<int> a1 = Stack<int>();
  const int a = 10;
  a1.push(a);
  EXPECT_EQ(a1.isEmpty(),false);
  EXPECT_EQ(a1.size(),1);
  EXPECT_EQ(a1.top(),10);
}

TEST(StackTest, PushTest2){
  Stack<int> a1 = Stack<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (const int& i : elements){
    a1.push(i);
  }
  EXPECT_EQ(a1.size(), 10);
  EXPECT_EQ(a1.top(), 10);
}

TEST(StackTest, PopTest){
  Stack<int> a1 = Stack<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (const int& i : elements){
    a1.push(i);
  }
  for (int i=0; i<10;i++){
    a1.pop();
  }
  EXPECT_EQ(a1.isEmpty(), true);
}

TEST(StackTest, EqualTest){
  Stack<int> a1 = Stack<int>();
  const int elements[] = {1,2,3,4};
  for (const int& i : elements){
    a1.push(i);
  }
  Stack<int> a2 = a1; //copy constructor
  EXPECT_EQ(a1==a2, true);
  EXPECT_EQ(a1!=a2, false);
}
