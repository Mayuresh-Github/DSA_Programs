/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

/* Defining namespace */
using namespace std;

/* Class Declaration  */
class stk
{
	int top;
	int st[5];

	public:
		/* Constructor */
		stk()
		{
			top = -1;
		}

		void push(int a);
		void pop();
		void display();
};
/* End of Class Declaration */

/* Body of Functions */
void stk::push(int a)
{
	if (top > 4)
	{
		cout << "\n Overflow!" << endl;
	}
	else
	{
		top++;
		st[top] = a;
		cout << "\n Inserted!" << endl;
	}
}

void stk::pop()
{
	if (top < 0)
	{
		cout << "\n Underflow!" << endl;
	}
	else
	{
		cout << endl;
		cout << st[top] << " Deleted!" << endl;
		top--;
	}
}

void stk::display()
{
	if (top < 0)
	{
		cout << "\n Empty!" << endl;
	}
	else
	{
		cout << endl;
		for (int i = top;i >= 0;i--)
		{
			cout << " " << st[i];
		}
		cout << endl;
	}
}
/* End of Body of Functions */

/* Main Function */
int main()
{
	int ch, val;
	stk s;

	while (1)
	{
		cout << "\n \n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit" << endl;
		cout << "\n Enter choice: ";
		cin >> ch;

		switch (ch)
		{
			case 1: 
				cout << "\n Enter value: ";
				cin >> val;
				s.push(val);
				break;
		
			case 2: 
				s.pop();
				break;
		
			case 3:
				s.display();
				break;
		
			case 4: 
				exit(0);

			default:
				cout << "\n Enter correct choice!" << endl;
		}
	}
	return 0;
}
/* End of Main Function */