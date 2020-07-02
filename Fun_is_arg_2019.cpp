/*
Вариант №15. Задача в Абрамове #116(д, е)
Версия 1.0
2019 г.
Разработчик Бровцын Олег
*/
#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

void multiply(double (*f)(double, int), double &result, int n, double x);
void vvod(double &x, int &n);
double first(double x, int k);
double second(double x, int k);

int main()
{
	setlocale(LC_ALL, "rus");
	char str[80];//проверка ввода
	int n = 0;//натуральное число
	int end_flag = 0;//выход из программы
	int flag = 0;//флаг ввода
	int flag_case = 0;//флаг для выполнения кейсов
	int flag_solv_1 = 0;//флаг для вывода ответа №1
	int flag_solv_2 = 0;//флаг для вывода ответа №2
	int number = 0;//пункт меню
	double x = 0;//действительное число
	double result_1 = 1;//ответ №1
	double temp = 1;//факториал
	double result_2 = 1;//ответ №2
	do {
		system("cls");
		cout << "Меню:" << endl;
		cout << "1 - Ввод" << endl;
		cout << "2 - Решение по первой формуле" << endl;
		cout << "3 - Решение по второй формуле" << endl;
		cout << "4 - Вывод" << endl;
		cout << "5 - О программе" << endl;
		cout << "6 - Помощь" << endl;
		cout << "7 - Выход" << endl;
		do {//защита для ввода пункта меню
			flag = 0;
			cout << "\nВведите номер пункта меню:";
			cin.getline(str, 79);
			if (!atoi(str)) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n";
				flag++;
			}
			else {
				number = atoi(str);
				if (number < 1 || number > 7) {
					cout << "Вы ввели недопустимое значение! Повторите ввод\n";
					flag++;
				}
			}
		} while (flag != 0);
		system("cls");
		switch (number) {
		case 1://ввод
			if (flag_case > 0) {
				flag_case = 0;
				temp = 1;
				result_1 = 1;
				result_2 = 1;
				n = 0;
				x = 0;
				flag_solv_1 = 0;
				flag_solv_2 = 0;
			}
			vvod(x, n);
			flag_case++;
			_getch();
			break;
		case 2://решение №1
			if (flag_solv_1 == 0) {
				if (flag_case > 0) {
					multiply(first, result_1, n, x);
					flag_solv_1++;
					cout << "Задача успешно решена.\nОтвет вы можете увидеть в пункте меню \"Вывод\"" << endl;
				}
				else {
					cout << "\nВходные данные не обнаружены!" << endl;
				}
			}
			else {
				cout << "\nЗадача уже была решена!" << endl;
			}
			cout << "\nНажмите ENTER..." << endl;
			_getch();
			break;
		case 3://решение №2
			if (flag_solv_2 == 0) {
				if (flag_case > 0) {
					multiply(second, result_2, n , x);
					flag_solv_2++;
					cout << "Задача успешно решена.\nОтвет вы можете увидеть в пункте меню \"Вывод\"" << endl;
				}
				else {
					cout << "\nВходные данные не обнаружены!" << endl;
				}
			}
			else {
				cout << "\nЗадача уже была решена!" << endl;
			}
			cout << "\nНажмите ENTER..." << endl;
			_getch();
			break;
		case 4:
			if (flag_solv_1 == 0 && flag_solv_2 == 0) {
				cout << "Задачи не решены!" << endl;
			}
			else {
				cout << "При x = " << x << " и n = " << n << endl;
				if (flag_solv_1 > 0) {
					cout << "\nОтвет на задачу №1: " << result_1 << endl;
				}
				if (flag_solv_2 > 0) {
					cout << "\nОтвет на задачу №2: " << result_2 << endl;
				}
			}
			cout << "\nНажмите ENTER..." << endl;
			_getch();
			break;
		case 5:
			cout << "Вариант №15. Задача в Абрамове #116(д, е)\nВерсия 1.0\n2019 г.\nРазработчик Бровцын Олег" << endl;
			cout << "\nНажмите ENTER..." << endl;
			_getch();
			break;
		case 6:
			cout << "ОПИСАНИЕ ЗАДАЧ:" << endl;
			cout << "\nЗадача №1" << endl;
			cout << "\nП[от k = 1 до n]((k/(k + 1)) - cos^k(|x|)" << endl;
			cout << "\nЗадача №2" << endl;
			cout << "\nП[от k =1 до n]((((1-x)^(k+1)) + 1)/(((k - 1)! +1)^2))" << endl;
			cout << "\nНажмите ENTER..." << endl;
			_getch();
			break;
		case 7:
			cout << "До свидания!" << endl;
			cout << "\nНажмите ENTER..." << endl;
			end_flag++;
		}
	} while (end_flag == 0);
	_getch();
	return 0;
}

double first(double x, int k) {
	double temp = (double)k/(k + 1);
	double temp_1 = pow(cos(abs(x) * M_PI / 180),k);
	double sum_1 = temp - temp_1;
	return sum_1;
}
double second(double x, int k) {
	double temp = 1;
	for (int i = (k-1); i != 0; i--) {
		temp *= i;
	}
	double sum_2 = (pow(1 - x, k + 1) + 1) / pow(temp + 1, 2);
	return sum_2;
}
void multiply(double (*f)(double, int), double &result, int n, double x) {
	for (int i = 1; i <= n; i++) {
		result *= (*f)(x,i);
	}
}
void vvod(double &x, int &n) {
	int flag = 0;
	char str[80];
	do {
		flag = 0;
		cout << "(от -999,99 до 999,99)(Вместо точки запятая!!)" << endl;
		cout << "\nВведите действительное число: ";
		cin.getline(str, 79);
		if (!atof(str)) {
			cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
			flag++;
		}
		else {
			x = atof(str);
			if (x > 999.99 || x < -999.99) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
				flag++;
			}
		}
	} while (flag != 0);
	do {
		flag = 0;
		cout << "\nВведите натуральное число(от 0 до 20): ";
		cin.getline(str, 79);
		if (!atoi(str)) {
			cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
			flag++;
		}
		else {
			n = atoi(str);
			if (n < 0 || n > 20) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
				flag++;
			}
		}
	} while (flag != 0);
	cout << "\nНажмите ENTER..." << endl;
}


