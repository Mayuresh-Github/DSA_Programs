/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 2 */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

/* Defining namespace */
using namespace std;

/* Main Function */
int main()
{
	int m[50], c1[50];
	int i, n;
	int total = 0;
	int  avg, high = 0, low = 100, h = 0, count = 0, c = 0;

	cout << "\n Enter total number of Students: ";
	cin >> n;
	count = n;

	for (i = 0;i < n;i++)
	{
		cout << " " << i+1;
	}

	cout << "\n \n Enter marks obtain by the Students(-1 for Absent Students): ";
	for (i = 0;i < n;i++)
	{
		cin >> m[i];
	}

	cout << "\n Roll no \tMarks";
	for (i = 0;i < n;i++)
	{
		cout << "\n\n    "<< i+1 << "  \t\t " << m[i];
	}

	/* Average marks */
	int countavg = n;
	for (i = 0;i < n;i++)
	{
		if (m[i] == -1)
		{
			i++;
			countavg--;
		}
		total = total + m[i];
	}
	avg = total / countavg;
	cout << "\n \n Average marks: " << avg;

	/* Highest marks */
	for (i = 0;i < n;i++)
	{
		if (m[i] != -1)
		{
			if (m[i] > high)
			{
				high = m[i];
			}
		}
	}
	cout << "\n Highest marks: " << high;

	/* Lowest marks */
	for (i = 0;i < n;i++)
	{
		if (m[i] != -1)
		{
			if (m[i] < low)
			{
				low = m[i];
			}
		}
	}
	cout << "\n Lowest marks: " << low;

	/* Students scoring highest marks */
	count = 0;
	for (i = 0;i < n;i++)
	{
		if (m[i] != -1)
		{
			if (m[i] == high)
			{
				count = count + 1;
			}
		}
	}
	cout << "\n \n Total number of students scoring Highest marks: " << count;

	/* Absent students */
	cout << "\n \n List of roll no of the students absent for the test: ";
	for (i = 0;i < n;i++)
	{
		if (m[i] == -1)
		{
			cout << " " << i+1;
		}
	}
	cout << "\n";

	/* Students scoring most marks */
	int cnt = 0;
	for (i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (m[i] != 0)
			{
				if (m[i] == m[j])
				{
					cnt++;	//highest occurance
					c1[i] = cnt;
				}
			}
			else
			{
				c1[i] = 0;
			}
		}
	}
	/* Store highest occured element count in h */
	int h1 = 1;
	for (i = 0;i < n;i++)
	{
		if (h1 < c1[i])
		{
			h1 = c1[i];
		}
	}
	for (i = 0;i < n;i++)
	{
		if (h1 == c1[i])
		{
			cout << "\n Marks scored by most of the Students : " << m[i];
			break;
		}
	}

	return 0;
}
/* End of Main Function */

