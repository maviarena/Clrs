#include<iostream>
using namespace std;

class Node{
     public:
	Node(int value);
	Node* parent;
	Node* left;
	Node* right;
	int data;
};

Node::Node(int value)
{
	parent = NULL;
	data = value;
	left = NULL;
	right = NULL;
}

class Tree{
	public:
	Node* root;
	Tree(){ root = NULL;}
	Node* getRoot(){ return root;}
	Node* setRoot(Node* r){ root = r;}
	Node* createNode(int value){ Node* n = new Node(value); return n;}
	void addNode(int value);
};


void Tree::addNode(int value)
{
	cout<<"Value :: "<<value<<endl;
	Node* n = createNode(value);
	if(getRoot() == NULL)
	{
		setRoot(n);
		n->parent = NULL;
		return;
	}
	else
	{
		Node* r = getRoot();
		cout<<"r->data ::"<<r->data<<endl;
		while(r != NULL)
		{

		cout<<"r->data ::"<<r->data<<endl;
			if(value <= r->data)
			{	
				if(r->left != NULL)
					r = r->left;
				else{
					r->left = n;
					n->parent = r;
					cout<<"Node "<<value<<" added to left of :: "<<r->data<<endl;
					return;
				}
			}
			else
			{ 
				if(r->right != NULL)
					r = r->right;
				else
				{
					r->right = n;
					n->parent = r;
					cout<<"Node "<<value<<" added to right of :: "<<r->data<<endl;
					return;
				}
			}
		}
	}
}

int main()
{
	int arr[] = {1, 4, 5, 10, 16, 17, 21};

	int root = arr[3];
	Tree t;
	t.addNode(root);
	for(int i = 0; i < 7; i++)
	{
		if(arr[i] != root)
			t.addNode(arr[i]);
	}
	return 0;
}
