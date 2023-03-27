#pragma once

using namespace sf;


class node {
public:
	int data;
	bool red;
	node* r;
	node* l;
	Text txt;
	int x, y, dist;
	int height;
	node(int x, int y, int dist, int data, int height, bool red = NULL, node* r = nullptr, node* l = nullptr)
	{
	}
};

class binTree {
public:
	node* root = nullptr;

	void add(int data);
	int maxHeight;
	void heightCount(node*head);
};

//void bFs(node* head);
void BinTree(int arr[], int treeSize);