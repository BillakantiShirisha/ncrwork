#include<stdio.h>
#include<iostream>
#include<stack>
#include "Files.h"
#include<stdlib.h>
using namespace std;
int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}
// Function to perform arithmetic operations
float applyOp(float a, float b, char op) {
	switch (op) {
	case '+': return add(a,b);
	case '-': return sub(a,b);
	case '*': return mul(a,b);
	case '/': return divn(a,b);
	}
}
//Function to evaluate expression
float evaluate(char *expr)
{
	stack<float> operand;
	stack<char> operators;
	int i;
	for (i = 0; expr[i] != '\0'; i++)
	{
		//character is Space
		if (expr[i] == ' ')
			continue;
		//character is (
		else if (expr[i] == '(')
			operators.push(expr[i]);
		//character is digit
		else if (isdigit(expr[i]))
		{
			int var = 0;
			while (expr[i] != '\0' && isdigit(expr[i]))
			{
				var = var * 10 + expr[i] - '0';
				i++;
			}
			i--;
			operand.push(var);
			//cout << var << endl;
		}
		//character is )
		else if (expr[i] == ')')
		{
			while ((!operators.empty()) && operators.top() != '(')
			{
				float op1 = operand.top();
				operand.pop();
				float op2 = operand.top();
				operand.pop();
				char op = operators.top();
				operators.pop();
				operand.push(applyOp(op2, op1, op));
			}
			operators.pop();
		}
		//character is operator
		else
		{
			while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i]))
			{
				float op1 = operand.top();
				operand.pop();
				float op2 = operand.top();
				operand.pop();
				char op = operators.top();
				operators.pop();
				operand.push(applyOp(op2, op1, op));
			}
			operators.push(expr[i]);
		}
	}
	//If the operators and operand stacks are not empty
	while (!operators.empty())
	{
		float op1 = operand.top();
		operand.pop();
		float op2 = operand.top();
		operand.pop();
		float op = operators.top();
		operators.pop();
		//cout << applyOp(op2, op1, op) << endl;
		operand.push(applyOp(op2, op1, op));
	}
	//cout << operand.top();
	return operand.top();
}
int main()
{
	char *expr; 
	int size;
	printf("Enter length of string\n");
	scanf("%d", &size);
	expr = (char*)malloc(sizeof(char)*size);
	printf("Enter expression to evaluate\n");
	scanf(" %[^\t\n]s", expr);
	printf("Result of the expression %s is %f", expr, evaluate(expr));
	free(expr);
	getchar();
	return 0;
}