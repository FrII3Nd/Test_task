#include <gtest/gtest.h>
#include "CircularBuffer.hpp"

// Demonstrate some basic assertions.
TEST(RingBufferTest, Put_GET_int) {
	CircularBuffer<int, 3> test;
	test.put(1);
	test.put(2);
	test.put(3);
	EXPECT_EQ(test.get(), 1);
	EXPECT_EQ(test.size(), 2);
	}
TEST(RingBufferTest, Overflow) {
	CircularBuffer<int, 3> test;
	test.put(1);
	test.put(2);
	test.put(3);
	EXPECT_EQ(test.size(), 3);
	test.put(4);
	EXPECT_EQ(test.get(), 2);
	EXPECT_EQ(test.size(), 2);
}
TEST(RingBufferTest, Remove) {
	CircularBuffer<int, 3> test;
	test.put(1);
	test.put(2);
	test.put(3);
	EXPECT_EQ(test.size(), 3);
	test.remove();
	EXPECT_EQ(test.get(), 2);
	EXPECT_EQ(test.size(), 1);
	test.remove();
	test.remove();
	EXPECT_EQ(test.size(), 0);
}
TEST(RingBufferTest, Complex_Char) {
	CircularBuffer<char, 5> test;
	test.put('h');
	test.put('e');
	test.put('l');
	test.put('l');
	test.put('o');
	EXPECT_EQ(test.size(), 5);
	EXPECT_EQ(test.get(), 'h');
	test.remove();
	EXPECT_EQ(test.get(), 'l');
	EXPECT_EQ(test.size(), 2);
	test.put('a');
	test.put('b');
	test.put('c');
	test.put('d');
	EXPECT_EQ(test.get(), 'o');
	EXPECT_EQ(test.size(), 4);
}