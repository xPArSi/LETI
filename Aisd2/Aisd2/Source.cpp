#include <iostream>
#include <algorithm>
#include <cmath>
#include <conio.h>
#include <time.h>

using namespace std;

double mindist = 100000000;
int X1 = 0, X2 = 0, Y1 = 0, Y2 = 0;
const int N = 10;

class snail {
public:
	int x, y;
};

bool sortx(snail a, snail b) // X sorting condition
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}


bool sorty(const snail& a, const snail& b) // Y sorting condition
{
	return a.y < b.y;
}

double dist(snail a, snail b) // Getting the distation
{
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void new_ans(snail a, snail b) // Checking if answer is better
{
	double dist1 = dist(a,b);
	if (dist1 < mindist)
	{
		mindist = dist1;
		X1 = a.x;
		Y1 = a.y;
		X2 = b.x;
		Y2 = b.y;
	}
}

void rec(int left, int right, snail* a)
{
	if (right - left <= 2)
	{
		for (int i = left; i <= right; i++)
			for (int j = i + 1; j <= right; j++)
			{
				new_ans(a[i], a[j]);
			}
		/*for (int k = 0; k < N; k++)
			cout << a[k].x << " " << a[k].y << endl;
		cout << endl;*/
		sort(a + left, a + right + 1, &sorty);
		return;
	}

	int mid = (left + right) / 2;
	int midx = a[mid].x;
	rec(left, mid, a);
	rec(mid + 1, right, a);
	/*for (int i = 0; i < N; i++)
		cout << a[i].x << " " << a[i].y << endl;
	cout << endl;*/
	snail* buff = new snail[N];
	merge(a + left, a + mid + 1, a + mid + 1, a + right + 1, buff, &sorty);
	//for (int i = 0; i < N; i++)
	//	cout << buff[i].x << " " << buff[i].y << endl;
	//cout << endl;
	copy(buff, buff + right - left + 1, a + left);
	/*for (int i = 0; i < N; i++)
		cout << buff[i].x << " " << buff[i].y << endl;
	cout << endl;*/
	
	int counter = 0;
	for (int i = left; i <= right; i++)
		if (abs(a[i].x - midx) < mindist)
		{
			for (int j = counter - 1; j >= 0 && (a[i].y - mindist < buff[j].y); j--)
				new_ans(a[i], buff[j]);
			buff[counter++] = a[i];
		}

}

int main() {
	srand(time(NULL));
	snail a[N];
	for (int i = 0; i < N; i++)
	{
		a[i].x = rand() % 100;
		a[i].y = rand() % 100;
	}

	/*for (int i = 0; i < N; i++)
		cout << a[i].x << " " << a[i].y << endl;

	cout << endl;*/
	sort(a, a + size(a), &sortx);
	
	/*for (int i = 0; i < N; i++)
		cout << a[i].x << " " << a[i].y << endl;
	cout << endl;*/
	rec(0, size(a) - 1, a);
	/*for (int i = 0; i < N; i++)
		cout << a[i].x << " " << a[i].y << endl;
	cout << endl;*/
	//cout << "Snails coordinates are (" << X1 << ", " << Y1 << ") and (" << X2 << ", " << Y2 << ")\n";

	double time = (mindist / 2) / 0.01;

	cout << "The time before their meeting is " << time << " seconds" << endl;

}