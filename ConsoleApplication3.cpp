#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Dog {
	string breed;
	char gender;
	string name;
	int age;
	string owner;
};

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int ages;
	int i;
	Dog A[5];
	for (i = 0; i < 3; i++) {
		cout << "Введите породу собаки: ";
		cin >> A[i].breed;
		cout << "Введите пол собаки: ";
		cin >> A[i].gender;
		cout << "Введите кличку собаки: ";
		cin >> A[i].name;
		cout << "Введите возраст собаки: ";
		cin >> A[i].age;
		cout << "Введите владельца собаки: ";
		cin >> A[i].owner;
	}
	cout << "   ";
	cout << "Вывести собак возраста: ";
	cin >> ages;
	for (i = 0; i < 4; i++) {
		if (ages == A[i].age) {
			cout << A[i].breed + " " + A[i].name << endl;
		}
		else continue;
	
	}
}