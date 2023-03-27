#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <time.h>
#include <queue>
#include "binTree.h"
#include "rbTree.h"
#include "avlTree.h"

using namespace std;
using namespace sf;

const int treeSize = 200000;
int arr[treeSize]{ 0 };




void main()
{
	srand(time(NULL));
	int smth = rand() % treeSize;
	for (int i = 0; i < treeSize; i++)
	{
		arr[i] = smth + i;
		//cout << i << endl;
	}
	for (int i = treeSize - 1; i >= 1; i--)
	{
		int j = rand() % (i + 1);
		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
		//cout << i << endl;
	}
	cout << "Tree size is: " << treeSize << endl;
	BinTree(arr, treeSize);
	RBTree(arr, treeSize);
	avlTree(arr, treeSize);
}