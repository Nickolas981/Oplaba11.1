#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>

using namespace std;
void wordCount();
void read();
void bubbleSort();
struct node;
void print_Tree(node *p, int level);
//map<string, int> words;
//string word[100][2];
//int counter = 0;
vector<pair<string, int>> vec;
ifstream in("input.txt");
struct node {
	int key;
	int counter;
	string  word; //= new string[10];
	node *l = NULL,
		 *r = NULL;

};
void print_Tree(node * p, int level);
void push(string data, int key,int counter, node *&t)
{

	if (t == NULL )
	{
		t = new node;
		t->key = key;
		t->word = data;
		t->counter = counter;
		t->l = t->r = NULL;
		return;
	}
	/*if (key == t->key)
	{
		t->word = data;

		return;
	}*/


	if (key>t->key)
		push(data, key,counter, t->r);
	else
		push(data, key,counter, t->l);

}
void main() {
	node *head_Word = NULL;
	read();
	//wordCount();
	bubbleSort();
	for (int i = 0; i < vec.size(); i++)
	{
		push(vec[i].first, i,vec[i].second, head_Word);
	}
	print_Tree(head_Word, 0);
	system("pause");
}
void read() {
	bool flag = false;
	pair<string, int> buff;
	if (in >> buff.first) {
		buff.second = 1;
		vec.push_back(buff);
	}
	while (in>>buff.first)
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

//void wordCount()
//{
//	string buf;
//	while (in >> buf)
//	{
//		if (words.count(buf))
//			words[buf]++;
//		else
//			words.insert(pair<string, int>(buf, 1));
//	}
//	for (map<string, int>::iterator i = words.begin(), end = words.end(); i != end; ++i) {
//		word[counter][1] = i->first;
//		word[counter++][2] = i->second;
//	}
//}
void print_Tree(node *p, int level)
{
	if (p)
	{
		print_Tree(p->l, level + 1);
		for (int i = 0; i< level; i++) cout << "   ";
		cout << p->counter << ":";
		/*for (int  i = 0; i < p->c; i++)
		{
		p->word[i];
		}*/
		cout << p->word;
		print_Tree(p->r, level + 1);
	}
}
void bubbleSort() // сортировка пузырьком
{
	pair<string, int> buff; // временная переменная для хранения элемента массива
	bool exit = false; // болевая переменная для выхода из цикла, если массив отсортирован

	while (!exit) // пока массив не отсортирован
	{
		exit = true;
		for (int i = 0; i < (vec.size() - 2); i++)																				   //сортировка пузырьком по убыванию - знак <
			if (vec[i].second < vec[i+1].second) // сравниваем два соседних элемента
			{
				// выполняем перестановку элементов массива
				/*temp[1] = arrayPtr[int_counter][1];
				temp[2] = arrayPtr[int_counter][2];
				
				arrayPtr[int_counter][1] = arrayPtr[int_counter + 1][1];
				arrayPtr[int_counter][2] = arrayPtr[int_counter + 1][2];
				arrayPtr[int_counter + 1][1] = temp[1];
				arrayPtr[int_counter + 1][2] = temp[2];
*/
				buff = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = buff;
				exit = false; // на очередной итерации была произведена перестановка элементов
			}
	}
}