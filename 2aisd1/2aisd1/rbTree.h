#pragma once
class rbNode {
public:
	int data;
	rbNode* r;
	rbNode* l;
	rbNode* parent;
	bool red;
	rbNode(int data, bool red, rbNode* parent = nullptr, rbNode* r = nullptr, rbNode* l = nullptr)
	{
	}
	rbNode()
	{}
};

class rbTree {
public:
	rbNode* root = nullptr;
	void add(int data);
	void rbBalance(rbNode* curr);
	void leftRotate(rbNode* inp);
	void rightRotate(rbNode* inp);
};

void RBTree(int arr[], int treeSize);
