#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
class List
{
	struct node *start;
public:
	List();
	void insertFirst(int);
	void insertLast(int);
	void insertAfter(int, int);
	void insertBefore(int, int);
	int deleteFirst();
	int deleteLast();
	void deleteSpec(int);
	void travelForward();
	void travelBackward();
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
	temp->prev = NULL;
	temp->next = start;
	if(start!=NULL)
	start->prev = temp;
	start = temp;
}
void List::insertLast(int ele)
{
	struct node *temp, *cur;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		cur = start;
		while (cur->next != NULL)
			cur = cur->next;
		temp->prev = cur;
		cur->next = temp;
	}
}
void List::insertAfter(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *cur,*temp;
		cur = start;
		while (cur != NULL && cur->data != sele)
			cur = cur->next;
		if (cur != NULL)
		{
			temp = new node;
			temp->data = ele;
			temp->prev = cur;
			temp->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = temp;
			cur->next = temp;
		}
		else
			cout << "Element not found\n";
	}
	else
		cout << "List is empty\n";
}
void List::insertBefore(int sele, int ele)
{
	if (start != NULL)
	{
			struct node *cur;
			cur = start;
			while ((cur != NULL) && (cur->data != sele))
				cur = cur->next;
			if (cur != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = ele;
				temp->prev = cur->prev;
				temp->next = cur;
				if (cur->prev != NULL)
					cur->prev->next = temp;
				else
					start = temp;
				cur->prev = temp;
			}
			else
				cout << "Element not found\n";
	}
	else
		cout << "List is empty\n";
}
int List::deleteFirst()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty\n";
	return x;
}
int List::deleteLast()
{
	int x = -1;
	if (start != NULL)
	{
			struct node *cur;
			cur = start;
			while (cur->next != NULL)
				cur = cur->next;
			x = cur->data;
			if (cur->prev != NULL)
				cur->prev->next = NULL;
			else
				start = NULL;
			delete cur;
	}
	else
		cout << "List is empty\n";
	return x;
}
void List::deleteSpec(int ele)
{
	struct node *temp, *cur;
	if (start != NULL)
	{
			cur = start;
			while ((cur != NULL) && (cur->data != ele))
				cur = cur->next;
			if (cur != NULL)
			{
				if (cur->prev != NULL)
					cur->prev->next = cur->next;
				else
					start = cur->next;
				if (cur->next != NULL)
					cur->next->prev = cur->prev;
				delete cur;
			}
			else
				cout << "Element not found\n";
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
void List::travelBackward()
{
	struct node *cur;
	cur = start;
	if (start != NULL)
	{
		while (cur->next != NULL)
			cur = cur->next;
		while (cur != NULL)
		{
			cout << cur->data;
			cur = cur->prev;
		}
	}
	else
		cout << "List is empty\n";
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
		cout << "Enter choice\n1.Insert at beginning\n2.Insert at the end\n3.Insert after an element\n4.Insert before an element\n5.Delete first element\n6.Delete last element\n7.Delete specific element\n8.Traversel forward\n9.Traversel backward\n10.Exit\n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter element to insert\n";
			cin >> e;
			l.insertFirst(e);
			break;
		case 2:
			cout << "Enter element to insert\n";
			cin >> e;
			l.insertLast(e);
			break;
		case 3:
			cout << "Enter element to insert\n";
			cin >> e;
			cout << "Enter search element\n";
			cin >> se;
			l.insertAfter(se, e);
			break;
		case 4:
			cout << "Enter element to insert\n";
			cin >> e;
			cout << "Enter search element\n";
			cin >> se;
			l.insertBefore(se, e);
			break;
		case 5:
			cout << "Deleted element is\n" << l.deleteFirst();
			break;
		case 6:
			cout << "Deleted element is\n" << l.deleteLast();
			break;
		case 7:
			cout << "Enter search element\n";
			cin >> se;
			l.deleteSpec(se);
			break;
		case 8:
			cout << "Forward list is\n";
			l.travelForward();
			break;
		case 9:
			cout << "Backward list is\n";
			l.travelBackward();
			break;
		}
		if (c == 10)
			break;
	}
	return 0;
}