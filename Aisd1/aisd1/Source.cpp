#include <iostream>
#include <math.h>
using namespace std;

int id = 1;
int summ = 1;

class Info{
public:
	int info;
	Info()
	{
		info = summ + 100;
		summ++;
	}
};

class Node {
public:
	Node* next;
	int index;
	Info inf;
	Node()
	{
		index = id++;
	}
};

class List {
public:
	Node* head;

	void indexing()
	{
		int x = 1;
		if (head == nullptr)
			cout << "List is empty";
		else
		{
			Node* curr = head;
			while (curr != nullptr)
			{
				curr->index = x++;
				curr = curr->next;
			}
		}
		id = x;
	}

	void addend()
	{
		if (head == nullptr)
			head = new Node;
		else
		{
			Node *curr = head;

			while (curr->next != nullptr)
				curr = curr->next;
			curr->next = new Node;
		}
		indexing();
	}

	void addbeg()
	{
		if (head == nullptr)
			head = new Node;
		else
		{
			Node* curr = new Node;
			curr->next = head;
			head = curr;
		}
		indexing();
	}

	void dellast()
	{
		if (head == nullptr)
			cout << "List is empty";
		else {
			Node* curr = head;
			if (curr->next == nullptr)
				head = nullptr;
			if (curr->next->next == nullptr)
				head->next = nullptr;
			if (curr->next->next != nullptr)
				while (curr->next->next != nullptr)
					curr = curr->next;
			delete curr->next;
			curr->next = nullptr;
		}
		indexing();
	}

	void dellfirst()
	{
		if (head == nullptr)
			cout << "List is empty";
		else {
			Node* curr = head;
			head = curr->next;
			delete curr;
		}
		indexing();
	}

	void out()
	{
		if (head == nullptr)
			cout << "List is empty\n";
		else {
			Node* curr = head;
			while (curr != nullptr)
			{
				cout << curr->index << ") " << curr->inf.info << " ";
				curr = curr->next;
			}
			cout << endl;
		}
	}

	void idin()
	{
		int x;
		cout << "Enter index(int) : ";
		cin >> x;
		if (head == nullptr)
			cout << "List is empty";
		Node* curr = head;
		Node* buff;
		if (x == 0)
			addbeg();
		else {
			for (int i = 1; i < x - 1; i++)
			{
				if (curr->next != nullptr)
					curr = curr->next;
				else
				{
					cout << "Max ind is " << i;
					x = -1;
					break;
				}
			}
			if (x != -1)
			{
				buff = new Node;
				buff->next = curr->next;
				curr->next = buff;
			}
		}
		indexing();
	}

	void idout() {
		int x;
		cout << "Enter index(int) : ";
		cin >> x;
		if (head == nullptr)
			cout << "List is empty";
		Node* curr = head;
		for (int i = 1; i < x; i++)
		{
			if (curr->next != nullptr)
				curr = curr->next;
			else
			{
				cout << "Max ind is " << i;
				x = -1;
				break;
			}
		}
		if (x != -1)
			cout << curr->inf.info << endl;
		indexing();
	}

	void iddel()
	{
		int x;
		cout << "Enter index(int) : ";
		cin >> x;
		if (head == nullptr)
			cout << "List is empty";
		Node* curr = head;
		Node* buff;
		if (x == 0)
			dellfirst();
		else {
			for (int i = 1; i < x - 1; i++)
			{
				if (curr->next != nullptr)
					curr = curr->next;
				else
				{
					cout << "Max ind is " << i;
					x = -1;
					break;
				}
			}
			if (x != -1) {
				buff = curr->next->next;
				delete curr->next;
				curr->next = buff;
			}
		}
		indexing();
	}

	void getsize()
	{
		if (head == nullptr)
			cout << "It's empty";
		else
		{
			Node* curr = head;
			int x = 0;
			while (curr != nullptr)
			{
				curr = curr->next;
				x++;
			}
			cout << "Size is " << x << endl;
		}
	}

	void delall()
	{
		if (head == nullptr)
			cout << "List is already empty" << endl;
		else
		{
			while(head != nullptr)
			{
				Node* curr = head;
				head = head->next;
				delete curr;
			}
		}
	}

