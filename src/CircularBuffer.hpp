#pragma once

#include <cstddef>

template<typename T, std::size_t N>
class CircularBuffer {
private:
    T arr[N];
	const int bufferSize = N;
	T* tail = arr;
	T* head = arr;
	int counter = 0;
    struct Iterator_conf
    {
        T* cur;
        T* arr_start;
        T* arr_end;
    };
    Iterator_conf it_cnf{head,arr,arr + N - 1};
public:
    class Iterator;
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

	T pop() noexcept //Delete data from the buffer (older element)
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
	int size() noexcept // return the number of buffer elements
	{
		return counter;
	}
	int max_size() noexcept
	{
		return bufferSize;
	}
    Iterator begin() noexcept
    {
        it_cnf.cur = head;
        return it_cnf;
    }
    Iterator end() noexcept
    {
        if (tail != arr)
        {
            it_cnf.cur = tail - 1;
        }
        else
        {
            it_cnf.cur = arr + N - 1;
        }
        return it_cnf;
    }
    class Iterator
    {
    private:
        T* current;
        T* begin;
        T* end;
    public:
        Iterator(Iterator_conf& it) noexcept
        {
            current = it.cur;
            begin = it.arr_start;
            end = it.arr_end;
        }
        ~Iterator() = default;
        T& operator=(T* ptr) noexcept
        {
            current = ptr;
            return current;
        }
        T& operator=(Iterator_conf& it) noexcept
        {
            current = it.cur;
            return current;
        }
        bool operator==(const Iterator& it) noexcept
        {
            return current == it.current;
        }
        bool operator!=(const Iterator& it) noexcept
        {
            return current != it.current;
        }
        T& operator*()
        {
            return *current;
        }
        T& operator++() noexcept
        {
            if (current != end)
            {
                current++;
            }
            else
            {
                current = begin;
            }
            return *current;
        }
        T& operator++(int) noexcept
        {
            if (current != end)
            {
                current++;
            }
            else
            {
                current = begin;
            }
            return *current;
        }
        T& operator--() noexcept
        {
            if (current != begin)
            {
                current--;
            }
            else
            {
                current = end;
            }
            return *current;
        }
        T& operator--(int) noexcept
        {
            if (current != begin)
            {
                current--;
            }
            else
            {
                current = end;
            }
            return *current;
        }
    };
};

