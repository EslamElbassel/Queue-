#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Queue
{
	int tail;
	int head;
	int length;
	int max;
	T* arr;
public:
	Queue()
	{
		max = 10;
		arr = new T [max];
		head = 0;
		tail = max-1;
		length = 0;
	}
	Queue(T value, int intial_size) 
	{
		max = intial_size;
		arr = new T[max];
		head = 0;
		tail = max - 1;
		length = 1;
		arr[0] = value;
	}
	bool isEmpty() 
	{
		return length == 0;
	}
	bool isFull() 
	{ 
		return length == max; 
	}
	void push(T value)
	{
		if (isFull())
			cout << "Queue is full can't push \n";
		else {
			tail = (tail + 1) % max;
			arr[tail] = value;
			length++;
		}
	}
	void pop() 
	{
		if (isEmpty())
			cout << "Empty queue can't pop\n";
		else {
			head = (head + 1) % max;
			--length;
		}
	}
	T& front() 
	{
		if (isEmpty())
			cout << "Queue is empty \n";
		else {
			return arr[head];
		}
	}
	void printQueue() 
	{
		if (isEmpty())
			cout << "Queue is empty\n";
		else
		{
			for (int i = head; i != tail ; i=(i+1)%max)
			{
	 			cout << arr[i] << " ";
			}
			cout << arr[tail];
			cout << endl;
		}
	}
	int size() 
	{
		return length;
	}
	~Queue() 
	{
		delete[]arr;
	}
};

