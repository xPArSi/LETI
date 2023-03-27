#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <time.h>
#include <queue>
#include <ctime>

using namespace std;
using namespace sf;

Clock tick;
Time time1;
double rbTime = 0.0;

class rbNode {
public:
	int data;
	rbNode* r;
	rbNode* l;
	rbNode* parent;
	bool red;
	int height;
	rbNode(int height,int data, bool red, rbNode* parent = nullptr, rbNode* r = nullptr, rbNode* l = nullptr)
	{
		this->height = height;
		this->data = data;
		this->red = red;
		this->parent = parent;
	}
	rbNode()
	{}
};

class rbTree {
public:
	rbNode* root = nullptr;
	rbNode* getRoot()
	{
		return root;
	}
	void add(int data)
	{
		
		if (root == nullptr)
		{
			root = new rbNode(0, data, false);
			root->parent = nullptr;
		}
		else
		{
			rbNode* buff = new rbNode();
			rbNode* curr = getRoot();
			buff->data = data;
			while (curr != nullptr)
			{
				if (curr->data > data)
				{
					if (curr->l == nullptr)
					{
						curr->l = buff;
						buff->red = true;
						buff->height = curr->height + 1;
						buff->parent = curr;
						break;
					}
					else
						curr = curr->l;
				}
				else
				{
					if (curr->r == nullptr)
					{
						curr->r = buff;
						buff->red = true;
						buff->height = curr->height + 1;
						buff->parent = curr;
						break;
					}
					else
						curr = curr->r;
				}
			}
			rbBalance(buff);
		}
	}
	void rbBalance(rbNode* curr)
	{
		
		while (curr->parent->red)
		{
			rbNode* grparent = curr->parent->parent;
			rbNode* uncle = getRoot();
			if (curr->parent == grparent->l)
			{
				if (grparent->r)
					uncle = grparent->r;
				if (uncle->red)
				{
					curr->parent->red = false;
					uncle->red = false;
					grparent->red = true;
					if (grparent->data != root->data)
						curr = grparent;
					else 
					{
						//rbTime += time1.asSeconds();
						break;
					}
				}
				else if (curr == grparent->l->r)
					leftRotate(curr->parent);
				else
				{
					curr->parent->red = false;
					grparent->red = true;
					rightRotate(grparent);
					if (grparent->data != root->data)
						curr = grparent;
					else
					{
						//rbTime += time1.asSeconds();
						break;
					}
				}
			}
			else
			{
				if (grparent->l)
					uncle = grparent->l;
				if (uncle->red)
				{
					curr->parent->red = false;
					uncle->red = false;
					grparent->red = true;
					if (grparent->data != root->data)
						curr = grparent;
					else
					{
						//rbTime += time1.asSeconds();
						break;
					}
				}
				else if (curr == grparent->r->l)
					rightRotate(curr->parent);
				else
				{
					curr->parent->red = false;
					grparent->red = true;
					leftRotate(grparent);
					if (grparent->data != root->data)
						curr = grparent;
					else
					{
						//rbTime += time1.asSeconds();
						break;
					}
				}
			}
		}
		root->red = false;
	}

	void leftRotate(rbNode* inp)
	{
		clock_t begin = clock();
		rbNode* buff = new rbNode();
		if (inp->r->l)
			buff->r = inp->r->l;
		buff->l = inp->l;
		buff->data = inp->data;
		buff->red = inp->red;
		inp->data = inp->r->data;
		inp->red = inp->r->red;
		inp->l = buff;
		if (buff->l)
			buff->l->parent = buff;
		if (buff->r)
			buff->r->parent = buff;
		buff->parent = inp;
		if (inp->r->r)
			inp->r = inp->r->r;
		else
			inp->r = nullptr;
		if (inp->r)
			inp->r->parent = inp;
		clock_t end = clock();
		rbTime += (double)(end - begin) / CLOCKS_PER_SEC;
	}

	void rightRotate(rbNode* inp)
	{
		clock_t begin = clock();
		rbNode* buff = new rbNode();
		if (inp->l->r)
			buff->l = inp->l->r;
		buff->r = inp->r;
		buff->data = inp->data;
		buff->red = inp->red;
		inp->data = inp->l->data;
		inp->red = inp->l->red;
		inp->r = buff;
		if (buff->l)
			buff->l->parent = buff;
		if (buff->r)
			buff->r->parent = buff;
		buff->parent = inp;
		if (inp->l->l)
			inp->l = inp->l->l;
		else
			inp->l = nullptr;
		if (inp->l)
			inp->l->parent = inp;
		clock_t end = clock();
		rbTime += (double)(end - begin) / CLOCKS_PER_SEC;
	}
	int maxHeight = 0;
	void heightCount(rbNode*head)
	{
		if (!head)
			return;
		heightCount(head->l);
		heightCount(head->r);
		if (head->height > maxHeight)
			maxHeight = head->height;
	}
};

void RBTree(int arr[], int treeSize)
{
	srand(time(NULL));
	time1 = tick.getElapsedTime();
	rbTree test;
	
	for (int i = 0; i < treeSize; i++)
	{
		test.add(arr[i]);
		//cout << i << endl;
	}

	test.heightCount(test.root);
	cout << "rb height " << test.maxHeight << endl;
	cout << "rb time " << rbTime << endl;
}