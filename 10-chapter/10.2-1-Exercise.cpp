#include<iostream>

using namespace std;

class Node{
    public:
	int data;
	Node* next;
	Node();
	Node(int n);
	~Node();
};

Node::Node()
{
	data = 0;
	next = NULL;
}

Node::Node(int n)
{
	data = n;
	next = NULL;
}

Node::~Node()
{

}

class List{
	Node *head;
   public:
	List();
	~List();
	Node* getHead();
	void ins(int n);
	void del();
	void printlist();
	void reverseList();
};

List::List()
{
	head = NULL;
}

List::~List()
{
}

void List::ins(int n)
{
	Node *node = new Node(n);

	node->next = head;
	head = node;
}
void List::del()
{
	if(head == NULL)
		return;
	
	Node* n = head;
	head = head->next;
	delete n;
}

void List::printlist()
{
	Node* n = head;

	while(n != NULL)
	{
		cout<<n->data<<",";
		n = n->next;
	}
	cout<<endl;
}

void List::reverseList()
{
	Node* n = head->next;
	Node* n2 = head;
	n2->next = NULL;
	while(n != NULL)
	{
		Node* temp = n->next;
		n->next = n2;
		n2 = n;
		n = temp;
	}
	head = n2;
}

int main()
{
	List list;
	list.ins(5);
	list.ins(7);
	list.ins(56);
	list.printlist();
	list.del();
	list.printlist();
	list.ins(23);
	list.ins(19);
	list.printlist();
	list.del();
	list.printlist();
	list.reverseList();
	list.printlist();
	return 0;
}

