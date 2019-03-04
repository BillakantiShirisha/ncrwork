#include<iostream>
using namespace std;
#define SIZE 10
template<class T>
class Stack
{
	int top;
	T arr[SIZE];
public:
	Stack()
	{
		top = -1;
	}
	void push(T x)
	{
		if (top == SIZE - 1)
			cout << "Stack overflow\n";
		arr[++top] = x;
	}
	T pop()
	{
		if (top == -1)
		{
			cout << "Stack underflow\n";
			return -1;
		}
		return arr[top--];
	}
	int size()
	{
		return top + 1;
	}
	~Stack()
	{

	}
};
int main()
{
	Stack<int> s;
	s.push(12);
	cout << "Size of the stack is " << s.size() << endl;
	s.push(9);
	cout << "Top of the stack is " << s.pop() << endl;
	s.push(162);
	cout << "Size of the stack is " << s.size() << endl;
	cout << "Top of the stack is " << s.pop() << endl;
	getchar();
	return 0;
}