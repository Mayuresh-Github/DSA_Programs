/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 12 */
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
	void InsertionSort();
	void ShellSortDisplay();
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

void Percentage::InsertionSort()
{
	float temp;

	for (i = 1; i < n; i++)
	{
		temp = a[i];
		j = i - 1;

		while (temp < a[j] && (j >= 0))
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = temp;
	}
}

void Percentage::ShellSortDisplay()
{
	int d = 0, k = 0;
	float temp;

	d = (n - 1) / 2;
	for (i = d;i >= 1;i = i / 2)
	{
		for (j = i;j <= n - 1;j++)
		{
			temp = a[j];
			k = j - i;
			while (k >= 0 && temp < a[k])
			{
				a[k + i] = a[k];
				k = k - i;
			}
			a[k + i] = temp;
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
		cout << "\n 1.Insert Records \n 2.Sort using Insertion Sort \n 3.Sort using Shell Sort and Display Top 5 Scores \n 4.Display \n 5.Exit" << endl;
		cout << "\n Enter choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			p.accept();
			break;

		case 2:
			p.InsertionSort();
			p.display();
			break;

		case 3:
			p.ShellSortDisplay();
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
