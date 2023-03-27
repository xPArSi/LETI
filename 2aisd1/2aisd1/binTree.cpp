#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <time.h>
#include <queue>

using namespace std;
using namespace sf;


Font font;


class node {
public:
	int data;
	bool red;
	node* r;
	node* l;
	int height = 0;
	node(int data, int height, bool red = NULL, node* r = nullptr, node* l = nullptr)
	{
		this->data = data;
		this->red = red;
		this->r = r;
		this->l = l;
		this->height = height + 1;
	}
};

class binTree {
public:
	node* root = nullptr;

	void add(int data)
	{
		if (root == nullptr)
		{
			root = new node(data, -1);
		}
		else
		{
			node* curr = root;
			while (1)
			{
				if (data == curr->data)
					break;
				if (data > curr->data)
				{
					if (curr->r == nullptr)
					{
						curr->r = new node(data, curr->height);
						break;
					}
					else
						curr = curr->r;
				}

				if (data < curr->data)
				{
					if (curr->l == nullptr)
					{
						curr->l = new node(data, curr->height);
						break;
					}
					else
						curr = curr->l;
				}

			}
		}
	}
	int maxHeight = 0;
	void heightCount(node*head)
	{
		if (!head)
			return;
		heightCount(head->l);
		heightCount(head->r);
		if (head->height > maxHeight)
			maxHeight = head->height;
	}
};



void BinTree(int arr[],int treeSize)
{
	srand(time(NULL));

	binTree test;
	int value;
	for (int i = 0; i < treeSize; i++)
	{
		value = rand();
		test.add(arr[i]);
		//cout << i << endl;
	}

	font.loadFromFile("arial.ttf");
	test.heightCount(test.root);
	cout << "bin height " << test.maxHeight << endl;
}
