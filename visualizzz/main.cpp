#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <cstdlib>

using namespace std;
using namespace sf;

int arysize = 1200;
int width = 1;



class node
{
	friend SFML_GRAPHICS_API RectangleShape;
public:
	int x;
	int y;
	RectangleShape rect;
	node()
	{
		x = 0;
		y = 0;
	}
};

bool searching(node* ary, int y)
{
	for (int i = 0; i < arysize; i++)
	{
		if (y == ary[i].y)
			return true;
	}
	return false;
}

void fillin(node* ary)
{
	int randomed{ 0 };
	for (int i = 0; i < arysize; i++)
	{
		ary[i].x = i + 1;
		while (searching(ary, randomed))
		{
			randomed = 1 + rand() % arysize;
		}
		ary[i].y = randomed;
	}
}

bool stop(node* ary)
{
	for (int i = 0; i < arysize; i++)
	{
		if (ary[i].x != ary[i].y)
			return false;
	}
	return true;
}

void bubble(node* ary)
{
	int bubblik{ 0 };
	for (int i = 0; i < arysize-1; i++)
	{
		if (ary[i].y >= ary[i + 1].y)
		{
			bubblik = ary[i].y;
			ary[i].y = ary[i + 1].y;
			ary[i + 1].y = bubblik;
		}
	}
}

int minmin = 0;
int mincounter = 0;

void smin(node* ary)
{
	if (stop(ary) != true)
	{
		int mini = 10000;
		int save = 0;
		int savei = 0;
		for (int i = 0; i < arysize; i++)
		{
			if (mini > ary[i].y && minmin < ary[i].y)
			{
				mini = ary[i].y;
				save = i;
			}
		}
		savei = ary[mincounter].y;
		ary[mincounter++].y = mini;
		ary[save].y = savei;
		minmin = mini;
	}
}

int maxmax = 10000;
int maxcounter = arysize-1;

void smax(node* ary)
{
	if (stop(ary) != true)
	{
		int maxi = 0;
		int save = 0;
		int savei = 0;
		for (int i = 0; i < arysize; i++)
		{
			if (maxi < ary[i].y && maxmax > ary[i].y)
			{
				maxi = ary[i].y;
				save = i;
			}
		}
		savei = ary[maxcounter].y;
		ary[maxcounter--].y = maxi;
		ary[save].y = savei;
		maxmax = maxi;
	}
}

void stupid(node* ary)
{
	int flag{ 0 };
	int save = 0;
	int savei = 0;
	for (int i = 0; i < arysize; i++)
	{
		if (ary[i].y != ary[i].x && flag != 1)
		{
			save = ary[i].y;
			savei = i;
			flag = 1;
		}
		if (save == ary[i].x)
		{
			ary[savei].y = ary[i].y;
			ary[i].y = save;
		}
	}
}

void Shaker(node* ary)
{
	int buff;
	int left = 1;
	int right = arysize - 1;
	for (int i = right; i >= left; i--)
	{
		if (ary[i - 1].y > ary[i].y)
		{
			buff = ary[i].y;
			ary[i].y = ary[i - 1].y;
			ary[i - 1].y = buff;
		}
	}
	left++;
	for (int i = left; i <= right; i++)
	{
		if (ary[i - 1].y > ary[i].y)
		{
			buff = ary[i].y;
			ary[i].y = ary[i - 1].y;
			ary[i - 1].y = buff;
		}
	}
	right++;
}

void notEvenAsort(node* ary)
{
	for (int i = 0; i < arysize; i++)
	{
		if (ary[i].y != ary[i].x)
		{
			ary[i].y = ary[i].x;
			break;
		}
	}
}

//int counter = 0;

void insertionsort(node* ary, int numofenterings)
{
	int buffy = 0;
	for (int j = numofenterings; j > 0 && ary[j - 1].y > ary[j].y; j--)
	{
		swap(ary[j - 1].y, ary[j].y);
		/*buffy = ary[j].y;
		ary[j].y = ary[j - 1].y;
		ary[j - 1].y = buffy;*/
	}
}

void selectionsort(node* ary, int numofenterings)
{
	int min = numofenterings;
	for (int i = numofenterings + 1; i < arysize; i++)
	{
		if (ary[i].y < ary[min].y) min = i;
	}
	if (numofenterings != min)
	{
		swap(ary[numofenterings].y, ary[min].y);
	}
}

node* buff= new node[arysize];


void merge(node* ary, int l, int r, int m, RenderWindow& window)
{
	int i, j, k;
	
	i = l;
	k = l;
	j = m + 1;
	while (i <= m && j <= r)
	{
		if (ary[i].y < ary[j].y)
		{
			buff[k].y = ary[i].y;
			k++;
			i++;
		}
		else
		{
			buff[k].y = ary[j].y;
			k++;
			j++;
		}
	}
	while (i <= m)
		buff[k++].y = ary[i++].y;
	while (j <= r)
		buff[k++].y = ary[j++].y;
	for (i = l; i < k; i++)
		ary[i].y = buff[i].y;

}

