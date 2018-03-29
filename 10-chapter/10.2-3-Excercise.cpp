#include<iostream>

using namespace std;

class Node{
    public:
	int data;
	Node* next;
	Node();
	Node(int num);
	~Node();
};

Node::Node()
{
	data = 0;
	next = NULL;
}
