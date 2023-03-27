//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <Windows.h>
//#include <queue>
//#include <stack>
//#include <time.h>
//
//using namespace std;
//using namespace sf;
//
//int dist = 200;
//double scale = 1.2;
//int radius = 30;
//Font font;
//bool scaleFlag1 = true;
//bool scaleFlag2 = true;
//int maxtree = 0;
//int mintree = INT_MAX;
//
//
//class node {
//public:
//	friend SFML_GRAPHICS_API CircleShape;
//	friend SFML_GRAPHICS_API Vertex;
//	int data;
//	node* r; // right
//	node* l; // left
//	CircleShape circle;
//	Text text;
//	Vertex line[2];
//	Vertex line2[2];
//	int x;
//	int y;
//	int dist;
//	double scalen;
//	int hight;
//	bool red;
//	node(bool more, int value, int x1, int y1, int dist, double a, int hight = 1,bool red = false, node* r = nullptr, node* l = nullptr)
//	{
//		this->r = r;
//		this->l = l;
//		this->data = value;
//		this->dist = dist / 1.2;
//		if (a - 0.5 >= 0.5)
//		{
//			scalen = a - 0.5;
//		}
//		else
//			scalen = a;
//		circle.setRadius(radius);
//		if (red)
//			circle.setFillColor(Color::Red);
//		else
//			circle.setFillColor(Color::Black);
//		if (more)
//		{
//			if (scaleFlag1)
//			{
//				x = x1 + dist * a + 100;
//				y = y1 + dist / 3;
//				scaleFlag1 = false;
//			}
//			else
//			{
//				x = x1 + dist * a;
//				y = y1 + dist;
//			}
//		}
//		else
//		{
//			if (scaleFlag2)
//			{
//				x = x1 - dist * a - 100;
//				y = y1 + dist / 3;
//				scaleFlag2 = false;
//			}
//			else
//			{
//				x = x1 - dist * a;
//				y = y1 + dist;
//			}
//		}
//		circle.setPosition(x, y);
//		text.setFont(font);
//		text.setCharacterSize(30);
//#pragma warning(suppress : 4996)
//		text.setColor(Color::White);
//		string str;
//		str = to_string(hight);
//		text.setString(str);
//	}
//};
//
//class root {
//public:
//	node* head = nullptr;
//	void add(int value, RenderWindow& window)
//	{
//		int counter = 2;
//		if (head == nullptr)
//		{
//			head = new node(true, value, window.getSize().x / 2 - dist * 2 - 100, 0 - dist / 3, dist, 2, 1, false);
//			if (value / 10 == 0)
//				head->text.setPosition(head->x + radius / 2 + 7, head->y + radius / 2 - 3);
//			else
//				head->text.setPosition(head->x + radius / 2 + 7 - 10, head->y + radius / 2 - 3);
//			scaleFlag1 = true;
//		}
//		else
//		{
//			node* curr = head;
//			while (1)
//			{
//				
//				if (value > curr->data)
//				{
//					if (curr->r == nullptr)
//					{
//						curr == head ? scaleFlag1 = true : scaleFlag1 = false;
//						curr->r = new node(true, value, curr->x, curr->y, curr->dist, curr->scalen, counter);
//						Vertex line[2] =
//						{
//							Vertex(Vector2f(curr->x + radius,curr->y + radius)),
//							Vertex(Vector2f(curr->r->x + radius,curr->r->y + radius))
//						};
//						curr->line[0].position.x = curr->x + radius;
//						curr->line[0].position.y = curr->y + radius;
//						curr->line[1].position.x = curr->r->x + radius;
//						curr->line[1].position.y = curr->r->y + radius;
//						curr->line->color = Color::Green;
//						if (value / 10 == 0)
//							curr->r->text.setPosition(curr->r->x + radius / 2 + 7, curr->r->y + radius / 2 - 3);
//						else
//							curr->r->text.setPosition(curr->r->x + radius / 2 + 7 - 10, curr->r->y + radius / 2 - 3);
//						break;
//					}
//					else
//					{
//						curr = curr->r;
//						counter++;
//					}
//				}
//				if (value < curr->data)
//				{
//					if (curr->l == nullptr)
//					{
//						curr == head ? scaleFlag2 = true : scaleFlag2 = false;
//						curr->l = new node(false, value, curr->x, curr->y, curr->dist, curr->scalen, counter);
//						curr->line2[0].position.x = curr->x + radius;
//						curr->line2[0].position.y = curr->y + radius;
//						curr->line2[1].position.x = curr->l->x + radius;
//						curr->line2[1].position.y = curr->l->y + radius;
//						curr->line2->color = Color::Green;
//						if (value / 10 == 0)
//							curr->l->text.setPosition(curr->l->x + radius / 2 + 7, curr->l->y + radius / 2 - 3);
//						else
//							curr->l->text.setPosition(curr->l->x + radius / 2 + 7 - 10, curr->l->y + radius / 2 - 3);
//						break;
//					}
//					else
//					{
//						curr = curr->l;
//						counter++;
//					}
//				}
//			}
//		}
//	}
//
//	void minmax()
//	{
//		if (head != nullptr)
//		{
//			node* curr = head;
//			while (curr->r != nullptr)
//				curr = curr->r;
//			cout << "max = " << curr->data;
//			curr = head;
//			while (curr->l != nullptr)
//				curr = curr->l;
//			cout << "min = " << curr->data;
//		}
//		else
//			cout << "Root is empty";
//	}
//
//	void preOrder(node* head, RenderWindow& window) {
//		if (!head) { return; }
//
//		preOrder(head->l, window);
//		preOrder(head->r, window);
//		window.draw(head->line, 2, Lines);
//		window.draw(head->line2, 2, Lines);
//		window.draw(head->circle);
//		window.draw(head->text);
//	}
//
//	node* find(node* head, int key)
//	{
//		if (head == NULL)
//		{
//			return NULL;
//		}
//		if (head->data == key)
//		{
//			return head;
//		}
//
//		if (key <= head->data)
//		{
//
//			if (head->l != NULL)
//				return find(head->l, key);
//			else
//			{
//				return NULL;
//			}
//		}
//		else
//		{
//
//			if (head->r != NULL)
//				return find(head->r, key);
//			else
//			{
//				return NULL;
//			}
//		}
//	}
//	node* findPrev(node* head, int key)
//	{
//		if (head == NULL)
//		{
//			return NULL;
//		}
//		if (head->l->data == key || head->r->data == key)
//		{
//
//			return head;
//		}
//
//		if (key <= head->data)
//		{
//
//			if (head->l != NULL)
//				return find(head->l, key);
//			else
//			{
//				return NULL;
//			}
//		}
//		else
//		{
//
//			if (head->r != NULL)
//				return find(head->r, key);
//			else
//			{
//				return NULL;
//			}
//		}
//	}
//	node* findNext(node* head, int key)
//	{
//		node* ans;
//		if (head == NULL)
//		{
//			return NULL;
//		}
//		if (head->data == key)
//		{
//			if (head->l != nullptr) {
//				ans->l = head->l;
//			}
//			if (head->r != nullptr) {
//				ans->r = head->r;
//			}
//			return ans;
//		}
//
//		if (key <= head->data)
//		{
//
//			if (head->l != NULL)
//				return findNext(head->l, key);
//			else
//			{
//				return NULL;
//			}
//		}
//		else
//		{
//
//			if (head->r)
//				return findNext(head->r, key);
//			else
//			{
//				return NULL;
//			}
//		}
//	}
//
//	node* delNode(node * head, int inp) {
//
//		if (head == NULL)
//			return head;
//
//		if (inp == head->data) {
//
//			node* tmp;
//
//			if (head->r == NULL)
//				tmp = head->l;
//
//			else {
//
//				node* ptr = head->r;
//
//				if (ptr->l == NULL) {
//					ptr->l = head->l;
//					tmp = ptr;
//				}
//
//				else {
//
//					node* ptrmin = ptr->l;
//					while (ptrmin->l != NULL) {
//						ptr = ptrmin;
//						ptrmin = ptr->l;
//					}
//					ptr->l = ptrmin->r;
//					ptrmin->l = head->l;
//					ptrmin->r = head->r;
//					tmp = ptrmin;
//				}
//
//			}
//
//			delete head;
//			return tmp;
//		}
//
//		else if (inp < head->data)
//			head->l = delNode(head->l, inp);
//
//		else
//			head->r = delNode(head->r, inp);
//
//		return head;
//	}
//
//	void preOrderMax(node* head, node* shead, RenderWindow& window)
//	{
//		if (!head) { return; }
//		preOrderMax(head->l, shead, window);
//		preOrderMax(head->r, shead, window);
//		head->circle.setOutlineThickness(5);
//		head->circle.setOutlineColor(Color::Blue);
//		window.clear(Color(30, 30, 30, 2));
//		preOrder(shead, window);
//		window.display();
//		Sleep(1000);
//
//		if (head->data >= maxtree)
//		{
//			if (maxtree != 0)
//				find(shead, maxtree)->circle.setOutlineThickness(0);
//			maxtree = head->data;
//			head->circle.setOutlineColor(Color::Red);
//		}
//		else
//			head->circle.setOutlineThickness(0);
//
//		preOrder(shead, window);
//		window.display();
//
//	}
//	void postOrderMin(node* head, node* shead, RenderWindow& window)
//	{
//		if (!head) { return; }
//
//		head->circle.setOutlineThickness(5);
//		head->circle.setOutlineColor(Color::Blue);
//		window.clear(Color(30, 30, 30, 2));
//		preOrder(shead, window);
//		window.display();
//		Sleep(1000);
//
//		if (head->data <= mintree)
//		{
//			if (mintree != INT_MAX)
//				find(shead, mintree)->circle.setOutlineThickness(0);
//			mintree = head->data;
//			head->circle.setOutlineColor(Color::Red);
//		}
//		else
//			head->circle.setOutlineThickness(0);
//
//		preOrder(shead, window);
//		window.display();
//		postOrderMin(head->l, shead, window);
//		postOrderMin(head->r, shead, window);
//	}
//	void inOrderMinMax(node* head, node* shead, RenderWindow& window)
//	{
//		if (!head) { return; }
//		inOrderMinMax(head->l, shead, window);
//		head->circle.setOutlineThickness(5);
//		head->circle.setOutlineColor(Color::Blue);
//		window.clear(Color(30, 30, 30, 2));
//		preOrder(shead, window);
//		window.display();
//		Sleep(1000);
//		if (head->data >= maxtree || head->data <= mintree)
//		{
//			if (head->data >= maxtree)
//			{
//				if (maxtree != 0)
//					find(shead, maxtree)->circle.setOutlineThickness(0);
//				maxtree = head->data;
//				head->circle.setOutlineColor(Color::Red);
//			}
//			if (head->data <= mintree)
//			{
//				if (mintree != INT_MAX)
//					find(shead, mintree)->circle.setOutlineThickness(0);
//				mintree = head->data;
//				head->circle.setOutlineColor(Color::Red);
//			}
//		}
//		else
//			head->circle.setOutlineThickness(0);
//		find(shead, mintree)->circle.setOutlineThickness(5);
//		find(shead, maxtree)->circle.setOutlineThickness(5);
//		preOrder(shead, window);
//		window.display();
//		inOrderMinMax(head->r, shead, window);
//	}
//};
//
//
//void main()
//{
//	Text text;
//	font.loadFromFile("arial.ttf");
//
//	root test;
//	RenderWindow window(VideoMode(1800, 1000), "Root");
//	window.clear(Color(30, 30, 30, 2));
//	int value;
//	//cout << "Enter 10 nodes: \n";
//	for (int i = 0; i < 10; i++)
//	{
//		value = rand();
//		test.add(value, window);
//	}
//	cout << "Choose what do you want to do: \n 1) preOrder find max \n 2) postOrder find min \n 3) inOrder find min and max \n 4) delete node \n";
//	bool flagg = true;
//	int x = 0;
//
//	//test.minmax();
//	int flag = 0;
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//		}
//		window.clear(Color(30, 30, 30, 2));
//		test.preOrder(test.head, window);
//		if (flag == 0)
//			switch (x)
//			{
//			case(1):
//				test.preOrderMax(test.head, test.head, window);
//				flag = 1;
//				break;
//			case(2):
//				test.postOrderMin(test.head, test.head, window);
//				flag = 1;
//				break;
//			case(3):
//				test.inOrderMinMax(test.head, test.head, window);
//				flag = 1;
//				break;
//			case(4):
//				int z;
//				cout << "Which one do you want to delete? \n";
//				cin >> z;
//				test.delNode(test.head, z);
//				flag = 1;
//				break;
//			}
//
//		window.display();
//		if (flagg)
//		{
//			cin >> x;
//			flagg = false;
//		}
//	}
//}