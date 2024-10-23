#pragma once

#include <iostream>

template<typename T, std::size_t N>
class CircularBuffer {
private:
	T* arr;
	int bufferSize;
	T* tail;
	T* head;
	int counter = 0;

public:
	CircularBuffer() noexcept
	{
		bufferSize = N;
		arr = new T[bufferSize];
		tail = head = arr;
	}
	~CircularBuffer() noexcept
	{
		delete[] arr;
	}
	void put(T value) noexcept // write data to the buffer
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
		else
			tail = arr;
		if (counter < bufferSize)
			counter++;
	}
	T get() // read data from the buffer (older element)
	{
		if (counter != 0) {
			if (head == &arr[bufferSize - 1]) {
				head = arr;
				counter--;
				return arr[bufferSize - 1];
			}
			else {
				head++;
				counter--;
				return *(head - 1);
			}

		}
		else
			throw "Buffer is empty";
	}
	void remove() noexcept //Delete data from the buffer (older element)
	{
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
			std::cout << "Buffer is empty" << "\n";
	}
	int size() noexcept // return the number of buffer elements
	{
		return counter;
	}
	void printBuffer() noexcept // outputs the entire buffer to console
	{
		T* current = head;
		if (counter == 0) {
			std::cout << "Bufer is empty" << "\n";
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
