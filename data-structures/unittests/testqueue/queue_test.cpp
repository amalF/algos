#include <limits.h>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "queue.h"
#include "queue_test.h"


TEST(QueueTest, EmptyQueueTest){
  Queue<int> a1 = Queue<int>();
  EXPECT_EQ(a1.isEmpty(),true);
}

TEST(QueueTest, PushTest){
  Queue<int> a1 = Queue<int>();
  const int a = 10;
  a1.push(a);
  EXPECT_EQ(a1.isEmpty(),false);
  EXPECT_EQ(a1.size(),1);
  EXPECT_EQ(a1.front(),10);
  EXPECT_EQ(a1.back(),10);
}

TEST(QueueTest, PushTest2){
  Queue<int> a1 = Queue<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (const int& i : elements){
    a1.push(i);
  }
  EXPECT_EQ(a1.size(), 10);
  EXPECT_EQ(a1.front(), 1);
  EXPECT_EQ(a1.back(),10);
}

TEST(QueueTest, PopTest){
  Queue<int> a1 = Queue<int>();
  const int elements[] = {1,2,3,4,5,6,7,8,9,10};
  for (const int& i : elements){
    a1.push(i);
  }
  for (int i=0; i<10;i++){
    a1.pop();
  }
  EXPECT_EQ(a1.isEmpty(), true);
}

TEST(QueueTest, EqualTest){
  Queue<int> a1 = Queue<int>();
  for (int i=0;i<4;i++){
    a1.push(i+1);
  }
  Queue<int> a2 = a1; //copy constructor
  EXPECT_EQ(a1==a2, true);
  EXPECT_EQ(a1!=a2, false);
}
