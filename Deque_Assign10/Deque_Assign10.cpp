/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 10 */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

#define max 10

/* Defining namespace */
using namespace std;

/* Class */
class dequeue_imple
{
	int r, f;
	int n[max];

public:
	/* Constructor */
	dequeue_imple()
	{
		f = -1;
		r = -1;
	}

	/* Functions */
	void EnqueueR()
	{
		if (r == (max - 1))
		{
			cout << "\n Queue is full!" << endl;
			return;
		}

		if (f == -1 && r == -1)
		{
			r = 0;
			f = 0;

			cout << "\n Enter the value to be Queued: ";
			cin >> n[f];
		}
		else
		{
			cout << "\n Enter the value to be Queued: ";
			cin >> n[++r];
		}
	}

	void EnqueueF()
	{
		if (f == 0)
		{
			cout << "\n Can't insert from Front!" << endl;
			return;
		}

		if (f == -1 && r == -1)
		{
			r = 0;
			f = 0;

			cout << "\n Enter the value to be Queued: ";
			cin >> n[f];
		}
		else
		{
			cout << "\n Enter value to be Queued: ";
			cin >> n[--f];
		}
	}

	void DequeueR()
	{
		if (f == -1 && r == -1)
		{
			cout << "\n Queue is Empty!" << endl;
			return;
		}

		if (f == r)
		{
			f = -1;
			r = -1;

			cout << "\n The element is deleted!" << endl;
			return;
		}

		if (f != r && r >= f)
		{
			r--;
		}

	}


	void DequeueF()
	{
		if (f == -1 && r == -1)
		{
			cout << "\n The Queue is Empty!" << endl;
			return;
		}

		if (f == r)
		{
			f = -1;
			r = -1;

			cout << "\n The element is deleted!" << endl;
			return;
		}

		if (f != r && r >= f)
		{
			f++;
		}
	}

	void display()
	{
		int s;
		s = f;

		if (f == -1 && r == -1)
		{
			cout << "\n Queue is Empty!" << endl;
			return;
		}

		if (f == (max - 1))
		{
			cout << "\n Queue is Full!" << endl;
			f = -1;
			r = -1;
			return;
		}

		cout << "\n Elements of Queue: ";
		while (s <= r)
		{
			cout << n[s] << " ";
			s++;
		}
		cout << "\n";
	}
	/* End of Functions */
};
/* End of Class */

/* Main Function */
int main()
{
	dequeue_imple d;
	int op = -1;

	while (op != 0)
	{
		cout << "\n \n 1. E -> R \n 2. E -> F \n 3. D -> R \n 4. D -> F \n 5. Display \n 6. Exit";
		cout << "\n \n Enter choice: ";
		cin >> op;

		switch (op)
		{
			case 1:
				cout << "\n E -> R:";
				d.EnqueueR();
				d.display();
				break;

			case 2:
				cout << "\n E -> F:";
				d.EnqueueF();
				d.display();
				break;

			case 3:
				cout << "\n D -> R:";
				d.DequeueR();
				d.display();
				break;

			case 4:
				cout << "\n D -> F:";
				d.DequeueF();
				d.display();
				break;

			case 5:
				cout << "\n Display:";
				d.display();
				break;

			case 6:
				cout << "\n Exit" << endl;
				return 0;
				break;
				
			default:
				cout << "\n Enter correct choice!" << endl;
				break;
		}
	}

	return 0;
}
/* End of Main Function */