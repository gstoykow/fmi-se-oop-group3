#include "Stack.h"

void Stack::push(int value)
{
	if (isEmpty())
	{
		top = new node(value, nullptr);
	}
	else
	{
		node* newNode = new node(value, top);
		top = newNode;
	}
}

void Stack::pop()
{
	if (!isEmpty())
	{
		node* temp = top->prev;
		delete top;
		top = temp;	
	}
}

int Stack::peek() const
{
	if (!isEmpty())
	{ 
		return top->value;
	}
}

void Stack::print() const
{
	if (!isEmpty())
	{
		node* temp = top;
		while (temp != nullptr)
		{
			cout << temp->value << endl;
			temp = temp->prev;
		} 
	}
	else 
	{
		cout << "Stack is empty!";
	}
}

bool Stack::isEmpty() const
{
	if (top == nullptr) return true;
	else return false;
}

Stack::Stack()
{
	//size logic
	top = nullptr;
}

Stack::Stack(const Stack & s)
{
	//will implement
}

Stack::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}
