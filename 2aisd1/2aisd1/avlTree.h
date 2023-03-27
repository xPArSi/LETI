#pragma once
class aNode
{
public:
	int data;
	int height;
	aNode* r;
	aNode* l;
	bool visited;
	aNode(int data)
	{
	}
	aNode* rightRotate(aNode* inp);
	aNode* leftRotate(aNode* inp);
	aNode* balance(aNode* inp);
	aNode* add(aNode* inp, int data);
	
};

int height(aNode* inp);
int bfact(aNode* inp);
void fixH(aNode* inp);
void avlTree(int arr[], int treeSize);
