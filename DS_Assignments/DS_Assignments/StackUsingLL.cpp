#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class Stack
{
	struct node *start;
public:
	Stack();
	void display();
	void push(int);
	int pop();
	int peek();
	~Stack();
};
Stack::Stack()
{
	start = NULL;
}

void Stack::display()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}
void Stack::push(int ele)
{

	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
int Stack::pop()
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
int Stack::peek()
{
	int x = -1;
	if (start != NULL)
		x = start->data;
	return x;
}
Stack::~Stack()
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
	int c, se, e;
	Stack s;
	s.push(4);
	s.push(6);
	cout<<"Popped element is\n"<<s.pop()<<endl;
	s.push(8);
	cout << "Element on top of stack is\n" << s.peek()<<endl;
	s.push(3);
	s.display();
	return 0;
}