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
		Node* Maximum(Node* n);
		Node* Minimum(Node* n);
		Node* Successor(Node* x);
		Node* Predecessor(Node* x);
		Node* find(int v);
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

Node* BinarySearchTree::Maximum(Node* n)
{
	Node* current = n;
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current;
}

Node* BinarySearchTree::Minimum(Node* n)
{
	Node* current = n;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}


Node* BinarySearchTree::Successor(Node* n)
{
	if(n->right != NULL)
		return Minimum(n->right);
	else
	{
		Node* y = n->parent;
		while(y != NULL && n == y->right)
		{
			n = y;
			y = y->parent;
		}
		return y;
	}
}

Node* BinarySearchTree::Predecessor(Node* n)
{
	if(n->left != NULL)
		return Maximum(n->left);
	else
	{
		Node* p = n->parent;
		while(p != NULL and n == p->left)
		{
			n = p;
			p = p->parent;
		}
		return p;
	}
}

Node* BinarySearchTree::find(int v)
{
	Node* current = getRoot();
	
	while(current != NULL)
	{
		if( v == current->data)
			return current;
		else if( v < current->data)
			current = current->left;
		else
			current = current->right;
	}
	return NULL;
}


int main()
{
	int arr[] = {15, 18, 6, 7, 3, 17, 20, 2, 4, 13, 9};

	BinarySearchTree t;
	for(int i = 0; i<11; i++)
		t.addNode(arr[i]);

	Node* n = t.Maximum(t.find(15));
	cout<<"Max :: "<<n->data<<endl;
	n = t.Minimum(t.find(15));
	cout<<"Min :: "<<n->data<<endl;

	int val = 7;
	n = t.find(val);
	cout<<"Predessor of "<<val<<" : "<<(t.Predecessor(n))->data<<endl;;
	cout<<"Successor of "<<val<<" : "<<(t.Successor(n))->data<<endl;;

	return 0;
}
