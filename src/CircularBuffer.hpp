#pragma once

#include <cstddef>


template<typename T, std::size_t N>
class Iterator;
template<typename T, std::size_t N>
class CircularBuffer {
	friend class Iterator<T, N>;
private:
	int bufferSize;
	T* tail;
	T* head;
	int counter = 0;
	T arr[N];
public:
	CircularBuffer()
	{
		//typedef Iterator <T> itr;
		bufferSize = N;
		tail = head = arr;
	}
	void push(T value) noexcept // write data to the buffer
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
	T pop() noexcept// read data from the buffer (older element)
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
template<typename T,std::size_t N>
class Iterator
{
private:
	T* begin;
	T* end;
	T* current;
	T* buffer;

public:
	Iterator(CircularBuffer<T, N>& buf) {
		begin = buf.head;
		end = buf.tail;
		current = buf.head;
		buffer = buf.arr;
	}
	~Iterator() = default;
	T& operator*() {
		return *current;
	}
	T& operator++() noexcept {
		if (current != buffer + (N - 1))
			current++;
		else
			current = buffer;
		return *current;
	}
	T& operator--() noexcept {
		if (current != buffer)
			current--;
		else
			current = buffer;
		return *current;
	}
	T& operator +=(int n) {
		current += n;
		return *current;
	}
	T& operator -=(int n) {
		current -= n;
		return *current;
	}
	T Begin() noexcept {
		current = begin;
		return *current;
	}
	T End() noexcept {
		if (end != buffer)
			current = end - 1;
		else
			current = buffer + (N - 1);
		return *current;
	}
	T* getBegin() noexcept {
		return begin;
	}
	T* getEnd() noexcept {
		return end;
	}
	T* getCurrent() noexcept {
		return current;
	}
};