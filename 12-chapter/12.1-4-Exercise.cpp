#include<iostream>
#include<stack>

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
	void preOrderTraversal(Node* r);
	void inOrderTraversal(Node* r);
	void postOrderTraversal(Node* r);
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

void Tree::preOrderTraversal(Node* r)
{
	Node* current = r;

	if(current != NULL)
	{
		cout<<current->data<<",";
		preOrderTraversal(current->left);
		preOrderTraversal(current->right);
	}
}

void Tree::postOrderTraversal(Node* r)
{
	Node* current = r;

	if(current != NULL)
	{
		postOrderTraversal(current->left);
		postOrderTraversal(current->right);
		cout<<current->data<<",";
	}

}

void Tree::inOrderTraversal(Node* r)
{
	Node* current = r;

	if(current != NULL)
	{
		inOrderTraversal(current->left);
		cout<<current->data<<",";
		inOrderTraversal(current->right);
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

	t.preOrderTraversal(t.getRoot());
	cout<<endl;
	t.postOrderTraversal(t.getRoot());
	cout<<endl;
	t.inOrderTraversal(t.getRoot());
	cout<<endl;
	return 0;
}
