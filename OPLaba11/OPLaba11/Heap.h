#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

//ifstream in;
class Heap {
	int *size;
	static const int SIZE = 100; 
	string *h; 
	int HeapSize; 
public:
	Heap();  
	void addelem(string,int); 
	void outHeap();  
	void out(); 
	int getmax();  
	void heapify(int);
};
struct node {
	int key;
	int counter;
	string  word;
	node *l = NULL,
		*r = NULL;

};
//vector<pair<string, int>> vec;
void read();
void print_Tree(node *p, int level);
void bubbleSort();
void push(string data, int key, int counter, node *&t);
Heap circle();
//Heap::Heap() {
//	size = new  int[SIZE];
//	h = new string[SIZE];
//	HeapSize = 0;
//}
//void Heap::addelem(string n,int s) {
//	int i, parent;
//	i = HeapSize;
//	size[i] = s;
//	h[i] = n;
//	parent = (i - 1) / 2;
//	while (parent >= 0 && i > 0) {
//		if (size[i] > size[parent]) {
//			string temp = h[i];
//			int buf = size[i];
//			size[i] = size[parent];
//			size[parent] = buf;
//			h[i] = h[parent];
//			h[parent] = temp;
//		}
//		i = parent;
//		parent = (i - 1) / 2;
//	}
//	HeapSize++;
//}
//void Heap::outHeap(void) {
//	int i = 0;
//	int k = 1;
//	while (i < HeapSize) {
//		while ((i < k) && (i < HeapSize)) {
//			cout << h[i] << ":" << size[i] << " ";
//			i++;
//		}
//		cout << endl;
//		k = k * 2 + 1;
//	}
//}
//void Heap::out(void) {
//	for (int i = 0; i< HeapSize; i++) {
//		cout << h[i]<<":"<<size[i] << " ";
//	}
//	cout << endl;
//}
//void Heap::heapify(int i) {
//	int left, right;
//	string temp;
//	left = 2 * i + 1;
//	right = 2 * i + 2;
//	if (left < HeapSize) {
//		if (h[i] < h[left]) {
//			temp = h[i];
//			h[i] = h[left];
//			h[left] = temp;
//			heapify(left);
//		}
//	}
//	if (right < HeapSize) {
//		if (h[i] < h[right]) {
//			temp = h[i];
//			h[i] = h[right];
//			h[right] = temp;
//			heapify(right);
//		}
//	}
//}