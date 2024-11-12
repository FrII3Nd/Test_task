#include "CppUTest/TestHarness.h"
#include "CircularBuffer.hpp"
#include "CppUTest/CommandLineTestRunner.h"

    TEST_GROUP(RingBufferTest)
    {
        void setup()
        {}
        void teardown()
        {}
    };
    TEST(RingBufferTest, Push_Pop) {
    CircularBuffer<int, 3> test;
        CHECK_EQUAL(test.max_size(), 3);
        CHECK_EQUAL(test.size(), 0);
        test.push(1);
        CHECK_EQUAL(test.size(), 1);
        test.push(2);
        CHECK_EQUAL(test.size(), 2);
        test.push(3);
        CHECK_EQUAL(test.size(), 3);
        test.pop();
        CHECK_EQUAL(test.size(), 2);
        test.pop();
        CHECK_EQUAL(test.size(), 1);
        test.pop();
        CHECK_EQUAL(test.size(), 0);
    }
    TEST(RingBufferTest, Overflow) {
        CircularBuffer<int, 3> test;
        test.push(1);
        test.push(2);
        test.push(3);
        CHECK_EQUAL(test.size(), 3);
        test.push(4);
        CHECK_EQUAL(test.size(), 3);
        CHECK_EQUAL(test.pop(), 2);
        test.push(5);
        CHECK_EQUAL(test.pop(), 3);
    }
    TEST(RingBufferTest, Float) {
        CircularBuffer<float, 3> test;
        test.push(3.1f);
        test.push(2.2f);
        test.push(1.3f);
        CHECK_EQUAL(test.pop(), 3.1f);
        CHECK_EQUAL(test.pop(), 2.2f);
        CHECK_EQUAL(test.pop(), 1.3f);
    }
    TEST(RingBufferTest, Char) {
        CircularBuffer<char, 3> test;
        test.push('a');
        test.push('b');
        test.push('c');
        CHECK_EQUAL(test.pop(), 'a');
        CHECK_EQUAL(test.pop(), 'b');
        CHECK_EQUAL(test.pop(), 'c');
    }
    TEST(RingBufferTest, Bool) {
        CircularBuffer<bool, 3> test;
        test.push(0);
        test.push(0);
        test.push(1);
        CHECK_EQUAL(test.pop(), 0);
        CHECK_EQUAL(test.pop(), 0);
        CHECK_EQUAL(test.pop(), 1);
    }
    TEST(RingBufferTest, Iterator_incr_decr) {
        CircularBuffer<int, 5> test;
        test.push(1);
        test.push(2);
        test.push(3);
        test.push(4);
        test.push(5);
        auto it = test.begin();
        CHECK_EQUAL(*it, 1);
        CHECK_EQUAL(++it, 2);
        CHECK_EQUAL(it++, 3);
        CHECK_EQUAL(++it, 4);
        CHECK_EQUAL(it--, 3);
        CHECK_EQUAL(--it, 2);
        CHECK_EQUAL(--it, 1);
    }
    TEST(RingBufferTest, Iterator_compare) {
        CircularBuffer<int, 3> test;
        test.push(1);
        test.push(2);
        test.push(3);
        auto it = test.begin();
        auto it2 = test.end();
        CHECK_FALSE(it == it2);
        CHECK_TRUE(it != it2);
        it++;
        CHECK_FALSE(it == it2);
        it++;
        CHECK_TRUE(it == it2);
        CHECK_FALSE(it != it2);
    }
    TEST(RingBufferTest, Iterator_ring) {
        CircularBuffer<int, 3> test;
        test.push(1);
        test.push(2);
        test.push(3);
        test.push(4);
        auto it = test.begin();
        CHECK_EQUAL(*it, 2);
        CHECK_EQUAL(++it, 3);
        CHECK_EQUAL(it++, 4);
        it = test.end();
        CHECK_EQUAL(*it, 4);
        CHECK_EQUAL(--it, 3);
        CHECK_EQUAL(it--, 2);
    }

int main(int ac, char** av) {
    return CommandLineTestRunner::RunAllTests(ac, av);
}