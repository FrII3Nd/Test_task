#include <gtest/gtest.h>
#include "CircularBuffer.hpp"

TEST(RingBufferTest, Put_GET) {
	CircularBuffer<int, 3> test;
	test.put(1);
	test.put(2);
	test.put(3);
	EXPECT_EQ(test.size(), 3);
	EXPECT_EQ(test.get(), 1);
	EXPECT_EQ(test.get(), 2);
	EXPECT_EQ(test.get(), 3);
	EXPECT_EQ(test.size(), 0);
	}
TEST(RingBufferTest, Overflow) {
	CircularBuffer<int, 3> test;
	test.put(1);
	test.put(2);
	test.put(3);
	EXPECT_EQ(test.size(), 3);
	test.put(4);
	EXPECT_EQ(test.size(), 3);
	EXPECT_EQ(test.get(), 2);
	test.put(5);
	EXPECT_EQ(test.get(), 3);
	EXPECT_EQ(test.get(), 4);
	EXPECT_EQ(test.get(), 5);
}
TEST(RingBufferTest, Remove) {
	CircularBuffer<int, 3> test;
	test.put(1);
	test.put(2);
	test.put(3);
	EXPECT_EQ(test.size(), 3);
	test.remove();
	EXPECT_EQ(test.size(), 2);
	test.remove();
	test.remove();
	EXPECT_EQ(test.size(), 0);
}
TEST(RingBufferTest, Float) {
	CircularBuffer<float, 3> test;
	test.put(3.1f);
	test.put(2.2f);
	test.put(1.3f);
	EXPECT_EQ(test.get(), 3.1f);
	EXPECT_EQ(test.get(), 2.2f);
	EXPECT_EQ(test.get(), 1.3f);
}
TEST(RingBufferTest, Char) {
	CircularBuffer<char, 3> test;
	test.put('a');
	test.put('b');
	test.put('c');
	EXPECT_EQ(test.get(), 'a');
	EXPECT_EQ(test.get(), 'b');
	EXPECT_EQ(test.get(), 'c');
}
TEST(RingBufferTest, Bool) {
	CircularBuffer<bool, 3> test;
	test.put(0);
	test.put(0);
	test.put(1);
	EXPECT_EQ(test.get(), 0);
	EXPECT_EQ(test.get(), 0);
	EXPECT_EQ(test.get(), 1);
}
TEST(RingBufferTest, Complex) {
	CircularBuffer<int , 5> test;
	test.put(1);
	test.put(2);
	test.put(3);
	test.put(4);
	test.put(5);
	EXPECT_EQ(test.get(), 1);
	EXPECT_EQ(test.get(), 2);
	EXPECT_EQ(test.get(), 3);
	EXPECT_EQ(test.get(), 4);
	EXPECT_EQ(test.get(), 5);
	test.put(1);
	test.put(2);
	test.put(3);
	test.put(4);
	test.put(5);
	test.put(6);
	EXPECT_EQ(test.get(), 2);
	test.remove();
	test.remove();
	test.remove();
	EXPECT_EQ(test.get(), 6);
	test.put(1);
	test.put(2);
	test.put(3);
	test.put(4);
	test.put(5);
	test.put(6);
	test.put(7);
	test.put(8);
	EXPECT_EQ(test.get(), 4);
	EXPECT_EQ(test.get(), 5);
	EXPECT_EQ(test.get(), 6);
	EXPECT_EQ(test.get(), 7);
	EXPECT_EQ(test.get(), 8);
}
