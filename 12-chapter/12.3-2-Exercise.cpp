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
		Node* addNodeRecursive(int v, Node* n);
		Node* Maximum(Node* n);
		Node* Minimum(Node* n);
		Node* Successor(Node* x);
		Node* Predecessor(Node* x);
		Node* find(int v);
		void inOrderTraversal();
		void treeDelete(Node* n);
		void treeTransplant(Node* newn, Node* oldn);
};

void BinarySearchTree::treeTransplant(Node* oldn, Node* newn)
{
	cout<<"In tree transplant"<<endl;
	if(oldn->parent == NULL)
		setRoot(newn);
	else if((oldn->parent)->left == oldn)
	{
		(oldn->parent)->left = newn;
		if(newn != NULL)
		{	
		cout<<"Replacing "<<oldn->data<<" with "<<newn->data<<endl;
		cout<<newn->data<<" will be attaced to left of "<<(oldn->parent)->data<<endl;
		}
		else
		{
		cout<<"Replacing "<<oldn->data<<" with NULL"<<endl;
		cout<<"NULL will be attaced to left of "<<(oldn->parent)->data<<endl;
		}
	}
	else
	{
		(oldn->parent)->right = newn;
		if(newn != NULL)
		{	
		cout<<"Replacing "<<oldn->data<<" with "<<newn->data<<endl;
		cout<<newn->data<<" will be attaced to right of "<<(oldn->parent)->data<<endl;
		}
		else
		{
		cout<<"Replacing "<<oldn->data<<" with NULL"<<endl;
		cout<<"NULL will be attaced to right of "<<(oldn->parent)->data<<endl;
		}
	}
	if(newn != NULL)
		newn->parent = oldn->parent;
}
void BinarySearchTree::treeDelete(Node* n)
{
	if(n->left == NULL)
	{
		treeTransplant(n, n->right);
	}
	else if(n->right == NULL)
		treeTransplant(n, n->left);
	else
	{
		Node* y = Successor(n);
		cout<<"Sucessor of "<<n->data<<" is "<<y->data<<endl;
		n->data = y->data;
		treeTransplant(y, y->right);
	}
}

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

Node* BinarySearchTree::addNodeRecursive(int v, Node* n)
{
	if(n == NULL)
		return createNode(v);
	else if(v <= n->data)
	{
			n->left = addNodeRecursive(v, n->left);
			//(n->left)->parent = n;
			cout<<"Added "<<v<<" to the left of "<<n->data<<endl;
	}
	else if(v > n->data)
	{
			n->right = addNodeRecursive(v, n->right);
			//(n->right)->parent = n;
			cout<<"Added "<<v<<" to the right of "<<n->data<<endl;
	}
	return n;
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
	Node* n = Minimum(getRoot());
	
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
	//t.setRoot(t.createNode(arr[0]));
	for(int i = 0; i<11; i++)
		t.addNode(arr[i]);
/*
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

//	t.inOrderTraversal();*/
	t.treeDelete(t.find(15));
	t.inOrderTraversal();
	return 0;
}
