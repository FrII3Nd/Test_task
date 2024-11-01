#include "CircularBuffer.hpp"
#include <iostream>

int main() {
    CircularBuffer<int, 5> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    Iterator<int, 5> it(test);
    std::cout <<*it << " ";
    std::cout << it++ << " ";
    std::cout << it++ << " ";
    std::cout << ++it << " ";
    std::cout << ++it << "\n";
    system("pause");
    return 0;
}
