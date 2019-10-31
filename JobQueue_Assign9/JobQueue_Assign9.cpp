/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 9 */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>
#include<string>

/* Defining namespace */
using namespace std;

/* Class */
class queuee
{
	string job[100];
	int n = 0, f = 0, r = 0;

	public:
	void insertsize()
	{
		cout << "\n Enter the number of the jobs: ";
		cin >> n;
	}

	void insertj()
	{
		if (r - f >= n - 1)
		{
			cout << "\n Queue is FULL!" << endl;
		}
		else
		{
			cout << "\n Enter the name of the job: ";
			cin >> job[r];
			r = r + 1;
		}
	}

	void deletej()
	{
		if (f != r)
		{
			f = f + 1;
			cout << "\n Deleted!" << endl;
		}
		else
		{
			cout << "\n Queue IS EMPTY!" << endl;
		}
	}

	void display()
	{
		cout << "\n The Queue is: ";
		for (int i = f;i <= r;i++)
		{
			cout << job[i] << " ";
		}
		cout << "\n" << endl;

	}

};
/* End of Class */

/* Main Function */
int main()
{
	queuee q;
	int ch;

	q.insertsize();

	while (1)
	{	
		cout << "\n 1.INSERT\n 2.DELETE\n 3.DISPLAY\n 4.EXIT" << endl;
		cout << "\n Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
			case 1:
				q.insertj();
				q.display();
				break;

			case 2:
				q.deletej();
				q.display();
				break;

			case 3:	
				q.display();
				break;

			case 4:
				q.display();
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

