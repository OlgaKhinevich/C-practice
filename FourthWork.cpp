#include "pch.h"
#include <iostream>
#include <memory>
#include <math.h>
#include <Windows.h>

using namespace std;

class Solution
{
protected:
	int a;
	int b; 

	Solution() {}

	Solution(int _a, int _b) 
	{
		a = _a;
		b = _b;
	}

};


class Linear : public Solution {
public:
	Linear() {}

	Linear(int _a, int _b):Solution(_a, _b) {}

	void set_values()
	{
		cout << "Введите коэффициент а: ";
		cin >> a;
		cout << "Введите коэффициент b: ";
		cin >> b;
		cout << endl;
	}

	void solve_linear_equation()
	{
		if (a == 0 && b != 0)
		{
			cout << "Нет решения" << endl;
		} 
		else if (a == 0 && b == 0)
		{
			cout << "Бесконечное количество решений" << endl;
		}
		else if (b == 0 && a != 0)
		{
			cout << "Корень: 0" << endl;
		}
		else {
			auto x = -b / a;
			cout << "Корень: " << x << endl;
		}
	}
};

class Square : public Solution {
private:
	int c;
	int d;
public:
	Square() {}

	Square(int _a, int _b, int _c):Solution(_a, _b)
	{
		c = _c;
	}

	void set_values()
	{
		cout << "Введите коэффициент а: ";
		cin >> a;
		cout << "Введите коэффициент b: ";
		cin >> b;
		cout << "Введите коэффициент c: ";
		cin >> c;
		cout << endl;
	}

	void solve_square_equation()
	{
		d = b * b - 4 * a*c;
		if (d > 0) 
		{
			auto x1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
			auto x2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
			cout << "Корни квадратного уравнения: " << x1 << " и " << x2 << endl;
		}
		else if (d == 0)
		{
			auto x = (-1 * b + sqrt(b*b - 4 * a*c)) / (2 * a);
			cout << "Корень квадратного уравнения: " << x << endl;

		}
		else
		{
			cout << "Дискриминант меньше 0, корни квадратного уравнения невещественные" << endl;
		}
	}
};


class Series {
	unique_ptr<Solution> solution;
	unique_ptr<Square> square;
	unique_ptr<Linear> linear;
public:
	Series() {
		solution = make_unique<Square>();
		square = make_unique<Square>();
		linear = make_unique<Linear>();
	}

	void input()
	{
		linear->set_values();
		square->set_values();

	}

	void output()
	{
		cout << "Решение линейного уравнения:" << endl;
		linear->solve_linear_equation();
		cout << "Решение квадратного уравнения:" << endl;
		square->solve_square_equation();
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Series* first_series = new Series();
	first_series->input();
	first_series->output();
}
