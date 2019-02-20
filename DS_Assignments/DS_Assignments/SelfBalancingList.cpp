#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class List
{
	struct node *start;
public:
	List();
	void insertFirst(int);
	void adjust(int);
	void travelForward();
	~List();
};
List::List()
{
	start = NULL;
}
void List::insertFirst(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void List::adjust(int ele)
{
	struct node *temp, *cur;
	if (start != NULL)
	{
		if (start->data == ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			cur = start;
			while ((cur->next != NULL) && (cur->next->data != ele))
				cur = cur->next;
			if (cur->next != NULL)
			{
				temp = cur->next;
				cur->next = temp->next;
			}
			else
				cout << "Element not found\n";
		}
		temp->next = start;
		start = temp;
	}
	else
		cout << "List is empty\n";
}
void List::travelForward()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}
List::~List()
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
	List l; 
	while (1)
	{
		cout << "Enter choice\n1.Insert at beginning\n2.Self Adjust\n3.Traversel forward\n4.Exit\n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter element to insert\n";
			cin >> e;
			l.insertFirst(e);
			break;
		case 2:
			cout << "Enter search element\n";
			cin >> se;
			l.adjust(se);
			break;
		case 3:
			cout << "Forward list is\n";
			l.travelForward();
			break;
		}
		if (c == 4)
			break;
	}
	return 0;
}