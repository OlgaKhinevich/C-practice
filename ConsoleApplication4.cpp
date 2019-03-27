#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
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
	vector <int> b;
	vector <vector <int>> vec;
	cout << "Введите количество массивов: ";
	cin >> count;
	for (i=1; i <= count; i++) {
		cout << "Введите длину массива " << i << ": ";
		cin >> size;
		a.clear();
		for (int j = 0; j < size; j++)
		{
			cout << "Введите элемент массива " << i << ": ";
			cin >> el;
			a.push_back(el);
		}
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end(), [](prev, next)
	{
		return (prev.size() < next.size()) ;
	});
	
		
	
	
	
}