	void dunnoind()
	{
		int ind;
		int newvalue;
		if (head == nullptr)
			cout << "List is empty";
		else {
			cout << "Enter index to change: ";
			cin >> ind;
			cout << "Enter new value: ";
			cin >> newvalue;
			Node* curr = head;
			for (int i = 1; i < ind; i++)
			{
				if (curr->next != nullptr)
					curr = curr->next;
				else
				{
					cout << "Max ind is " << i;
					ind = -1;
					break;
				}
			}
			if (ind != -1)
			{
				curr->inf.info = newvalue;
			}
		}
	}

	void isempty()
	{
		if (head == nullptr)
			cout << "List is emty";
	}

	void changing()
	{
		if (head == nullptr and head->next == nullptr)
			cout << "Not enough nods\n";
		else
		{
			int ind1, ind2;
			cout << "Enter first index u want to change\n";
			cin >> ind1;
			cout << "Enter second index u want to change\n";
			cin >> ind2;
			if (ind1 == ind2)
			{
				out();
			}
			else {
				Node* curr = head;
				Node* buff = nullptr;
				Node* buff2 = nullptr;
				Node* buff3 = nullptr;
				while (curr->next != nullptr)
				{
					if (curr->next->index == ind1)
					{
						buff = curr;
						curr = curr->next;
						break;
					}
					if (curr->next->index == ind2)
					{
						buff = curr;
						curr = curr->next;
						break;
					}
					curr = curr->next;
				}
				while (curr->next != nullptr)
				{
					if (curr->next->index == ind1)
					{
						if (abs(ind1 - ind2) > 1)
						{
							buff2 = buff->next;
							buff3 = curr->next->next;
							buff->next = curr->next;
							buff->next->next = buff2->next;
							buff2->next = buff3;
							curr->next = buff2;
							break;
						}
						else 
						{
							buff2 = buff->next;
							buff3 = curr->next->next;
							buff->next = curr->next;
							curr->next->next = buff2;
							buff2->next = buff3;
							break;
						}
					}
					if (curr->next->index == ind2)
					{
						if (abs(ind1 - ind2) > 1)
						{
							buff2 = buff->next;
							buff3 = curr->next->next;
							buff->next = curr->next;
							buff->next->next = buff2->next;
							buff2->next = buff3;
							curr->next = buff2;
							break;
						}
						else 
						{
							buff2 = buff->next;
							buff3 = curr->next->next;
							buff->next = curr->next;
							curr->next->next = buff2;
							buff2->next = buff3;
							break;
						}
					}
					curr = curr->next;
				}
			}
		}
		indexing();
	}
	List()
	{
		head = nullptr;
	}

};


void main()
{
	List List1;
	
	for (int i = 0; i < 10; i++)
		List1.addend();
	int a;
start:
	cout << "Choose operateion:\n0)add at the end\n1)add to top\n2)delete last\n3)delete first\n4)add by id\n5)cout by id\n6)delete by id\n7)get size of list\n"
		<< "8)delete list\n9)replacing by id\n10)emptiness test\n11)swap by index \n";
	cin >> a;
	switch (a) {
	case 0:
		List1.out();
		List1.addend();
		List1.out();
		break;
	case 1:
		List1.out();
		List1.addbeg();
		List1.out();
		break;
	case 2:
		List1.out();
		List1.dellast();
		List1.out();
		break;
	case 3:
		List1.out();
		List1.dellfirst();
		List1.out();
		break;
	case 4:
		List1.out();
		List1.idin();
		List1.out();
		break;
	case 5:
		List1.out();
		List1.idout();
		List1.out();
		break;
	case 6:
		List1.out();
		List1.iddel();
		List1.out();
		break;
	case 7:
		List1.out();
		List1.getsize();
		break;
	case 8:
		List1.out();
		List1.delall();
		List1.out();
		break;
	case 9:
		List1.out();
		List1.dunnoind();
		List1.out();
		break;
	case 10:
		List1.out();
		List1.isempty();
		List1.out();
		break;
	case 11:
		List1.out();
		List1.changing();
		List1.out();
		break;
	}
	goto start;
}