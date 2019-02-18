#include<iostream>
using namespace std;
class Stack 
{
	int top;
	int *s;
	int size;
public:
	Stack();
	void push(int);
	int pop();
	int peek();
	bool IsEmpty();
	bool IsFull();
	void display();
	~Stack();
	void getSize(int);
};
Stack::Stack()
{
	top = -1;
	s = NULL;
	size = 0;
}
void Stack::getSize(int n)
{
	size = n;
	s = new int[n];
}
bool Stack::IsFull()
{
	return (top == (size - 1));
}
bool Stack::IsEmpty()
{
	return (top == -1);
}
void Stack::push(int ele)
{
	if (!IsFull())
		s[++top] = ele;
	else
		cout << "Stack is full"<<endl;
}
int Stack::pop()
{
	int x = -999;
	if (!IsEmpty())
		x = s[top--];
	else
		cout << "Stack is empty"<<endl;
	return x;
}
int Stack::peek()
{
	int y = -999;
	if (!IsEmpty())
		y = s[top];
	else
		cout << "Stack is empty"<<endl;
	return y;
}
void Stack::display()
{
	for (int i = 0; i <= top; i++)
		cout << s[i]<<endl;
}
Stack::~Stack()
{
	delete s;
}
int main()
{
	int n;
	Stack st;
	cin >> n;
	st.getSize(n);
	st.push(2);
	st.push(5);
	st.display();
	cout<<st.peek()<<endl;
	st.push(4);
	cout<<"Popped element is"<<st.pop()<<endl;
	cout << "Popped element is" << st.pop()<<endl;
	st.pop();
	return 0;
}