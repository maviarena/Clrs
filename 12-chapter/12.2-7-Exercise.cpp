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
		void inOrderTraversal();
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
	Node* t = NULL;
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
			t = current;
			if(n->data <= current->data)
				current = current->left;
			else
				current = current->right;
		}
	}

	n->parent = t;
	if(n->data <= t->data)
	{
		t->left = n;
		cout<<"Added "<<n->data<<" to the left of "<<t->data<<endl;
	}
	else
	{
		t->right = n;
		cout<<"Added "<<n->data<<" to the right of "<<t->data<<endl;
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

void BinarySearchTree::inOrderTraversal()
{
	Node* n = Minimum(find(15));
	
	while( n != NULL)
	{
		cout<<n->data<<",";
		n = Successor(n);
	}
	cout<<endl;
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

	int val = 20;
	n = t.find(val);
	Node* temp = t.Successor(n);
	if(temp == NULL)
		cout<<"Sucessor doesnot exist"<<endl;
	else
		cout<<"Successor of "<<val<<" : "<<temp->data<<endl;

	t.inOrderTraversal();
	return 0;
}
