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
		cout << "Stack is full" << endl;
}
int Stack::pop()
{
	int x = -999;
	if (!IsEmpty())
		x = s[top--];
	else
		cout << "Stack is empty" << endl;
	return x;
}
int Stack::peek()
{
	int y = -999;
	if (!IsEmpty())
		y = s[top];
	return y;
}
void Stack::display()
{
	for (int i = 0; i <= top; i++)
		cout << s[i] << endl;
}
Stack::~Stack()
{
	delete s;
}
int prec(char c)
{
	if (c == '+' || c == '-')
		return 2;
	else if (c == '*' || c == '/')
		return 3;
	else if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')
		return 1;
	else
		return 0;
}
int main()
{
	int  i,a,b,s=0,k=1;
	char str[30], c, op[30];
	Stack st;
	cin >> str;
	st.getSize(30);
	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		if (c=='+' || c=='-' || c=='*' || c=='/')
		{
			a = st.pop();
			b = st.pop();
			if (c == '+')
				st.push(a + b);
			else if (c == '-')
				st.push(b - a);
			else if (c == '*')
				st.push(a * b);
			else if (c == '/')
				st.push(b / a);
		}
		else if (c != '@')
		{
			s = s * k+(c-48);
			k = k * 10;
		}
		else if(c=='@')
		{
			st.push(s);
			k = 1;
			s = 0;
		}
	}
	cout << st.peek();
	return 0;
}