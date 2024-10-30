#include "CircularBuffer.hpp"
#include <iostream>

int main() {
    CircularBuffer<int, 5> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(2);
    test.push(99);
    Iterator<int, 5> it(test);
    std::cout <<*it << "\n";
    std::cout << ++it << "\n";
    std::cout << ++it << "\n";
    std::cout << ++it << "\n";
    std::cout << ++it << "\n\n";
    it.Begin();
    while (true) {
        std::cout << *it << " ";
        ++it;
        if (it.getCurrent() == it.getEnd())
            break;
    }
    std::cout << "\n";
    std::cout << it.End() << "\n";
    system("pause");
    return 0;
}
