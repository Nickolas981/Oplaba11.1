#include<iostream>
//#include<fstream>
//#include<vector>
//#include<string>
#include"Heap.h"

using namespace std;
//void wordCount();
//void read();
//void bubbleSort();
//struct node;
//void print_Tree(node *p, int level);

//struct node {
//	int key;
//	int counter;
//	string  word; 
//	node *l = NULL,
//		 *r = NULL;
//
//};
//vector<pair<string, int>> vec;
void print_Tree(node * p, int level);
//void push(string data, int key,int counter, node *&t)
//{
//
//	if (t == NULL )
//	{
//		t = new node;
//		t->key = key;
//		t->word = data;
//		t->counter = counter;
//		t->l = t->r = NULL;
//		return;
//	}
//	if (key>t->key)
//		push(data, key,counter, t->r);
//	else
//		push(data, key,counter, t->l);
//}
void main() {	
	read();	
	bubbleSort();	
	Heap h = circle();
	h.outHeap();
	system("pause");
}
//void read() {
//	bool flag = false;
//	pair<string, int> buff;
//	if (in >> buff.first) {
//		buff.second = 1;
//		vec.push_back(buff);
//	}
//	while (in>>buff.first)
//	{
//			for (int i = 0; i < vec.size(); i++)
//				if (vec[i].first == buff.first) {
//					flag = true;
//					vec[i].second++;
//				}
//			if (flag == false)
//			{
//				buff.second = 1;
//				vec.push_back(buff);
//			}
//			flag = false;
//	}
//}
//
//
//void print_Tree(node *p, int level)
//{
//	if (p)
//	{
//		print_Tree(p->l, level + 1);
//		for (int i = 0; i< level; i++) cout << "   ";
//		cout << p->counter << ":";		
//		cout << p->word;
//		print_Tree(p->r, level + 1);
//	}
//}
//void bubbleSort() 
//{
//	pair<string, int> buff; 
//	bool exit = false; 
//	while (!exit) 
//	{
//		exit = true;
//		for (int i = 0; i < (vec.size() - 2); i++)																				   //сортировка пузырьком по убыванию - знак <
//			if (vec[i].second < vec[i+1].second)
//			{
//				buff = vec[i];
//				vec[i] = vec[i + 1];
//				vec[i + 1] = buff;
//				exit = false; 
//			}
//	}
//}
