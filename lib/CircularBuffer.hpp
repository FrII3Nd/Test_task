#pragma once
#include <iostream>

class Iterator;
template<typename T, std::size_t N>
class CircularBuffer {
private:
    T* arr;
    int bufferSize;
    T* tail;
    T* head;
    int counter = 0;

public:
    CircularBuffer()
    {
        bufferSize = N;
        arr = new T[bufferSize];
        tail = head = arr;
    }
    ~CircularBuffer()
    {
        delete[] arr;
    }
    void put(T value)
    {
        *tail = value;
        if (tail == head && counter != 0) {
            if (head != &arr[bufferSize - 1])
                head++;
            else
                head = arr;
        }
        if (tail != &arr[bufferSize - 1]) {
            tail++;
        }
        else {
            tail = arr;
        }
        if (counter < bufferSize)
            counter++;
    }
    T get()
    {
        if (counter != 0) {
            T value_out = *head;
            if (head == &arr[bufferSize - 1]) {
                head = arr;
                counter--;
            }
            else {
                head++;
                counter--;
            }
            return value_out;
        }
        std::cout << "Buffer is empty" << "\n";
        throw 1;
    }
    void remove() {
        if (counter != 0) {
            if (head == &arr[bufferSize - 1]) {
                head = arr;
                counter--;
            }
            else {
                head++;
                counter--;
            }
        }
        else
            std::cout << "Buffer is empty" << "\n"; //throw (todo)
    }

    void printBuffer() {
        T* current = head;
        if (counter == 0) {
            std::cout << "Buffer is empty" << "\n";
            return;
        }
        for (int i = 0; i < counter; i++) {
            std::cout << *current << " ";
            if (current == &arr[bufferSize - 1])
                current = arr;
            else
                current++;
        }
        std::cout << "\n";
    }
};
