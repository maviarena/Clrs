#include<iostream>
using namespace std;

class Queue{
	int * queue;
	int capacity;
	int size;
	int tail;
	int head;
    public:
	Queue();
	Queue(int n);
	~Queue();
	void enqueue(int num);
	int dequeue();
	void printQueue();
};

Queue::Queue()
{
	size = 0;
	capacity = 10;
	queue = new int[capacity]();
	head = 0;
	tail = capacity - 1;
}

Queue::Queue(int n)
{
	size = 0;
	capacity = n;
	queue = new int[capacity]();
	head = 0;
	tail = capacity-1;
}
Queue::~Queue()
{
	delete [] queue;
}

void Queue::printQueue()
{
	for(int i= 0; i<capacity; i++)
	{
		cout<<queue[i]<<",";
	}
	cout<<endl;
}

void Queue::enqueue(int num)
{
	cout<<"In here"<<endl;
	if(size < capacity)
	{
		++size;
		tail = (tail+1)%capacity;
		queue[tail] = num;
		cout<<"Enqueue :: "<<num<<endl;
		printQueue();
	}
	else
		cout<<"Queue full"<<endl;
}

int Queue::dequeue()
{
	if(size == 0)
		return -1;
	int num = queue[head];
	queue[head] = 0;
	head = (head +1)%capacity;
	--size;
	cout<<"Dequeue ::"<<num<<endl;
	printQueue();
	return num;
}

int main()
{
	Queue queue(6);
	queue.enqueue(4);
	queue.dequeue();
	queue.enqueue(1);
	queue.enqueue(3);
	queue.dequeue();
	queue.enqueue(8);
	queue.dequeue();

	return 0;
}
