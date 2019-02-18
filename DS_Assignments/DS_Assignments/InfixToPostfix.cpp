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
	int  flag = 0, i,j=0;
	char str[30], c,op[30];
	Stack st;
	cin >> str;
	st.getSize(30);
	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		if (c == '(' || c == '{' || c == '[')
			st.push(c);
		else if (c == ')')
		{
			while (st.peek() != '(')
			{
				op[j++] = st.pop();
			}
			st.pop();
		}
		else if (c == '}')
		{
			while (st.peek() != '{')
			{
				op[j++] = st.pop();
			}
			st.pop();
		}
		else if (c == ']')
		{
			while (st.peek() != '[')
			{
				op[j++] = st.pop();
			}
			st.pop();
		}
		else if(isalpha(c))
			op[j++] = c;
		else
		{
				while (prec(c) <= prec(st.peek()))
					op[j++] = st.pop();
				st.push(c);
		}
	}
	while (!st.IsEmpty())
		op[j++] = st.pop();
	op[j] = '\0';
	for (j = 0; op[j] != '\0'; j++)
		cout << op[j];
	return 0;
}