#include<iostream>

using namespace std;

class Stack{
	int * stack;
	int size;
	int top;
public:
	Stack();
	Stack(int num);
	~Stack();
	void push(int num);
	int pop();
	void printStack();
};

Stack::Stack()
{
	stack = new int[10];
	size = 9;
	top = -1;
}

Stack::Stack(int num)
{
	stack = new int[num];
	size = num - 1;
	top = -1;
}

Stack::~Stack()
{
	delete [] stack;
}

void Stack::push(int num)
{
	if(top == size)
	{
		cout<<"Stack OverFlow"<<endl;
		return;
	}
	stack[++top] = num;
	cout<<"Pushed ::"<<num<<endl;
	printStack();
}

int Stack::pop()
{
	if(top < 0)
	{
		cout<<" Stack UnderFlow"<<endl;
		return -1;
	}
	int x = stack[top];
	top--;
	cout<<"Poped :: "<<x<<endl;
	printStack();
	return x;
}

void Stack::printStack()
{
	for(int i=0; i<=top; i++)
	{
		cout<<stack[i]<<",";
	}
	cout<<endl;
}

int main()
{
	Stack s(6);
	s.push(4);
	s.push(1);
	s.push(3);
	s.pop();
	s.push(8);
	s.pop();
	return 0;
}

