#pragma once
#include <iostream>

using namespace std;

struct node
{
	int value;
	node* prev = nullptr;

	node(int value, node* prev)
	{
		this->value = value;
		this->prev = prev;
	}
};

class Stack 
{

private:

	//size logic

	node* top = nullptr;

public:

	void push(int value);

	void pop();

	int peek()const;

	void print()const;
	
	bool isEmpty()const;

	Stack();
	Stack(const Stack& s);

	~Stack();

};
