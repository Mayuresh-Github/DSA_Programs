#include<iostream>

using namespace std;

class node
{
	node* left;
	node* right;

	char data;

	friend class tree;
};

class tree
{

public:
	node* root;
	tree()
	{
		root = NULL;
	}

	node* create();
	void display();
	void operator=(tree& t1);
	node* copy_ele(node*);
	void delete_tree(node*);
	node* getRoot();
};

class stack
{
	int top;
	node* st[20];

public:
	stack()
	{
		top = -1;
	}

	void push(node* a)
	{
		top = top + 1;
		st[top] = a;

	}

	node* pop()
	{
		return st[top--];

	}

	int empty()
	{
		if (top == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

node* tree::create()
{
	char ch;
	char ans = ' ';

	do
	{
		node* newnode;
		newnode = new node;

		cout << "\n Enter data: ";
		cin >> newnode->data;

		newnode->left = NULL;
		newnode->right = NULL;

		if (root == NULL)
		{
			root = newnode;
			cout << "\n Root of Tree: " << newnode->data << " ........created! \n ";
		}
		else
		{
			node* temp;
			temp = root;

			while (1)
			{
				cout << "\n Do you want to enter Left/Right? \n \n Enter choice: ";
				cin >> ch;

				if (ch == 'L' || ch == 'l')
				{
					if (temp->left == NULL)
					{
						temp->left = newnode;
						break;
					}
					else
					{
						temp = temp->left;
					}
				}

				else if (ch == 'R' || ch == 'r')
				{
					if (temp->right == NULL)
					{
						temp->right = newnode;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
			}

			cout << "\n Do you want to add more nodes? ";
			cin >> ans;
		}

	}while (ans == 'Y' || ans == 'y');

	return root;
}

void tree :: operator=(tree& t1)
{
	node* assi;
	assi = copy_ele(t1.root);
	root = assi;
}

node* tree::copy_ele(node* curr)
{
	if (curr == NULL)
	{
		return NULL;
	}
	else
	{
		node* newnode = new node;
		newnode->data = curr->data;

		newnode->left = copy_ele(curr->left);
		newnode->right = copy_ele(curr->right);

		return newnode;
	}
}
void tree::delete_tree(node* n)
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		delete_tree(n->left);
		delete_tree(n->right);
		delete(n);
	}
	root = NULL;

}

node* tree::getRoot()
{
	return root;
}

void tree::display()
{
	stack s;
	node* temp;
	temp = root;

	if (temp == NULL)
	{
		cout << "\n Tree is Empty";
	}
	else
	{
		cout << "\n =============Display=========== \n ";
		while (1)
		{
			while (temp != NULL)
			{
				s.push(temp);
				temp = temp->left;
			}
			if (s.empty())
			{
				return;
			}
			else
			{
				temp = s.pop();
				cout << "  " << temp->data << " -> ";
				temp = temp->right;
			}
		}
	}

	cout << "\n";
}

int main()
{
	int ch1;
	tree tree1, tree2;

	node* t1{};
	node* t2{};

	while (1)
	{

		cout << "\n \n 1. Tree 1 Create \n 2. Tree 2 Create \n 3. Address of Both Trees \n 4. Assignment \n 5. Tree Display \n 6. Delete Tree 1 \n 7. Delete Tree 2 \n 8. Exit \n \n Enter choice:  ";
		cin >> ch1;

		switch (ch1)
		{
			case 1:
				t1 = tree1.create();
				cout << "\n Tree 1 Create and Display ";
				tree1.display();
				break;
					
			case 2:
				t2 = tree2.create();
				cout << "\n Tree 1 Create and Display ";
				tree2.display();
				break;

			case 3:
				cout << "\n Tree 1 Address ";
				cout << tree1.getRoot();
					
				cout << "\n Tree 2 Address ";
				cout << tree2.getRoot();
				break;


			case 4:
				cout << "\n Assignment Done ";
				tree2 = tree1;
				break;


			case 5:
				cout << "\n Tree 1 Display ";
				tree1.display();

				cout << "\n Tree 2 Display ";
				tree2.display();
				break;

			case 6:
				cout << "\n Deleting Tree 1 ";
				tree1.delete_tree(t1);
				break;

			case 7:
				cout << "\n Deleting Tree 1 ";
				tree2.delete_tree(t2);
				break;

			case 8:
				return 0;
				break;
		}

	}
	return 0;

}

