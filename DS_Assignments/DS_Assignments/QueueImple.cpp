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
	void enque(int);
	int deque();
	bool underflow();
	bool overflow();
	void display();
	~Queue();
	void getSize(int);
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
bool Queue::overflow()
{
	return (r == (size - 1));
}
bool Queue::underflow()
{
	return (r==f && f== -1);
}
void Queue::enque(int ele)
{
	if (!overflow())
	{
		if (r == f && f == -1)
			f++;
		s[++r] = ele;
	}
	else
		cout << "Queue is full" << endl;
}
int Queue::deque()
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
	st.enque(2);
	st.enque(5);
	st.display();
	st.enque(4);
	cout << "Dequed element is" << st.deque() << endl;
	cout << "Dequed element is" << st.deque() << endl;
	st.deque();
	return 0;
}