void mergesort(node* ary, int l, int r, RenderWindow& window, int numofenterings)
{
	int m;
	
	if (l < r)
	{
		m = (l + r) / 2;
		mergesort(ary, l, m, window, numofenterings);
		mergesort(ary, m + 1, r, window, numofenterings);
		merge(ary, l, r, m, window);
		window.clear(Color(30, 30, 30, 2));
		for (int i = 0; i < arysize; i++)
		{
			ary[i].rect.setSize(Vector2f(width, -ary[i].y / 2));
			ary[i].rect.setPosition(Vector2f(250 + ary[i].x, 950));
			window.draw(ary[i].rect);
		}
		window.display();
	}
}

void shellsort(node* ary, RenderWindow& window)
{
	int buff, j;
	for (int step = arysize / 2; step > 0; step /= 2)
		for (int i = step; i < arysize; i++)
		{
			buff = ary[i].y;
			for (j = i; j >= step; j -= step)
			{
				if (buff < ary[j - step].y)
					ary[j].y = ary[j - step].y;
				else
					break;
			}
			ary[j].y = buff;
			window.clear(Color(30, 30, 30, 2));
			for (int i = 0; i < arysize; i++)
			{
				ary[i].rect.setSize(Vector2f(width, -ary[i].y / 2));
				ary[i].rect.setPosition(Vector2f(250 + ary[i].x, 950));
				window.draw(ary[i].rect);
			}
			window.display();
		}
}

void quicksort(node* ary, int l, int r, RenderWindow& window)
{
	int left = l;
	int right = r;
	int point = ary[(left + right) / 2].y;
	while (left <= right)
	{
		while (ary[left].y < point)
			left++;
		while (ary[right].y > point)
			right--;
		if (left <= right)
			swap(ary[left++].y, ary[right--].y);
		window.clear(Color(30, 30, 30, 2));
		for (int i = 0; i < arysize; i++)
		{
			ary[i].rect.setSize(Vector2f(width, -ary[i].y / 2));
			ary[i].rect.setPosition(Vector2f(250 + ary[i].x, 950));
			window.draw(ary[i].rect);
		}
		window.display();
	}
	if (l < right)
		quicksort(ary, l, right, window);
	if (r > left)
		quicksort(ary, left, r, window);
}

void out(node* ary)
{
	for (int i = 0; i < arysize; i++)
	{
		cout << ary[i].x << ' ' << ary[i].y << endl;
	}
}



void main()
{
	int numofenterings = 0;
	srand(time(NULL));
	node* ary;
	ary = new node[arysize];
	fillin(ary);
	//out(ary);
	int chose;
	int flag = 0;
	cout << "Chose the sorting type :" << endl;
	cout << "1)Min" << endl << "2)Max" << endl << "3)Minmax(in progress)" << endl << "4)Buble" << endl;
	cout << "5)Stupid" << endl << "6)Shaker" << endl << "7)Not even a sort :D" << endl << "8)Insertion sort" << endl;
	cout << "9)Selection sort" << endl << "10)Merge sort" << endl << "11)Shell sort" << endl << "12)Quick sort" << endl;
	cin >> chose;
	RenderWindow window(VideoMode(1800, 1000), "Sorts");
	while (window.isOpen())
		{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color(30, 30, 30, 2));
		for (int i = 0; i < arysize; i++)
		{
			ary[i].rect.setSize(Vector2f(width, -ary[i].y/2));
			ary[i].rect.setPosition(Vector2f(250+ary[i].x, 950));
			window.draw(ary[i].rect);
		}
		switch (chose)
		{
		default:
			break;
		case(1):
			smin(ary);
			break;
		case(2):
			smax(ary);
			break;
		case(3):
			//minmax(ary);
			break;
		case(4):
			bubble(ary);
			break;
		case(5):
			stupid(ary);
			break;
		case(6):
			Shaker(ary);
			break;
		case(7):
			notEvenAsort(ary);
			break;
		case(8):
			insertionsort(ary, numofenterings);
			break;
		case(9):
			selectionsort(ary, numofenterings);
			break;
		case(10):
			if (flag == 0)
			{
				mergesort(ary, 0, arysize - 1, window, numofenterings); //visualization doesn't work well
				flag = 1;
				break;
			}
			break;
		case(11):
			shellsort(ary, window);
			break;
		case(12):
			quicksort(ary, 0, arysize-1, window);
			break;
		}
		//bubble(ary);
		//smin(ary);
		if (stop(ary) != true)
		{
			numofenterings++;
		}
		/*Font font;
		font.loadFromFile("arial.ttf");
		Text text("", font, 30);
		string g;
		text.setFillColor(Color::White);
		g = "Number of enterings is: ";
		g += to_string(numofenterings);
		text.setString(g);
		window.draw(text);*/ //not working with all sorts
		
		window.display();
	}
}