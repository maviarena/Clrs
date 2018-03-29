#include<iostream>

using namespace std;


// Colour class

/* Node class - It provides functionality 
 * for each node. Each node has its own 
 * setter and getter for each property
 */

class Node{
	int data;
	Node* parent;
	Node* left;
	Node* right;
	
	public:
		enum Color{
			RED = 0,
			BLACK
		};
		Color color;
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
		void setColor(Node::Color c);
		Node::Color getColor();
		string getColorAsString();
};

Node::Node(int n)
{
	data = n;
	parent = left = right = NULL;
	color = Node::RED;
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

void Node::setColor(Node::Color c)
{
	color = c;
}

Node::Color Node::getColor()
{
	return color;
}

string Node::getColorAsString()
{
	if(color == Node::RED)
		return "RED";
	else
		return "BLACK";
}

/* RedBlackTree class - It deals with all the 
 * functionality of a Red Black Tree. It 
 * provides you all the insert, delete, fixup 
 * and rotation functionalities.
 * It uses Node class to create a node and
 * its member setter and getter to access 
 * the node.
 */


class RedBlackTree{
	Node* root;
public:
	RedBlackTree();
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

RedBlackTree::RedBlackTree()
{
	root = NULL;
}

void RedBlackTree::setRoot(Node* n)
{
	root = n;
}

Node* RedBlackTree::getRoot()
{
	return root;
}

Node* RedBlackTree::createNode(int n)
{
	Node* t = new Node(n); 
	return t;
}

Node* RedBlackTree::getSuccessor(Node* z)
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

void RedBlackTree::transplant(Node* u, Node* v)
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

Node* RedBlackTree::find(int val)
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

void RedBlackTree::deleteFixup(Node* x)
{
	while((x != getRoot()) && (x != NULL) && (x->getColor() == Node::BLACK))
	{
		Node* parent = x->getParent();
		Node* w = NULL;
		if(x == parent->getLeftChild())
		{
			w = parent->getRightChild();
			//case1: if sibling of x, w is RED
			//exchange the colour of parent & w
			//after this left rotate parent

			if((w != NULL) && (w->getColor() == Node::RED))
			{
				w->setColor(Node::BLACK);
				parent->setColor(Node::RED);
				leftRotate(parent);
				w = parent->getRightChild();
			}

			//case 2:: if sibling of x, w and both the child of w are black
			//remove the black colour of w and move x one step up
			
			if((w->getLeftChild() != NULL) && (w->getLeftChild()->getColor() == Node::BLACK) && (w->getRightChild() != NULL) && (w->getRightChild()->getColor() == Node::BLACK))
			{
				w->setColor(Node::RED);
				x = x->getParent();
			}
			//Case 3:: if only w's right child is black,
			//exchange the color of w.left & w and right rotate w 
			else
			{
				if((w->getRightChild() != NULL) && (w->getRightChild()->getColor() == Node::BLACK))
				{
					(w->getLeftChild())->setColor(Node::BLACK);
					w->setColor(Node::RED);
					rightRotate(w);
					w = (x->getParent())->getRightChild();
				}
				//case 4 :: if color of w's right child is red
				w->setColor((x->getParent())->getColor());
				(x->getParent())->setColor(Node::BLACK);
				if(w->getRightChild() != NULL)
					(w->getRightChild())->setColor(Node::BLACK);
				leftRotate(x->getParent());
				x = getRoot();
			}
			
		}
		else if(x == parent->getRightChild())
		{
			w = parent->getLeftChild();
			//case1: if sibling of x, w is RED
			//exchange the colour of parent & w
			//after this left rotate parent

			if((w != NULL) && (w->getColor() == Node::RED))
			{
				w->setColor(Node::BLACK);
				parent->setColor(Node::RED);
				rightRotate(parent);
				w = parent->getLeftChild();
			}

			//case 2:: if sibling of x, w and both the child of w are black
			//remove the black colour of w and move x one step up
			
			if((w->getLeftChild() != NULL) && (w->getLeftChild()->getColor() == Node::BLACK) && (w->getRightChild() != NULL) && (w->getRightChild()->getColor() == Node::BLACK))
			{
				w->setColor(Node::RED);
				x = x->getParent();
			}
			//Case 3:: if only w's right child is black,
			//exchange the color of w.left & w and right rotate w 
			else
			{
				if((w->getLeftChild() != NULL) && (w->getLeftChild()->getColor() == Node::BLACK))
				{
					(w->getRightChild())->setColor(Node::BLACK);
					w->setColor(Node::RED);
					leftRotate(w);
					w = (x->getParent())->getLeftChild();
				}
				//case 4 :: if color of w's right child is red
				w->setColor((x->getParent())->getColor());
				(x->getParent())->setColor(Node::BLACK);
				if(w->getLeftChild() != NULL)
					(w->getLeftChild())->setColor(Node::BLACK);
				rightRotate(x->getParent());
				x = getRoot();
			}
		}
		x->setColor(Node::BLACK);
	}	
}

void RedBlackTree::deleteNode(int val)
{
	Node* z = find(val);
	Node* y = z;
	Node* x = NULL;
	if( y == NULL)
	{
		cout<<"Value doesnot exists"<<endl;
		return;
	}
	
	Node::Color yOriginalColor = y->getColor();

	if(z->isLeftChildNull())
	{
		x = z->getRightChild();
		transplant(z,z->getRightChild());
	}
	else if(z->isRightChildNull())
	{
		x = z->getLeftChild();
		transplant(z,z->getLeftChild());
	}
	else
	{
		y = getSuccessor(z);
		yOriginalColor = y->getColor();
		x = y->getRightChild();
		if(y->getParent() == z)
		{
			if(x != NULL)
				x->setParent(y);
		}
		else
		{
			transplant(y,y->getRightChild());
			y->setRightChild(z->getRightChild());
			(y->getRightChild())->setParent(y);
		}
		transplant(z,y);
		y->setLeftChild(z->getLeftChild());
		(y->getLeftChild())->setParent(y);
		y->setColor(z->getColor());
	}

	if(yOriginalColor == Node::BLACK)
		deleteFixup(x);
}


void RedBlackTree::setParentChild(Node* n, Node* temp)
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

void RedBlackTree::leftRotate(Node* n)
{
	Node* temp = n->getRightChild();
	n->setRightChild(temp->getLeftChild());
	if(temp->getLeftChild() != NULL)
		(temp->getLeftChild())->setParent(n);
	temp->setLeftChild(n);
	setParentChild(n,temp);
}

void RedBlackTree::rightRotate(Node* n)
{
	Node* temp = n->getLeftChild();
	n->setLeftChild(temp->getRightChild());
	if(temp->getRightChild() != NULL)
		(temp->getRightChild())->setParent(n);
	temp->setRightChild(n);
	setParentChild(n,temp);
}

void RedBlackTree::printTree(Node* n)
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

void RedBlackTree::insertFixup(Node* n)
{

	Node* t = n;

	while(((t->getParent() != NULL) && (t->getParent())->getColor() == Node::RED))
	{
		cout<<"Value :: "<< n->getVal() <<" & colour is "<< n->getColorAsString()<<endl;
		cout<<"Value  of parent :: "<< (n->getParent())->getVal() <<" & colour is "<< (n->getParent())->getColorAsString()<<endl;
		Node* y = ((t->getParent())->getParent())->getLeftChild(); // Left Uncle
		Node* x = ((t->getParent())->getParent())->getRightChild(); //Right Uncle
		if(y != NULL && t->getParent() == y)
		{
			Node* uncle = x;
			if(uncle != NULL && uncle->getColor() == Node::RED)
			{
				(uncle->getParent())->setColor(Node::RED);
				uncle->setColor(Node::BLACK);
				(t->getParent())->setColor(Node::BLACK);
				t = uncle->getParent();
			}
			else
			{
			       	if(t == (t->getParent())->getRightChild())
				{
					t = t->getParent();
					leftRotate(t);
				}
				(t->getParent())->setColor(Node::BLACK);
				((t->getParent())->getParent())->setColor(Node::RED);
				rightRotate((t->getParent())->getParent());
			}

		}
		else if((x != NULL) && (t->getParent() == x))
		{

			Node* uncle = ((t->getParent())->getParent())->getLeftChild();
			if(uncle != NULL && uncle->getColor() == Node::RED)
			{
				(uncle->getParent())->setColor(Node::RED);
				uncle->setColor(Node::BLACK);
				(t->getParent())->setColor(Node::BLACK);
				t = uncle->getParent();
			}
			else
			{
			
				if(t == (t->getParent())->getLeftChild())
				{
					t = t->getParent();
					rightRotate(t);
				}
				(t->getParent())->setColor(Node::BLACK);
				((t->getParent())->getParent())->setColor(Node::RED);
				leftRotate((t->getParent())->getParent());
			}
		}
	}
	getRoot()->setColor(Node::BLACK);
}

void RedBlackTree::insertNode(int n)
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
	
	RedBlackTree* rbtree = new RedBlackTree();

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
