/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 1 */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

/* Defining namespace */
using namespace std;

/* Declaring required Functions */
void Intersection(int n, int p, int* crick, int* bad, int* inter);
void Union(int n, int p, int* crick, int* bad, int* uni);
void Onlybad(int n, int p, int* crick, int* bad, int* uni);
void Onlycrick(int n, int p, int* crick, int* bad, int* uni);

/* Main Funtion */
int main()
{
	int a, i, j, n, p, ch;
	int crick[50], bad[50], inter[50], uni[50];

	cout << "\n Enter total number of students: ";
	cin >> a;

	cout << "\n Enter number of students playing cricket: ";
	cin >> n;
	cout << "\n Enter number of students playing badminton: ";
	cin >> p;

	cout << "\n Enter roll number of students play cricket: ";
	for (i = 0;i < n;i++)
	{
		cin >> crick[i];
	}
	cout << "\n Enter roll number of students play badminton: ";
	for (j = 0;j < p;j++)
	{
		cin >> bad[j];
	}

	while (1)
	{

		cout << "\n1.Intersection \n2.Union \n3.Only Cricket \n4.Only Badminton \n5.None of them \n6.Exit: ";
		cout << "\n \nEnter your choice: ";
		cin >> ch;

		switch (ch)
		{
			case 1:
				Intersection(n, p, crick, bad, inter);
				break;

			case 2:
				Union(n, p, crick, bad, uni);
				break;

			case 3:
				Onlycrick(n, p, crick, bad, uni);
				break;

			case 4:
				Onlybad(n, p, crick, bad, uni);
				break;

			case 5:
				return 1;
				break;

			case 6:
				exit(0);
		}
	}
	return 0;
}
/* End of Main Function */

/* Body of Funtions */
void Intersection(int n, int p, int* crick, int* bad, int* inter)
{
	int i, j, q = 0;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < p;j++)
		{
			if (crick[i] == bad[j])
			{
				inter[q] = crick[i];
				q++;
			}
		}
	}

	cout << "\n Intersection is: ";
	for (i = 0;i < q;i++)
	{
		cout << " " << inter[i];
	}

}

void Union(int n, int p, int* crick, int* bad, int* uni)
{
	int i, j, k = 0, z = 1;
	for (i = 0;i < n;i++)
	{
		uni[k] = crick[i];
		k++;
	}
	for (j = 0;j < p;j++)
	{
		z = 1;
		for (i = 0;i < p;i++)
		{
			if (bad[j] == crick[i])
			{
				z = 0;
				break;
			}
		}

		if (z == 1)
		{
			uni[k] = bad[j];
			k++;
		}
	}

	cout << "\n Union is: ";
	for (i = 0;i < k;i++)
	{
		cout << " " << uni[i];
	}
}

void Onlybad(int n, int p, int* crick, int* bad, int* uni)
{
	int i, j, k = 0, y = 1;
	for (j = 0;j < p;j++)
	{
		y = 1;
		for (i = 0;i < p;i++)
		{
			if (bad[j] == crick[i])
			{
				y = 0;
				break;
			}
		}
		if (y == 1)
		{

			uni[k] = bad[j];
			k++;
		}
	}

	cout << "\n Student play only badminton: ";
	for (i = 0;i < k;i++)
	{
		cout << " " << uni[i];
	}
}

void Onlycrick(int n, int p, int* crick, int* bad, int* uni)
{
	int i, j, k = 0, z = 1;
	for (i = 0;i < p;i++)
	{
		z = 1;
		for (j = 0;j < p;j++)
		{
			if (crick[i] == bad[j])
			{
				z = 0;
				break;
			}
		}
		if (z == 1)
		{
			uni[k] = crick[i];
			k++;
		}
	}

	cout << "\n Student playing only cricket: ";
	for (j = 0;j < k;j++)
	{
		cout << " " << uni[j];
	}
}
/* End of Body of Funtions */