#include <limits.h>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "heap.h"

using namespace ds;

TEST(HeapTest, isEmptyTest){
	Heap<int> q;
        Heap<int> q2 = Heap<int>(10);
	EXPECT_EQ(q.isEmpty(),true);
	EXPECT_EQ(q.size(),0);
        EXPECT_EQ(q2.isEmpty(),true);
        EXPECT_EQ(q2.size(),0);
}

TEST(HeapTest, PushEmptyHeapTest){
	Heap<int> q;
	EXPECT_EQ(q.isEmpty(),true);
	EXPECT_EQ(q.size(),0);
        q.push(4);
        q.push(5);
        q.push(6);
        q.push(15);
        q.push(9); q.push(7);
        q.push(20);
        q.push(16); q.push(25); q.push(14); q.push(12); q.push(11);
        q.push(8); q.push(3);
        EXPECT_EQ(q.top(),3);
        EXPECT_EQ(q.size(),14);
        EXPECT_EQ(q.isEmpty(), false);

}
