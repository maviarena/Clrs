#include<iostream>

using namespace std;


class Node{
	public:
		int data;
		Node* parent;
		Node* left;
		Node* right;
		Node(int v);
		void setParent(Node* n);
		void setleft(Node* n);
		void setright(Node* n);
};

Node::Node(int v)
{
	data = v;
	parent = left = right = NULL;
}

void Node::setParent(Node* n)
{
	if(n != NULL)
		parent = n;
}

void Node::setleft(Node* n)
{
	if(n != NULL)
		left = n;
}

void Node::setright(Node* n)
{
	if(n != NULL)
		right = n;
}

class BinarySearchTree{
	public:
		Node* root;
		BinarySearchTree();
		void setRoot(Node* n);
		Node* getRoot();
		Node* createNode(int v);
		void addNode(int v);
		Node* Maximum();
		Node* Minimum();
};

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

void BinarySearchTree::setRoot(Node* n)
{
	if (n != NULL)
		root = n;
}

Node* BinarySearchTree::getRoot()
{
	return root;
}

Node* BinarySearchTree::createNode(int v)
{
	Node * n = new Node(v);
	return n;
}

void BinarySearchTree::addNode(int v)
{
	Node* n = new Node(v);
	if(getRoot() == NULL)
	{
		if(n != NULL)
			setRoot(n);
		return;
	}
	else
	{
		Node* current = getRoot();
		while(current != NULL)
		{
			if(n->data <= current->data)
			{
				if(current->left == NULL){
					n->parent = current;
					current->left = n;
					cout<<n->data<<" was added to left of "<<current->data<<endl;
					break;
				}
				else
					current = current->left;
			}
			else
			{
				
				if(current->right == NULL){
					n->parent = current;
					current->right = n;
					cout<<n->data<<" was added to right of "<<current->data<<endl;
					break;
				}
				else
					current = current->right;
				
			}
		}
		current = n;
	}
}

Node* BinarySearchTree::Maximum()
{
	Node* current = getRoot();
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current;
}

Node* BinarySearchTree::Minimum()
{
	Node* current = getRoot();
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

int main()
{
	int arr[] = {15, 18, 6, 7, 3, 17, 20, 2, 4, 13, 9};

	BinarySearchTree t;
	for(int i = 0; i<11; i++)
		t.addNode(arr[i]);

	Node* n = t.Maximum();
	cout<<"Max :: "<<n->data<<endl;
	n = t.Minimum();
	cout<<"Min :: "<<n->data<<endl;

	return 0;
}
