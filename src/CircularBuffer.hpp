#pragma once

#include <cstddef>

template<typename T, std::size_t N>
class CircularBuffer {
private:
	int bufferSize;
	T* tail;
	T* head;
	int counter = 0;
	T arr[N];
public:
	CircularBuffer() noexcept
	{
		bufferSize = N;
		tail = head = arr;
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
		return *head;
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
	}
	int size() noexcept // return the number of buffer elements
	{
		return counter;
	}
	int max_size() noexcept
	{
		return bufferSize;
	}
};
