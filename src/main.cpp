#include "CircularBuffer.hpp"

int main() {
    CircularBuffer<int, 3> test;
    test.put(1);
    test.put(2);
    test.put(3);
    test.printBuffer();
    test.put(4);
    test.printBuffer();
    test.put(5);
    test.printBuffer();
    test.remove();
    test.printBuffer();
    system("pause");
    return 0;
}