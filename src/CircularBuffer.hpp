#pragma once

#include <cstddef>


template<typename T, std::size_t N>
class Iterator;
template<typename T, std::size_t N>
class CircularBuffer {
	friend class Iterator<T, N>;
private:
    T arr[N];
	const int bufferSize = N;
	T* tail = arr;
	T* head = arr;
	int counter = 0;
public:
	CircularBuffer() = default;
	void push(T value) noexcept // write data to the buffer
	{
		*tail = value;
		if (tail == head && counter != 0)
        {
			if (head != &arr[bufferSize - 1])
            {
				head++;
            }
			else
            {
				head = arr;
            }
		}
		if (tail != &arr[bufferSize - 1])
        {
			tail++;
		}
		else
        {
            tail = arr;
        }
		if (counter < bufferSize)
        {
			counter++;
        }
	}

	void pop() noexcept //Delete data from the buffer (older element)
	{
		if (counter != 0)
        {
            T output = *head;
			if (head == &arr[bufferSize - 1])
            {
				head = arr;
				counter--;
			}
			else
            {
				head++;
				counter--;
			}
            return output;
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
	Iterator(CircularBuffer<T, N>& buf)
    {
		begin = buf.head;
		end = buf.tail;
		current = buf.head;
		buffer = buf.arr;
	}
	~Iterator() = default;
	T& operator*()
    {
		return *current;
	}
	T& operator++() noexcept
    {
		if (current != buffer + (N - 1))
        {
			current++;
        }
		else
        {
			current = buffer;
        }
		return *current;
	}
    T& operator++(int) noexcept
    {
        if (current != buffer + (N - 1))
        {
            current++;
        }
        else
        {
            current = buffer;
        }
        return *current;
    }
	T& operator--() noexcept
    {
		if (current != buffer)
        {
			current--;
        }
		else
        {
			current = buffer;
        }
		return *current;
	}
    T& operator--(int) noexcept
    {
        if (current != buffer)
        {
            current--;
        }
        else
        {
            current = buffer;
        }
        return *current;
    }
	T Begin() noexcept
    {
		current = begin;
		return *current;
	}
	T End() noexcept
    {
		if (end != buffer)
        {
			current = end - 1;
        }
		else
        {
			current = buffer + (N - 1);
        }
		return *current;
	}
	T* getBegin() noexcept
    {
		return begin;
	}
	T* getEnd() noexcept
    {
		return end;
	}
	T* getCurrent() noexcept
    {
		return current;
	}
};