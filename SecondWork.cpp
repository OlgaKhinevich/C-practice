#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int count = 0;
	int size = 0;
	int el;
	int i;
	vector <int> a;
	vector <int> sizes;
	vector <vector <int>> vec;
	cout << "Введите количество массивов: ";
	cin >> count;
	for (i = 0; i < count; i++) {
		cout << "Введите длину массива " << i + 1 << ": ";
		cin >> size;
		sizes.push_back(size);
		a.clear();
		for (int j = 0; j < size; j++)
		{
			cout << "Введите элемент массива " << i + 1 << ": ";
			cin >> el;
			a.push_back(el);
		}
		vec.push_back(a);
	}

	sort(sizes.begin(), sizes.end());

	for (int startIndex = 0; startIndex < count; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < count; ++currentIndex)
		{
			if (vec[currentIndex].size() < vec[smallestIndex].size())
				smallestIndex = currentIndex;
		}
		swap(vec[startIndex], vec[smallestIndex]);
	}

	for (int i = 0; i < count; ++i) {
		size = sizes[i];
		cout << endl;
		for (int j = 0; j < size; ++j) {
			cout << vec[i][j] << ' ';
		}
	}
	system("pause");
}


