#include "CircularBuffer.hpp"
#include <iostream>

int main() {
    CircularBuffer<int, 5> demo;
    demo.push(0);
    demo.push(1);
    demo.push(2);
    demo.push(3);
    demo.push(4);
    demo.push(5);
    std::cout<<"\nSize - "<<demo.size()<<"\n";
    auto it1 = demo.begin();
    auto it2 = demo.end();
    std::cout<<"\nBegin-->End: ";
    for (it1; it1 != it2; it1++)
    {
        std::cout<<"\t"<<*it1;
    }
    std::cout<<"\t"<<*it2<<"\n";
    auto it3 = demo.begin();
    auto it4 = demo.end();
    std::cout<<"\nEnd-->Begin: ";
    for (it4; it4 != it3; it4--)
    {
        std::cout<<"\t"<<*it4;
    }
    std::cout<<"\t"<<*it3<<"\n\nPop():       ";
    for(int i = 0; i < 5; i++)
    {
        std::cout<<"\t"<<demo.pop();
    }
    std::cout<<"\n\n";
    std::cout<<"Size - "<<demo.size()<<"\n";
    return 0;
}
