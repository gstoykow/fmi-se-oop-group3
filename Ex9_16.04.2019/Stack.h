#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct node
{
	T value;
	node* prev = nullptr;

	node(T value, node* prev)
	{
		this->value = value;
		this->prev = prev;
	}

	friend ostream& operator<<(ostream& os, const node& n)
	{
		os << n.value;
		return os;
	}
};

template<typename T>
class Stack
{

private:

	node<T>* top = nullptr;

public:

	Stack();
	Stack(const Stack&);
	~Stack();

	void push(T value);
	void pop();

	T peek()const;
	void print()const;

	bool isEmpty()const;

};

template<typename T>
inline Stack<T>::Stack(){}

template<typename T>
inline Stack<T>::Stack(const Stack &)
{
}

template<typename T>
inline Stack<T>::~Stack()
{
	while (!isEmpty())pop();
}

template<typename T>
inline void Stack<T>::push(T value)
{
	if (top == nullptr)
	{
		top = new node<T>(value, nullptr);
	}
	else
	{
		node<T>* newNode = new node<T>(value, top);
		top = newNode;
	}
}

template<typename T>
inline void Stack<T>::pop()
{
	if (top != nullptr)
	{
		node<T>* temp = top->prev;
		delete top;
		top = temp;
	}
	else return;
}

template<typename T>
inline T Stack<T>::peek() const
{
	if (!isEmpty())
		return top->value;
}

template<typename T>
inline void Stack<T>::print() const
{
	if (isEmpty())return;
	else{
		node<T>* temp = top;
		while (temp)
		{
			cout << *temp->value << endl;
			temp = temp->prev;
		}
	}
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	if (top == nullptr) return true;
	else return false;
}
