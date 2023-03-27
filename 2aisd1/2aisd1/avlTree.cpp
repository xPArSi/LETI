#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <time.h>
#include <queue>
#include <ctime>

using namespace std;
using namespace sf;
class aNode;
Clock tick1;
Time time2;
void fixH(aNode* inp);
int bfact(aNode* inp);
double avlTime = 0.0;

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
		this->data = data;
	}
};

aNode* rightRotate(aNode* inp)
{
	clock_t begin = clock();
	aNode* buff = inp->l;
	inp->l = buff->r;
	buff->r = inp;
	fixH(inp);
	fixH(buff);
	clock_t end = clock();
	avlTime += (double)(end - begin) / CLOCKS_PER_SEC;
	return buff;
}

aNode* leftRotate(aNode* inp)
{
	clock_t begin = clock();
	aNode* buff = inp->r;
	inp->r = buff->l;
	buff->l = inp;
	fixH(inp);
	fixH(buff);
	clock_t end = clock();
	avlTime += (double)(end - begin) / CLOCKS_PER_SEC;
	return buff;
}

aNode* balance(aNode* inp)
{
	
	fixH(inp);
	//clock_t begin = clock();
	if (bfact(inp) == 2)
	{
		//clock_t begin = clock();
		if (bfact(inp->r) < 0)
			inp->r = rightRotate(inp->r);
		//clock_t end = clock();
		//avlTime += (double)(end - begin) / CLOCKS_PER_SEC;
		return leftRotate(inp);
	}
	if (bfact(inp) == -2)
	{
		
		if (bfact(inp->l) > 0)
			inp->l = leftRotate(inp->l);
		
		return rightRotate(inp);
	}
	//clock_t end = clock();
	//avlTime += (double)(end - begin) / CLOCKS_PER_SEC;
	return inp;
}

aNode* add(aNode* inp, int data)
{
	if (!inp)
		return new aNode(data);
	if (data < inp->data)
		inp->l = add(inp->l, data);
	else
		inp->r = add(inp->r, data);
	return balance(inp);
}

int height(aNode* inp)
{
	return inp ? inp->height : 0;
}

int bfact(aNode* inp)
{
	return height(inp->r) - height(inp->l);
}

void fixH(aNode* inp)
{
	int l = height(inp->l);
	int r = height(inp->r);
	inp->height = (l > r ? l : r) + 1;
}

int counter = 0;
int maxHeight = 0;

void heightCount(aNode*head)
{
	if (!head)
	{
		counter > maxHeight ? maxHeight = counter : 0;
		counter--;
		return;
	}
	counter++;
	heightCount(head->l);
	heightCount(head->r);
}

void avlTree(int arr[], int treeSize)
{
	srand(time(NULL));
	time2 = tick1.getElapsedTime();
	aNode* AVLTree = nullptr;
	
	for (int i = 0; i < treeSize; i++)
	{
		AVLTree = add(AVLTree, arr[i]);
	}
	
	heightCount(AVLTree);
	cout << "avl height " << maxHeight << endl;
	cout << "avl time " << avlTime << endl;
}