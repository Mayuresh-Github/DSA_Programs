/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 11 */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

/* Defining namespace */
using namespace std;

/* Class Declaration */
class Percentage 
{
	int i, j, n;
	float x;
	float a[100];

	public:
		void accept();
		void SelectionSort();
		void BubbleSortDisplay();
		void display();
};
/* End of Class Declaration */

/* Body of Fucntions */
void Percentage::accept()
{
	cout << "\n Enter Array size: ";
	cin >> n;

	cout << "\n Enter Array Elements: ";
	for (i = 0;i < n;i++)
	{
		cin >> a[i];
	}
}

void Percentage::SelectionSort()
{
	int min;
	float temp = 0;

	cout << "\n Sorting using Selection Sort: ";
	for (i = 0;i < n-1;i++)
	{
		min = i;
		for (j = i+1;j < n;j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

void Percentage::BubbleSortDisplay()
{
	float temp = 0;

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (a[j] > a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

		}
	}

	cout << "\n Top 5 scores: ";
	for (i = 0;i < 5;i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n" << endl;
}

void Percentage::display()
{
	cout << "\n Display: ";
	for (i = 0;i < n;i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n" << endl;
}
/* End of Body of Functions */

/* Main Function */
int main()
{	
	int ch;
	Percentage p;
	int op = -1;


	while (op != 0)
	{
		cout << "\n What u want to do? " << endl;
		cout << "\n 1.Insert Records \n 2.Sort using Selection Sort \n 3.Sort using Bubble Sort and Display Top 5 Scores \n 4.Display \n 5.Exit" << endl;
		cout << "\n Enter choice: ";
		cin >> ch;

		switch (ch)
		{
			case 1:
				p.accept();
				break;

			case 2:
				p.SelectionSort();
				p.display();
				break;

			case 3:
				p.BubbleSortDisplay();
				break;

			case 4:
				p.display();
				break;

			case 5:
				exit(1);
				break;

			default:
				cout << "\n Enter correct choice!" << endl;
				break;
		}
	}

	return 0;
}
/* End of Main Function */
