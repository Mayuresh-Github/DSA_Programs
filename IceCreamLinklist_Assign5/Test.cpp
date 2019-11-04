/* Created By : Mayuresh Mitkari */
/* Purpose : DSA LAB ASSIGNMENT 5 */
/* Created on : 30 OCT 2019 */
/* Language : C++ */

/* Header files */
#include<iostream>

/* Defining namespace */
using namespace std;

/* Class Declaration */
class node
{	
	public:
		int data;
		node* next;
		
		void insertE(node* head, int d);
		void display(node* head);
		int unio(node* headb, node* headv, node* headu, int n);
		void inters(node* headb, node* headv, node* headi);
		void nustaBV(node* headb, node* headv, node* heado);
		int none(int m, int N, int k);
};
/* End of Class Declaration */

/* Body of Functions */
void node :: insertE(node* head, int d)
{
	node* p;
	node* q;
	p = new node;

	p->next = NULL;
	p->data = d;

	if (head->next == NULL)
	{
		head->next = p;
	}
	else
	{
		q = head;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;

	}
}

void node :: display(node* head)
{
	node* q;
	q = head->next;
	cout << "\n[\t";

	while (q != NULL)
	{
		cout << q->data << "\t";
		q = q->next;
	}
	cout << "]\n";
}

int node :: unio(node* headb, node* headv, node* headu, int n)
{
	int flag = 0;
	n = 0;

	node* p;
	node* q;
	q = new node;
	q->next = NULL;

	p = new node;
	p->next = NULL;
	p = headb->next;

	while (p != NULL)
	{
		insertE(headu, p->data);
		n++;
		p = p->next;
	}

	p = headv->next;
	while (p != NULL)
	{

		flag = 0;
		q = headb->next;
		while (q != NULL)
		{
			if (p->data == q->data)
			{
				q = q->next;
				flag = 1;
			}
			else
				q = q->next;

		}
		if (flag == 0)
		{
			insertE(headu, p->data);
			n++;
		}
		p = p->next;
	}
	return n;
}

void node :: inters(node* headb, node* headv, node* headi) 
{

	node* p;
	p = new node;
	p->next = NULL;

	node* q;
	q = new node;
	q->next = NULL;

	p = headb->next;
	while (p != NULL)
	{
		q = headv->next;
		while (q != NULL)
		{
			if (p->data == q->data)
			{
				insertE(headi, p->data);
				q = q->next;
			}
			else
			{
				q = q->next;
			}
		}
		p = p->next;
	}
}

void node :: nustaBV(node* headb, node* headv, node* heado)
{
	int flag = 0;
	node* p;
	p = new node;
	p->next = NULL;

	node* q;
	q = new node;
	q->next = NULL;

	p = headb->next;
	while (p != NULL)
	{
		q = headv->next;
		flag = 0;
		while (q != NULL)
		{

			if (q->data == p->data)
			{
				flag = 1;
				q = q->next;
			}
			else
			{
				q = q->next;
			}

		}
		if (flag == 0)
		{
			insertE(heado, p->data);
		}

		p = p->next;
	}
}

int node :: none(int m, int N, int k)
{
	k = m - N;
	return k;
}
/* End of Body of Functions */

/* Main Function */
int main()
{
	node n;
	node* headb;
	node* headv;

	headv = new node;
	headv->next = NULL;
	headb = new node;
	headb->next = NULL;

	int i, c = 0, b, v, ch, N, roll, z;
	int l = 0;

	cout << "\n Enter the total number of the students in the class: ";
	cin >> N;
	cout << "\n ===============   ** BUTTERSCOTCH STUDENTS **  ================\n";
	cout << "\n Enter how many students like butterscotch: ";
	cin >> b;
	for (i = 0;i < b;i++)
	{
		cout << "\n Enter roll number: ";
		cin >> roll;
		n.insertE(headb, roll);

	}
	cout << "\n ===============   ** VANILLA STUDENTS **  ================\n";
	cout << "\n Enter how many students like vanilla: ";
	cin >> v;
	for (i = 0;i < v;i++)
	{
		cout << "\n Enter roll number: ";
		cin >> roll;
		n.insertE(headv, roll);
	}
	while (1)
	{
		cout << "\n ===============  **  OPERATIONS MENU  **  =================\n";
		cout << "\n 1:Roll Number of Students who like EITHER vanilla OR butterscotch.\n 2:Roll Number of Students who like BOTH Vanilla and Butterscotch.";
		cout << "\n 3:Roll Number of Students who Like ONLY BUTTERSCOTCH.\n 4:Roll Number of Students who Like ONLY VANILLA.\n 5:Number of Students NOT INTERESTED in BOTH.\n ENTER YOUR CHOICE: ";
		cin >> ch;
		switch (ch)
		{
			case 1:
				cout << "\n  =======  **  UNION  **  =======\n";
				node* headu;
				headu = new node;
				headu->next = NULL;
				c = n.unio(headb, headv, headu, c);
				n.display(headu);
				break;

			case 2:
				cout << "\n  ====== ** INTERSECTION **  ===== \n";
				node* headi;
				headi = new node;
				headi->next = NULL;

				n.inters(headb, headv, headi);
				n.display(headi);
				break;

			case 3:
				cout << "\n ======= **  ONLY BUTTERSCOTCH  **  ====== \n";
				node* heado;
				heado = new node;
				heado->next = NULL;

				n.nustaBV(headb, headv, heado);
				n.display(heado);
				break;
	
			case 4:
				cout << "\n =======  **  ONLY VANILLA  **  ====== \n";
				node* headov;
				headov = new node;
				headov->next = NULL;

				n.nustaBV(headv, headb, headov);
				n.display(headov);
				break;

			case 5:
				cout << "\n ============ **  STUDENTS NOT INTERESTED IN ICECREAM  **  =============\n";
				z = n.none(N, c, l);

				cout << "\n The number of students who do not Like ice cream is: " << z;
				break;
		}
	}
	return 0;
}
/* End of Main Function */