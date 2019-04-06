#include "pch.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <String>
using namespace std;


class Bank_Card {
	string Card_Number;
	string FIO;
	string Account_Number;
	int Balance;
	int validityMonth;
	int validityYear;
	int PIN;
	string Bank_details;
public:
	Bank_Card(string number, string fio, string account, int balance, int month, int year, int pin, string details)
	{
		Card_Number = number;
		FIO = fio;
		Account_Number = account;
		Balance = balance;
		validityMonth = month;
		validityYear = year;
		PIN = pin;
		Bank_details = details;
	}

	void getInfo() {
		cout << "Номер карты: " << Card_Number << endl;
		cout << "ФИО владельца: " << FIO << endl;
		cout << "Номер счёта, к которому привязана карта: " << Account_Number << endl;
		cout << "Баланс карты: " << Balance << endl;
		cout << "Срок действия: " << validityMonth << " " << validityYear << endl;
		cout << "Реквизиты банка: " << Bank_details << endl;
	}

	void output_EUR() {
		double Euro = Balance / 73.43;
		cout << Euro << " евро" << endl;
	}
	void output_USD() {
		double Dollar = Balance / 65.41;
		cout << Dollar << " долларов" << endl;
	}
	 bool check_PIN(int input_PIN) {
		 
		if (input_PIN == PIN) {
			cout << "Пин-код введен верно" << endl;
			return true;
		}
		else {
			cout << "Пин-код не верный" << endl;
			return false;
		}
	}
	void check_validity(int nowMonth, int nowYear) {
		if (nowMonth < validityMonth && nowYear < validityYear) {
			cout << "Карта действительна" << endl;
		}
		else {
			cout << "Карта недействительна" << endl;
		}
	}
};


int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int input_PIN;

	Bank_Card card1("454676879980", "Иванов Иван Иванович", "459486958769789768", 128000, 12, 2021, 1234, "БИК: 123446789 ИНН: 788764543 Расчетный счет: 5465776878980 Корреспонденский счет: 565678000008766");
	cout << "Введите пин-код: ";
	cin >> input_PIN;
	//card1.check_PIN(input_PIN);
	if (card1.check_PIN(input_PIN) == true)
	{
		card1.getInfo();
		card1.output_EUR();
		card1.output_USD();
		
	}

	time_t now;
	struct tm nowLocal;
	now = time(NULL);
	nowLocal = *localtime(&now);
	int nowMonth = 1 + nowLocal.tm_mon;
	int nowYear = 1900 + nowLocal.tm_year;
	card1.check_validity(nowMonth, nowYear);
	system("pause");
}

