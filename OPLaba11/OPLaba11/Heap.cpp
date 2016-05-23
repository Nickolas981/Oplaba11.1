#include"Heap.h"
//#include<vector>
//#include<vector>

Heap::Heap() {
	size = new  int[SIZE];
	h = new string[SIZE];
	HeapSize = 0;
}
vector<pair<string, int>> vec;
void Heap::addelem(string n, int s) {
	int i, parent;
	i = HeapSize;
	size[i] = s;
	h[i] = n;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (size[i] > size[parent]) {
			string temp = h[i];
			int buf = size[i];
			size[i] = size[parent];
			size[parent] = buf;
			h[i] = h[parent];
			h[parent] = temp;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	HeapSize++;
}
Heap heap;
Heap circle() {
	for (int i = 0; i < vec.size(); i++)
		heap.addelem(vec[i].first, vec[i].second);
	return heap;
}
void Heap::outHeap(void) {
	int i = 0;
	int k = 1;
	while (i < HeapSize) {
		while ((i < k) && (i < HeapSize)) {
			cout << h[i] << ":" << size[i] << " ";
			i++;
		}
		cout << endl;
		k = k * 2 + 1;
	}
}
void Heap::out(void) {
	for (int i = 0; i< HeapSize; i++) {
		cout << h[i] << ":" << size[i] << " ";
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
void push(string data, int key, int counter, node *&t)
{

	if (t == NULL)
	{
		t = new node;
		t->key = key;
		t->word = data;
		t->counter = counter;
		t->l = t->r = NULL;
		return;
	}
	if (key>t->key)
		push(data, key, counter, t->r);
	else
		push(data, key, counter, t->l);
}
void read() {
	ifstream in("input.txt");
	bool flag = false;
	pair<string, int> buff;
	if (in >> buff.first) {
		buff.second = 1;
		vec.push_back(buff);
	}
	while (in >> buff.first)
	{
		for (int i = 0; i < vec.size(); i++)
			if (vec[i].first == buff.first) {
				flag = true;
				vec[i].second++;
			}
		if (flag == false)
		{
			buff.second = 1;
			vec.push_back(buff);
		}
		flag = false;
	}
}


void print_Tree(node *p, int level)
{
	if (p)
	{
		print_Tree(p->l, level + 1);
		for (int i = 0; i< level; i++) cout << "   ";
		cout << p->counter << ":";
		cout << p->word;
		print_Tree(p->r, level + 1);
	}
}
void bubbleSort()
{
	pair<string, int> buff;
	bool exit = false;
	while (!exit)
	{
		exit = true;
		for (int i = 0; i < (vec.size() - 2); i++)																				   //сортировка пузырьком по убыванию - знак <
			if (vec[i].second < vec[i + 1].second)
			{
				buff = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = buff;
				exit = false;
			}
	}
}
