#include<iostream>
using namespace std;
struct node
{
	int coeff;
	int pow;
	struct node *next;
};
class List
{
	struct node *start;
public:
	List();
	void insertLast(int,int);
	void addPoly(List &, List &);
	void travelForward();
	~List();
};
List::List()
{
	start = NULL;
}
void List::insertLast(int ele,int tele)
{
	struct node *temp, *cur;
	temp = new node;
	temp->pow = ele;
	temp->coeff = tele;
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
void List::addPoly(List &l1, List &l2)
{
	struct node *p1 = l1.start;
	struct node *p2 = l2.start;
	while (p1!=NULL && p2!=NULL)
	{
		if (p1->pow > p2->pow)
		{
			insertLast(p1->pow, p1->coeff);
			p1 = p1->next;
		}
		else if (p2->pow > p1->pow)
		{
			insertLast(p2->pow, p2->coeff);
			p2 = p2->next;
		}
		else
		{
			insertLast(p1->pow, ((p1->coeff) + (p2->coeff)));
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1 != NULL)
	{
		insertLast(p1->pow, p1->coeff);
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		insertLast(p2->pow, p2->coeff);
		p2 = p2->next;
	}
}
void List::travelForward()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->coeff<<"x^" << cur->pow << "+";
		cur = cur->next;
	}
	cout << endl;
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
	int c,ch,cho, se, ele,tele;
	List l1,l2,l3;
	while (1)
	{
		cout << "Enter first list choice:\n1.insert\n2.Exit\n";
		cin >> ch;
		if (ch == 1)
		{
			cout << "Enter power and coffecient\n";
			cin >> ele >> tele;
			l1.insertLast(ele, tele);
		}
		else
			break;
	}
	while (1)
	{
		cout << "Enter second list choice:\n1.insert\n2.Exit\n";
		cin >> ch;
		if (ch == 1)
		{
			cout << "Enter power and coffecient\n";
			cin >> ele >> tele;
			l2.insertLast(ele, tele);
		}
		else
			break;
	}
	l1.travelForward();
	l2.travelForward();
	l3.addPoly(l1, l2);
	l3.travelForward();
	/*while (1)
	{
		cout << "Enter choice\n1.Add polynomial\n2.Print list\n3.Exit\n";
		cin >> c;
		switch (c)
		{
		case 1:
			l3.addPoly(l1, l2);
			break;
		case 2:
			cout << "Forward list is\n";
			l3.travelForward();
			break;
		}
		if (c == 3)
			break;
	}*/
	return 0;
}