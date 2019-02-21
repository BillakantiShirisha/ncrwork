#include<iostream>
using namespace std;
class Queue
{
	int f;
	int r;
	int *s;
	int size;
public:
	Queue();
	void pushBack(int);
	void pushFront(int);
	int deleteFront();
	int deleteBack();
	bool underflow();
	bool back_overflow();
	bool front_overflow();
	void display();
	void getSize(int);
	~Queue();
};
Queue::Queue()
{
	f = -1;
	r = -1;
	s = NULL;
	size = 0;
}
void Queue::getSize(int n)
{
	size = n;
	s = new int[n];
}
bool Queue::back_overflow()
{
	return (r == (size - 1));
}
bool Queue::front_overflow()
{
	return (f == 0);
}
bool Queue::underflow()
{
	return (r == f && f == -1);
}
void Queue::pushBack(int ele)
{
	if (!back_overflow())
	{
		if (r == f && f == -1)
			f++;
		s[++r] = ele;
	}
	else
		cout << "Queue is full" << endl;
}
void Queue::pushFront(int ele)
{
	if (!front_overflow())
	{
		if (r == f && f == -1)
		{
			f++;
			r++;
			s[f] = ele;
		}
		else
		s[--f] = ele;
	}
	else
		cout << "Queue is full" << endl;
}
int Queue::deleteFront()
{
	int x = -999;
	if (!underflow())
	{
		if (f == r)
		{
			x = s[f];
			r = f = -1;
		}
		else
			x = s[f++];
	}
	else
		cout << "Queue is empty" << endl;
	return x;
}
int Queue::deleteBack()
{
	int x = -999;
	if (!underflow())
	{
		if (f == r)
		{
			x = s[f];
			r = f = -1;
		}
		else
			x = s[r--];
	}
	else
		cout << "Queue is empty" << endl;
	return x;
}
void Queue::display()
{
	for (int i = f; i <= r; i++)
		cout << s[i] << endl;
}
Queue::~Queue()
{
	delete s;
}
int main()
{
	Queue st;
	st.getSize(2);
	st.pushBack(2);
	st.pushBack(5);
	st.display();
	st.pushBack(4);
	cout << "Dequed element is" << st.deleteFront() << endl;
	st.pushFront(8);
	cout << "Dequed element is" << st.deleteFront() << endl;
	cout<<"Dequed elemenyt is"<<st.deleteBack()<<endl;
	st.deleteFront();
	return 0;
}