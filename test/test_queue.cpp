#include <gtest.h>
#include "priority_queue.h"

TEST(queue_on_dheap, can_create_queue){
	PQueue<int>* a;
	ASSERT_NO_THROW(a = new DQueue<int>(2));
}

TEST(queue_on_dheap, created_queue_is_empty){
	DQueue<int> a(2);
	EXPECT_EQ(1, a.isEmpty());
}

TEST(queue_on_dheap, can_get_size_queue){
	DQueue<int> a(2);
	ASSERT_NO_THROW(a.GetSize());
}

TEST(queue_on_dheap, GetSize_works_properly){
	DQueue<int> a(2);
	EXPECT_EQ(0, a.GetSize());
}

TEST(queue_on_dheap, can_push_key){
	DQueue<int> a(2);
	ASSERT_NO_THROW(a.push(1));
}

TEST(queue_on_dheap, push_increases_size){
	DQueue<int> a(2);
	int tmp = a.GetSize();
	a.push(1);
	EXPECT_EQ(tmp + 1, a.GetSize());
}

TEST(queue_on_dheap, can_pop_elem){
	DQueue<int> a(2);
	a.push(1);
	a.push(2);
	ASSERT_NO_THROW(a.pop());
}

TEST(queue_on_dheap, throws_when_pop_from_empty){
	DQueue<int> a(1);
	ASSERT_ANY_THROW(a.pop());
}

TEST(queue_on_dheap, pop_decreases_size){
	DQueue<int> a(2);
	a.push(1);
	a.push(2);
	int tmp = a.GetSize();
	a.pop();
	EXPECT_EQ(tmp - 1, a.GetSize());
}

TEST(queue_on_dheap, can_get_top_elem){
	DQueue<int> a(2);
	a.push(1);
	a.push(2);
	ASSERT_NO_THROW(a.top());
}

TEST(queue_on_dheap, throws_when_top_from_empty){
	DQueue<int> a(2);
	ASSERT_ANY_THROW(a.top());
}

TEST(queue_on_dheap, top_dont_decrease_size){
	DQueue<int> a(2);
	a.push(1);
	a.push(2);
	int tmp = a.GetSize();
	a.top();
	EXPECT_EQ(tmp, a.GetSize());
}

///////////////////////////////////////////////////////////

TEST(queue_on_bintree, can_create_queue){
	PQueue<int>* a;
	ASSERT_NO_THROW(a = new BQueue<int>());
}

TEST(queue_on_bintree, created_queue_is_empty){
	BQueue<int> a;
	EXPECT_EQ(1, a.isEmpty());
}

TEST(queue_on_bintree, can_get_size_queue){
	BQueue<int> a;
	ASSERT_NO_THROW(a.GetSize());
}

TEST(queue_on_bintree, GetSize_works_properly){
	BQueue<int> a;
	EXPECT_EQ(0, a.GetSize());
}

TEST(queue_on_bintree, can_push_key){
	BQueue<int> a;
	ASSERT_NO_THROW(a.push(1));
}

TEST(queue_on_bintree, push_increases_size){
	BQueue<int> a;
	int tmp = a.GetSize();
	a.push(1);
	EXPECT_EQ(tmp + 1, a.GetSize());
}

TEST(queue_on_bintree, can_get_top_elem){
	BQueue<int> a;
	a.push(1);
	a.push(2);
	ASSERT_NO_THROW(a.top());
}

TEST(queue_on_bintree, top_dont_decrease_size){
	BQueue<int> a;
	a.push(1);
	a.push(2);
	int tmp = a.GetSize();
	a.top();
	EXPECT_EQ(tmp, a.GetSize());
}
