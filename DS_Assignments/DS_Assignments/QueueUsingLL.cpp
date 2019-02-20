#include<iostream>
using namespace std; 
struct node
{
	int data;
	struct node *next;
};
class Queue
{
	struct node *start;
public:
	Queue();
	void enque(int);
	int deque();
	void display();
	~Queue();
};
Queue::Queue()
{
	start = NULL;
}
void Queue::enque(int ele)
{
	struct node *temp, *cur;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		cur = start;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = temp;
	}
}
int Queue::deque()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty\n";
	return x;
}
void Queue::display()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}
Queue::~Queue()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}
int main()
{
	Queue st;
	st.enque(2);
	st.enque(5);
	st.display();
	st.enque(4);
	cout << "Dequed element is" << st.deque() << endl;
	cout << "Dequed element is" << st.deque() << endl;
	st.display();
	return 0;
}