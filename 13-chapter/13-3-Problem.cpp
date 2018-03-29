#include<iostream>

using namespace std;


// Colour class

/* Node class - It provides functionality 
 * for each node. Each node has its own 
 * setter and getter for each property
 */

class Node{
	int data;
	int height;
	Node* parent;
	Node* left;
	Node* right;
	
	public:
		Node(int n);
		void setParent(Node* n);
		Node* getParent();
		void setLeftChild(Node* n);
		Node* getLeftChild();
		bool isLeftChildNull();
		void setRightChild(Node* n);
		Node* getRightChild();
		bool isRightChildNull();
		int getVal();
		void setVal(int val);
		int getHeight();
		void setHeight(int val);
};

Node::Node(int n)
{
	data = n;
	parent = left = right = NULL;
	height = 1;
}

void Node::setParent(Node* n)
{
	parent = n;
}

Node* Node::getParent()
{
	return parent;
}

void Node::setLeftChild(Node* n)
{
	left = n;
}

Node* Node::getLeftChild()
{
	return left;
}

bool Node::isLeftChildNull()
{
	return(left == NULL);
}

void Node::setRightChild(Node* n)
{
	right = n;
}

Node* Node::getRightChild()
{
	return right;
}

bool Node::isRightChildNull()
{
	return(right == NULL);
}

int Node::getVal()
{
	return data;
}

void Node::setVal(int val)
{
	data = val;
}

int Node::getHeight()
{
	return height;
}

void Node::setHeight(int val)
{
	height = val;
}

/* AVLTree class - It deals with all the 
 * functionality of a AVL Tree. It 
 * provides you all the insert, delete, fixup 
 * and rotation functionalities.
 * It uses Node class to create a node and
 * its member setter and getter to access 
 * the node.
 */


class AVLTree{
	Node* root;
public:
	AVLTree();
	void setRoot(Node* n);
	Node* getRoot();
	Node* createNode(int n);
	void insertNode(int n);
	void insertFixup(Node* n);
	void leftRotate(Node* n);
	void rightRotate(Node* n);
	void printTree(Node* n);
	Node* find(int val);
	void deleteNode(int val);
	void transplant(Node* u, Node* v);
	Node* getSuccessor(Node* z);
	void deleteFixup(Node* x);
	void setParentChild(Node* n, Node* x);
};

AVLTree::AVLTree()
{
	root = NULL;
}

void AVLTree::setRoot(Node* n)
{
	root = n;
}

Node* AVLTree::getRoot()
{
	return root;
}

Node* AVLTree::createNode(int n)
{
	Node* t = new Node(n); 
	return t;
}

Node* AVLTree::getSuccessor(Node* z)
{
	Node* n = z->getRightChild();
	Node* p = NULL;

	while(n != NULL)
	{
		p = n;
		n = n->getLeftChild();
	}
	return p;
}

void AVLTree::transplant(Node* u, Node* v)
{
	if(u->getParent() == NULL)
		setRoot(v);
	else if(u == (u->getParent())->getLeftChild())
		(u->getParent())->setLeftChild(v);
	else
		(u->getParent())->setRightChild(v);
	
	if(v !=NULL)
		v->setParent(u->getParent());
}

Node* AVLTree::find(int val)
{
	Node* n = getRoot();
	
	while(n != NULL)
	{
		if(val == n->getVal())
		       break;
		else if( val < n->getVal())
			n = n->getLeftChild();
		else
			n = n->getRightChild();	
	}
	return n;
}

void AVLTree::deleteFixup(Node* x)
{
}

void AVLTree::deleteNode(int val)
{
}


void AVLTree::setParentChild(Node* n, Node* temp)
{
	if(n->getParent() == NULL)
		setRoot(temp);
	else if((n->getParent())->getLeftChild() == n)
		n->getParent()->setLeftChild(temp);
	else
		n->getParent()->setRightChild(temp);

	temp->setParent(n->getParent());
	n->setParent(temp);
}

void AVLTree::leftRotate(Node* n)
{
	Node* temp = n->getRightChild();
	n->setRightChild(temp->getLeftChild());
	if(temp->getLeftChild() != NULL)
		(temp->getLeftChild())->setParent(n);
	temp->setLeftChild(n);
	setParentChild(n,temp);
}

void AVLTree::rightRotate(Node* n)
{
	Node* temp = n->getLeftChild();
	n->setLeftChild(temp->getRightChild());
	if(temp->getRightChild() != NULL)
		(temp->getRightChild())->setParent(n);
	temp->setRightChild(n);
	setParentChild(n,temp);
}

void AVLTree::printTree(Node* n)
{
	if( n != NULL)
	{
		cout<<"Value ::"<< n->getVal()<<"Colour :: "<<n->getColorAsString()<<endl;
		cout<<"Print left Child"<<endl;
		printTree(n->getLeftChild());
		cout<<"Print right Child"<<endl;
		printTree(n->getRightChild());
	}

}

void AVLTree::insertFixup(Node* n)
{

}

void AVLTree::insertNode(int n)
{
	Node* temp = createNode(n);
	
	if(getRoot() == NULL)
	{
		setRoot(temp);
		getRoot()->setColor(Node::BLACK);
		cout<<"Root is set :: "<< n <<" & colour is "<< getRoot()->getColorAsString()<<endl;
	}
	else
	{
		Node* p = NULL;
		Node* x = getRoot();
		while( x != NULL)
		{
			p = x;
			if( n <= x->getVal())
				x = x->getLeftChild();
			else
				x = x->getRightChild();
		}

		if( n <= p->getVal())
		{
			p->setLeftChild(temp);
			cout<<n<<" is added to left of "<< p->getVal()<<" who has the color "<<p->getColorAsString()<<endl;
		}
		else
		{
			p->setRightChild(temp);
			cout<<n<<" is added to right of "<< p->getVal()<<" who has the color "<<p->getColorAsString()<<endl;
		}
		temp->setParent(p);
		cout<<n<<" whose value is "<< temp->getVal()<<" who has the color "<<temp->getColorAsString()<<endl;
		insertFixup(temp);
	}
}



int main()
{
	//int arr[] = {7, 4, 11, 3, 6, 9, 18, 2, 14, 19, 12, 17, 22, 20};
	//int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int arr[] = {41, 38, 31, 12, 19, 8};
	int arr[] = {41, 38, 31};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	AVLTree* rbtree = new AVLTree();

	for(int i= 0; i < len; i++)
		rbtree->insertNode(arr[i]);
	rbtree->printTree(rbtree->getRoot());
	
	cout<<"calling delete >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
	//rbtree->deleteNode(8);
	//rbtree->deleteNode(12);
	//rbtree->deleteNode(19);
	rbtree->deleteNode(31);
	//rbtree->deleteNode(38);
	//rbtree->deleteNode(41);
	cout<<"After calling delete >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
	rbtree->printTree(rbtree->getRoot());
	
	return 0;
}
