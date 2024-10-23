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
    CircularBuffer<char, 4> test2;
    std::cout << "\n";
    test2.put('a');
    test2.put('b');
    test2.put('c');
    test2.put('d');
    test2.printBuffer();
    test2.get();
    test2.printBuffer();
    test2.put('1');
    test2.put('2');
    test2.put('3');
    test2.printBuffer();
    system("pause");
    return 0;
}
