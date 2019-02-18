#include<iostream>
using namespace std;
class Stack
{
	int top;
	char *s;
	int size;
public:
	Stack();
	void push(char);
	char pop();
	char peek();
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
	s = new char[n];
}
bool Stack::IsFull()
{
	return (top == (size - 1));
}
bool Stack::IsEmpty()
{
	return (top == -1);
}
void Stack::push(char ele)
{
	if (!IsFull())
		s[++top] = ele;
	else
		cout << "Stack is full" << endl;
}
char Stack::pop()
{
	char x = '\0';
	if (!IsEmpty())
		x = s[top--];
	else
		cout << "Stack is empty" << endl;
	return x;
}
char Stack::peek()
{
	char y = '\0';
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
int main()
{
	int  flag=0,i;
	char str[10],c;
	Stack st;
	cin >> str;
	st.getSize(10);
	for (i = 0; str[i]!='\0'; i++)
	{
		c = str[i];
		if ((c == '(') || (c == '{') || (c == '['))
			st.push(c);
			if ((c == ')' && st.peek() == '(') || (c == '}'&& st.peek() == '{') || (c == ']' && st.peek() == '['))
				st.pop();
			else if ((c == ')' && st.peek()!= '(') || (c == '}'&& st.peek() != '{') || (c == ']' && st.peek() != '['))
			{
				flag = 1;
				break;
			}
	}
	if ((flag == 0) && (st.IsEmpty()))
		cout << "Balanced";
	else
		cout << "Unbalanced";
	return 0;
}