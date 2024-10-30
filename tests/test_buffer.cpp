#include <gtest/gtest.h>
#include "CircularBuffer.hpp"

TEST(RingBufferTest, Push_Pop) {
	CircularBuffer<int, 3> test;
	EXPECT_EQ(test.max_size(), 3);
	EXPECT_EQ(test.size(), 0);
	test.push(1);
	test.push(2);
	test.push(3);
	EXPECT_EQ(test.size(), 3);
	EXPECT_EQ(test.pop(), 1);
}
TEST(RingBufferTest, Overflow) {
	CircularBuffer<int, 3> test;
	test.push(1);
	test.push(2);
	test.push(3);
	EXPECT_EQ(test.size(), 3);
	test.push(4);
	EXPECT_EQ(test.size(), 3);
	EXPECT_EQ(test.pop(), 2);
	test.push(5);
	EXPECT_EQ(test.pop(), 3);
}
TEST(RingBufferTest, Remove) {
	CircularBuffer<int, 3> test;
	test.push(1);
	test.push(2);
	test.push(3);
	EXPECT_EQ(test.size(), 3);
	test.remove();
	EXPECT_EQ(test.size(), 2);
	test.remove();
	test.remove();
	EXPECT_EQ(test.size(), 0);
}
TEST(RingBufferTest, Float) {
	CircularBuffer<float, 3> test;
	test.push(3.1f);
	test.push(2.2f);
	test.push(1.3f);
	EXPECT_EQ(test.pop(), 3.1f);
	test.remove();
	EXPECT_EQ(test.pop(), 2.2f);
	test.remove();
	EXPECT_EQ(test.pop(), 1.3f);
}
TEST(RingBufferTest, Char) {
	CircularBuffer<char, 3> test;
	test.push('a');
	test.push('b');
	test.push('c');
	EXPECT_EQ(test.pop(), 'a');
	test.remove();
	EXPECT_EQ(test.pop(), 'b');
	test.remove();
	EXPECT_EQ(test.pop(), 'c');
}
TEST(RingBufferTest, Bool) {
	CircularBuffer<bool, 3> test;
	test.push(0);
	test.push(0);
	test.push(1);
	EXPECT_EQ(test.pop(), 0);
	test.remove();
	EXPECT_EQ(test.pop(), 0);
	test.remove();
	EXPECT_EQ(test.pop(), 1);
}
TEST(RingBufferTest, Iterator) {
	CircularBuffer<int, 5> test;
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);
	Iterator<int, 5> it(test);
	EXPECT_EQ(*it, 1);
	EXPECT_EQ(++it, 2);
	EXPECT_EQ(++it, 3);
	EXPECT_EQ(++it, 4);
	EXPECT_EQ(--it, 3);
	EXPECT_EQ(--it, 2);
	EXPECT_EQ(--it, 1);
	EXPECT_EQ(it.Begin(), 1);
	EXPECT_EQ(it.End(), 5);
}
