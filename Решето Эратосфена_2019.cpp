// Решето Эратосфена.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Вариант 15. 7 задание
//Версия 1.0
//2019г.
//Разработчик Бровцын Олег

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>


using namespace std;
void proverka(int &n, string temp, int from, int to);//проверка ввода
void decision(int *arr, int n);//решение
void output(int *arr, int n);//вывод
void about();//о программе
void help();//помощь

int main()
{
	setlocale(LC_ALL,"rus");
	int n = 0;//предел
	int number = 0;//номер пункта меню
	int flag_v = 0;//флаг для освобождения памяти
	int end_flag = 0;//выход из программы
	int *result = nullptr;//ответ
	do {
		system("cls");
		cout << "1 - Ввод" << endl;
		cout << "2 - Решение" << endl;
		cout << "3 - Вывод" << endl;
		cout << "4 - О программе" << endl;
		cout << "5 - Помощь" << endl;
		cout << "6 - Выход" << endl;
		proverka(number, "\nВведите номер пункта меню:", 1, 6);
		system("cls");
		switch (number) {
		case 1:
			if (flag_v > 0) {
				delete[] result;
				n = 0;
				flag_v = 0;
			}
			proverka(n, "Введите натуральное число(от 3 до 1000): ", 3, 1000);
			result = new int[n + 1];
			flag_v++;
			break;
		case 2:
			if (flag_v == 1) {
				decision(result, n);
				flag_v++;
				cout << "Задача решена!\nОтвет вы можете посмотреть в пункте меню \"Вывод\"" << endl;
			}
			else {
				if (flag_v == 2) {
					cout << "Задача уже решена!" << endl;
				}
				else {
					cout << "Начальные данные не обнаружены! Перейдите в пункт меню №1" << endl;
				}
			}
			cout << "\nНажмите ENTER..." << endl;
			_getch();
			break;
		case 3:
			if (flag_v == 2) {
				output(result, n);
			}
			else {
				cout << "Задача не решена! Перейдите в пункт меню №2" << endl;
			}
			cout << "\nНажмите ENTER..." << endl;
			_getch();
			break;
		case 4:
			about();
			break;
		case 5:
			help();
			break;
		case 6:
			cout << "До свидания!" << endl;
			end_flag++;
			if (flag_v > 0) {
				delete[] result;
			}
		}
	} while (end_flag == 0);	
	_getch();
	return 0;
}

void proverka(int &n, string temp, int from, int to) {
	int flag = 0;
	char str[80];
	do {
		flag = 0;
		cout << temp;
		cin.getline(str, 79);
		if (!atoi(str)) {
			cout << "\nВы ввели недопустимое значение! Повторите ввод\n\n";
			flag++;
		}
		else {
			n = atoi(str);
			if (n < from || n > to) {
				cout << "\nВы ввели недопустимое значение! Повторите ввод\n\n";
				flag++;
			}
		}
	} while (flag != 0);
}
void decision(int *arr, int n) {
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= n; i++) {//заполняем
		arr[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 1) {//если число не зачёркнуто
			for (int j = (i + i); j <= n; j += i) {
				arr[j] = 0;//зачёркиваем все последующие кратные
			}
		}
	}
}
void output(int *arr, int n) {
		int flag = 0;
		cout << "Простые числа в диапазоне [2, " << n << "]" << endl;
		for (int i = 0; i <= n; i++) {
			if (arr[i] == 1) {
				cout << setw(3) << i << "\t";
				flag++;
			}
			if (flag == 10) {
				cout << "\n";
				flag = 0;
			}
		}
}
void about() {
	cout << "Flow-формы и диаграммы Насcи-Шнейдермана (Вариант 15)\nВерсия 1.0\n2019 г.\nРазработчик Бровцын Олег" << endl;
	cout << "\nНажмите ENTER..." << endl;
	_getch();
}
void help() {
	cout << "ЗАДАНИЕ:\nДано целое n>2. Вывести все простые числа из диапазона [2,n]" << endl;
	cout << "\nНажмите ENTER..." << endl;
	_getch();
}
