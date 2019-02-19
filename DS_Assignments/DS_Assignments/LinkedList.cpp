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
	void insertLast(int);
	void insertAfter(int,int);
	void insertBefore(int, int);
	int deleteFirst();
	int deleteLast();
	void deleteSpec(int);
	void travelForward();
	void travelBackward();
	void reverse();
	~List();
	friend void print(struct node*);
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
	start=temp;
}
void List::insertLast(int ele)
{
	struct node *temp,*cur;
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
void List::insertAfter(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *cur;
		cur = start;
		while (cur != NULL && cur->data != sele)
			cur = cur->next;
		if (cur != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = cur->next;
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
		if (start->data == sele)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *cur;
			cur = start;
			while ((cur->next != NULL) && (cur->next->data != sele))
				cur = cur->next;
			if (cur->next != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = ele;
				temp->next = cur->next;
				cur->next = temp;
			}
			else
				cout << "Element not found\n";
		}
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
		start = start->next;
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
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			struct node *cur;
			cur = start;
			while (cur->next->next != NULL)
				cur = cur->next;
			x = cur->next->data;
			delete cur->next;
			cur->next = NULL;
		}
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
				delete temp;
			}
			else
				cout << "Element not found\n";
		}
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
		cout << cur->data<<endl;
		cur = cur->next;
	}
}
void List::travelBackward()
{
	if (start != NULL)
		print(start);
	else
		cout << "List is empty\n";
}
void print(struct node *cur)
{
	if (cur != NULL)
	{
		print(cur->next);
		cout << cur->data<<endl;
	}
}
void List::reverse()
{
	struct node *temp,*rev = NULL;
	if (start != NULL)
	{
		if (start->next != NULL)
		{
			while (start != NULL)
			{
				temp = start;
				start = temp->next;
				temp->next = rev;
				rev = temp;
			}
			start = rev;
		}
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
	int c,se,e;
	List l;
	while (1)
	{
		cout << "Enter choice\n1.Insert at beginning\n2.Insert at the end\n3.Insert after an element\n4.Insert before an element\n5.Delete first element\n6.Delete last element\n7.Delete specific element\n8.Traversel forward\n9.Traversel backward\n10.Reverse the linked list\n11.Exit\n";
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
			l.insertAfter(se,e);
			break;
		case 4:
			cout << "Enter element to insert\n";
			cin >> e;
			cout << "Enter search element\n";
			cin >> se;
			l.insertBefore(se,e);
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
		case 10:
			cout << "Reversed list is\n";
			l.reverse();
			break;
		}
		if (c == 11)
			break;
	}
	return 0;
}