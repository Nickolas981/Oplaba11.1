#pragma once
#include <iostream>
#include<string>
using namespace std;

class Heap {
	static const int SIZE = 100; // максимальный размер кучи
	string *h;         // указатель на массив кучи
	int HeapSize; // размер кучи
public:
	Heap();  // конструктор кучи
	void addelem(string);  // добавление элемента кучи
	void outHeap();  // вывод элементов кучи в форме кучи
	void out();  // вывод элементов кучи в форме массива
	int getmax();  // удаление вершины (максимального элемента)
	void heapify(int);  // упорядочение кучи
};

Heap::Heap() {
	h = new string[SIZE];
	HeapSize = 0;
}
void Heap::addelem(string n) {
	int i, parent;
	i = HeapSize;
	h[i] = n;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (h[i] > h[parent]) {
			string temp = h[i];
			h[i] = h[parent];
			h[parent] = temp;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	HeapSize++;
}
void Heap::outHeap(void) {
	int i = 0;
	int k = 1;
	while (i < HeapSize) {
		while ((i < k) && (i < HeapSize)) {
			cout << h[i] << " ";
			i++;
		}
		cout << endl;
		k = k * 2 + 1;
	}
}
void Heap::out(void) {
	for (int i = 0; i< HeapSize; i++) {
		cout << h[i] << " ";
	}
	cout << endl;
}
void Heap::heapify(int i) {
	int left, right;
	string temp;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < HeapSize) {
		if (h[i] < h[left]) {
			temp = h[i];
			h[i] = h[left];
			h[left] = temp;
			heapify(left);
		}
	}
	if (right < HeapSize) {
		if (h[i] < h[right]) {
			temp = h[i];
			h[i] = h[right];
			h[right] = temp;
			heapify(right);
		}
	}
}