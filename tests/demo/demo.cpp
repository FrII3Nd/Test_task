#include "CircularBuffer.hpp"
#include <iostream>

int main() {
    CircularBuffer<int, 4> test;
    test.put(1);
    test.put(2);
    test.put(3);
    std::cout << test.get() << "\n";
    std::cout << test.size() << "\n";
    std::cout << test.max_size() << "\n";
    system("pause");
    return 0;
}
