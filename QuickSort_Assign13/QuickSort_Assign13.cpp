/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 13 */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

/* Defining namespace */
using namespace std;

/* Function Declaration */
void quick(float*, int, int);

/* Main Function */
int main()
{
	float a[100];
	int n, l, u, ch, i;

	cout << "\n Enter the total No of Records: ";
	cin >> n;

	l = 0;
	u = n - 1;

	while (1)
	{
		cout << "\n 1.Insert \n 2.Quick Sort \n 3.Display \n 4.Top 5 Scores \n 5.Exit: " << endl;
		cout << "\n Enter choice: ";
		cin >> ch;

		switch (ch)
		{
			case 1: 
				cout << "\n Enter Records: ";
				for (i = 0; i < n; i++)
				{
					cin >> a[i];
				}
				break;

			case 2: 
				quick(a, l, u);
				break;

			case 3: 
				cout << "\n Display Records: ";
				for (i = 0; i < n; i++)
				{
					cout << a[i] << " ";
				}
				break;

			case 4: 
				cout << "\n Top 5 Scores: ";
				for (i = n - 1; i > n - 6; i--)
				{
					cout << a[i] << " ";
				}
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

/* Fucntion Definition */
void quick(float a[], int l, int u)
{
	float p, temp;
	if (l < u)
	{
		p = a[l];
		int i = l;
		int j = u;
		while (i < j)
		{
			while (a[i] <= p && i <= j)
				i++;
			while (a[j] >= p && i <= j)
				j--;

			if (i <= j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[j];
		a[j] = a[l];
		a[l] = temp;

		quick(a, l, j - 1);
		quick(a, j + 1, u);
	}
}
/* End of Function Definition */

















