/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 8 */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

#define max 40

/* Defining namespace */
using namespace std;

int temp;

/* Class Declaration */
class inxpfx
{
	public:
		int top;
		char stk[max];

		/* Constructor */
		inxpfx()
		{
			top = -1;
		}

		void push(char a);
		char pop();
		int priority(char a);
		int empty()
		{
			if (top == -1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		char gettop()
		{
			return stk[top];
		}
};
/* End of Class Declaration */

/* Body of Function */
void inxpfx::push(char a)
{
	top = top + 1;
	stk[top] = a;
}

char inxpfx::pop()
{
	return stk[top--];

}

int inxpfx::priority(char a)
{
	if (a == '^')
	{
		return 3;
	}
	else if (a == '*' || a == '/')
	{
		return 2;
	}
	else if (a == '+' || a == '-')
	{
		return 1;
	}
}
/* End of Body of Function */

/* Main Function */
int main()
{
	int i = 0;
	char exp[30], temp, s;
	inxpfx obj;

	cout << "\n Insert the Expression: ";
	cin >> exp;

	int len = strlen(exp);

	while (exp[i] != '\0')
	{
		s = exp[i];
		if (exp[i] == '(')
		{
			obj.push(s);
		}
		else if (s == ')')
		{

			temp = obj.pop();
			while (temp != '(')
			{
				cout << temp;
				temp = obj.pop();
			}
		}
		else if (isalpha(s))
		{
			cout << s;
		}
		else
		{
			if (obj.empty())
			{
				obj.push(s);
			}
			else
			{
				if (obj.gettop() == '(')
				{
					obj.push(s);
				}
				else if (obj.priority(s) > obj.priority(obj.gettop()))
				{
					obj.push(s);
				}
				else
				{
					while (obj.priority(s) <= obj.priority(obj.gettop()))
					{
						temp = obj.pop();
						cout << temp;
					}
					obj.push(s);
				}

			}
		}
		i++;
	}
	if (i == len)
	{
		while (!obj.empty())
		{
			temp = obj.pop();
			cout << temp;
		}
	}
	return 0;
}
/* End of Main Function */
