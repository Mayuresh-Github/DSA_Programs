/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 7 */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

#define max 10

/* Defining namespace */
using namespace std;

/* Class Declaration */
class wellpth
{
	int top, flg;
	char stk[max];
	
	public:
		wellpth()
		{
			top = -1;
			flg = 0;
		}

		void push(char a);	
		void pop(char a);
		void display();
};
/* End of Class Declaration */

/* Body of Functions */
void wellpth::push(char a)
{
	top = top + 1;
	stk[top] = a;
}

void wellpth::pop(char a)
{
	if (a == '}')
	{
		if (stk[top] == '{')
		{
			top = top - 1;
		}
		else
		{
			flg = 1;
		}

	}
	if (a == ')')
	{
		if (stk[top] == '(')
		{
			top = top - 1;
		}
		else
		{
			flg = 1;
		}

	}
	if (a == ']')
	{
		if (stk[top] == '[')
		{
			top = top - 1;
		}
		else
		{
			flg = 1;
		}
	}
}

void wellpth::display()
{
	if (flg == 1 || top != -1)
	{
		cout << "\n Not Well Parenthesis (Unbalanced)!" << endl;
		cout << "\n Error: " << stk[top] << " bracket not closed" << endl;
	}
	else
	{
		cout << "\n Well Parenthesis (Balanced)!" << endl;
	}
}
/* End of Body of Functions */

/* Main Function */
int main()
{
	int i;
	char wp[20];
	wellpth obj;

	cout << "\n Insert the parenthesis string: ";
	cin >> wp;

	int len = strlen(wp);

	for (i = 0;i < len;i++)
	{
		if (wp[i] == '(' || wp[i] == '{' || wp[i] == '[')
		{
			char s = wp[i];
			obj.push(s);
		}
		else
		{
			if (wp[i] == ')' || wp[i] == '}' || wp[i] == ']')
			{
				char s = wp[i];
				obj.pop(s);
			}
		}
	}
	obj.display();

	return 0;
}
/* End of Main Function */