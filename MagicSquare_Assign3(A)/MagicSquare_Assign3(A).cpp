/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 3(A) */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

/* Defining namespace */
using namespace std;

/* Main Function */
int main()
{
	int i, j, n, a[10][10];

	cout << "\n Enter matrix dimensions: ";
	cin >> n;

	cout << "\n Enter matrix elements: ";
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			cin >> a[i][j];
		}
		cout << "\n";
	}

	cout << "\n Matrix elements are: " << endl;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "\n ------------------------------------------------------------\n";
	int flg, pt = 0, rsum = 0, dsum = 0, csum = 0;

	/* Diagonal sum */
	for (i = 0;i < n;i++)
	{
		dsum = dsum + a[i][i];
	}
	/* Compare Diagonal sum with Row sum */ 
	for (i = 0;i < n;i++)
	{
		rsum = 0;
		flg = 0;
		for (j = 0;j < n;j++)
		{

			rsum = rsum + a[i][j];
		}
		if (rsum == dsum)
		{
			flg = 1;
		}
		else
		{
			cout << "\n Its is not a Magic Matrix!" << endl;
			break;
		}
	}

	/* Compare Diagonal sum with Column sum */ 
	if (flg == 1)
	{
		for (j = 0;j < n;j++)
		{
			csum = 0; pt = 0;

			for (i = 0;i < n;i++)
			{
				csum = csum + a[i][j];
			}
			if (csum == dsum)
			{
				pt = 1;
			}
			else
			{
				pt = 0;
				cout << "\n It is not a Magic Matrix!" << endl;
				break;
			}
		}
		if (pt == 1)
		{
			cout << "\n It is a Magic Matrix!" << endl;
		}

	}
	return 0;
}
/* End of Main Function */