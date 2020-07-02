//15 вариант
/*
1.)	Описать структуру с именем ZNAK, содержащую следующие поля:
•	фамилия, имя;
•	знак Зодиака;
•	день рождения (массив из трех чисел).
2.)	Написать программу, выполняющую следующие действия:
•	ввод с клавиатуры данных в массив, состоящий из n элементов типа ZNAK, записи должны быть упорядочены по датам дней рождения;
•	вывод на дисплей информации о человеке, чья фамилия введена с клавиатуры;
•	если такого нет, выдать на дисплей соответствующее сообщение.

*/
//Версия 1.0
//2019 г.
//Разработчик Бровцын Олег
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <string>

using namespace std;

struct ZNAK {
	char family[80];
	char name[80];
	char ZOD[80];
	int data[3];
};

void vvod(ZNAK *ptr, int n);//функция ввода
void sort(ZNAK *ptr, int n);//функция сортировки
void show(ZNAK *ptr, int n);//показать список
void search(ZNAK *ptr, int n);//поиск человека
void checkvvod(int &ptr1/*ссылка для даты*/, int from/*от значения*/, int to/*до значения*/, char *stroka/*название строки*/);//защита от дурака

int main()
{
	setlocale(LC_ALL, "rus");
	int flag=0;//флаг для case-меню
	int n;//количество людей
	int m;//выбор пункта меню
	int flagv;//флаг в защите от дурака
	char str[80];//строка, которая проверяется на защиту от дурака
	int end_flag = 0;//выход из программы
	ZNAK *ptr=0;//указатель на структуру
	cout << "ЗАДАНИЕ:\n1)Описать структуру с именем ZNAK, содержащую следующие поля:\n*фамилия;\n*имя;\n*Знак Зодиака;\n";
	cout << "*день рождения (массив из трех чисел)\n2)Написать программу, выполняющую следующие действия:\n";
	cout << "*ввод с клавиатуры данных в массив, состоящий из n элементов типа ZNAK, записи должны быть упорядочены по датам дней рождения;\n";
	cout << "*вывод на дисплей информации о человеке, чья фамилия введена с клавиатуры;\n*если такого нет, выдать на дисплей соответствующее сообщение.\n";
	cout << "Нажмите ENTER";
	_getch();
	system("cls");
	do {
		system("cls");
		cout << "1.Ввод" << endl;
		cout << "2.Отсортированный по датам рождения список" << endl;
		cout << "3.Найти человека в списке" << endl;
		cout << "4.Выход" << endl;
		do {//защита для ввода пункта меню
			flagv = 0;
			cout << "\nВведите номер пункта меню:";
			cin.getline(str,79);
			if (!atoi(str)) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n";
				flagv++;
			}
			else {
				m = atoi(str);
				if (m == NULL || m < 1 || m > 4) {
					cout << "Вы ввели недопустимое значение! Повторите ввод\n";
					flagv++;
				}
			}
		} while (flagv != 0);
		system("cls");
		switch (m) {
		case 1:
			if (flag > 0) {
				flag = 0;
				delete[] ptr;
				n = 0;
			}
			do {//защита для ввода количества людей
				flagv = 0;
				cout << "Введите число людей(натуральное число и не более 10!):";
				cin.getline(str, 79);
				if (!atoi(str)) {
					cout << "Вы ввели недопустимое значение! Повторите ввод\n";
					flagv++;
				}
				else {
					n = atoi(str);
					if (n == NULL || n < 1 || n > 10) {
						cout << "Вы ввели недопустимое значение! Повторите ввод\n";
						flagv++;
					}
					else {
						cout << "Нажмите ENTER" << endl;
					}
				}
			} while (flagv != 0);
			ptr = new ZNAK[n];
			vvod(ptr, n);
			flag++;
			break;
		case 2:
			if (flag > 0) {
				cout << "Вот отсортированный по датам рождения (по возрастанию) список" << endl;
				sort(ptr, n);
				show(ptr, n);
				flag++;
			}
			else {
				cout << "Вы не заполнили список! Выберите пункт №1!" << endl;
			}
			_getch();
			break;
		case 3:
			if (flag > 0) {
				search(ptr, n);
			}
			else {
				cout << "Вы не заполнили список! Выберите пункт №1!" << endl;
			}
			_getch();
			break;
		case 4:
			cout << "До свидания!";
			end_flag++;
		}
	} while (end_flag==0);
	if (flag > 0) {
		delete[] ptr;
	}
	_getch();
	return 0;
}

void vvod(ZNAK *ptr, int n) {
	char day[] = { "День:" };
	char month[] = { "Месяц:" };
	char year[] = { "Год:" };
	int choose;
	int k;
	char str[80];
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "\n";
		cout << (i+1) << "-й человек" << endl;
		cout << "Фамилия (не более 79 символов)(НА ЛАТИНИЦЕ!): ";
		cin.getline(ptr[i].family, 79);
		cout << "Имя (не более 79 символов)(НА ЛАТИНИЦЕ!): ";
		cin.getline(ptr[i].name, 79); 
		system("cls");
		cout << "1.Овен" << endl;
		cout << "2.Телец" << endl;
		cout << "3.Близнецы" << endl;
		cout << "4.Рак" << endl;
		cout << "5.Лев" << endl;
		cout << "6.Дева" << endl;
		cout << "7.Весы" << endl;
		cout << "8.Скорпион" << endl;
		cout << "9.Стрелец" << endl;
		cout << "10.Козерог" << endl;
		cout << "11.Водолей" << endl;
		cout << "12.Рыбы" << endl;
		cout << "\n";

		do {
			k = 0;
			cout << "Введите номер выбранного знака : ";
			cin.getline(str, 79);
			if (!atoi(str)) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n";
				k++;
			}
			else {
				choose = atoi(str);
				if (choose == NULL || choose < 1 || choose > 12) {
					cout << "Вы ввели недопустимое значение! Повторите ввод\n";
					k++;
				}
			}
		} while (k != 0);
		cout << "\n";
		switch (choose) {
		case 1:
			cout << "Вы выбрали знак: Овен" << endl;
			strcpy_s(ptr[i].ZOD, "Овен");
			break;
		case 2:
			cout << "Вы выбрали знак: Телец" << endl;
			strcpy_s(ptr[i].ZOD, "Телец");
			break;
		case 3:
			cout << "Вы выбрали знак: Близнецы" << endl;
			strcpy_s(ptr[i].ZOD, "Близнецы");
			break;
		case 4:
			cout << "Вы выбрали знак: Рак" << endl;
			strcpy_s(ptr[i].ZOD, "Рак");
			break;
		case 5:
			cout << "Вы выбрали знак: Лев" << endl;
			strcpy_s(ptr[i].ZOD, "Лев");
			break;
		case 6:
			cout << "Вы выбрали знак: Дева" << endl;
			strcpy_s(ptr[i].ZOD, "Дева");
			break;
		case 7:
			cout << "Вы выбрали знак: Весы" << endl;
			strcpy_s(ptr[i].ZOD, "Весы");
			break;
		case 8:
			cout << "Вы выбрали знак: Скорпион" << endl;
			strcpy_s(ptr[i].ZOD, "Скорпион");
			break;
		case 9:
			cout << "Вы выбрали знак: Стрелец" << endl;
			strcpy_s(ptr[i].ZOD, "Стрелец");
			break;
		case 10:
			cout << "Вы выбрали знак: Козерог" << endl;
			strcpy_s(ptr[i].ZOD, "Козерог");
			break;
		case 11:
			cout << "Вы выбрали знак: Водолей" << endl;
			strcpy_s(ptr[i].ZOD, "Водолей");
			break;
		case 12:
			cout << "Вы выбрали знак: Рыбы" << endl;
			strcpy_s(ptr[i].ZOD, "Рыбы");
			break;
		}
		cout << "\nНажмите ENTER" << endl;
		_getch();
		system("cls");
		cout << "Дата рождения:(цифрами!)" << endl;
		checkvvod(ptr[i].data[0], 1, 31, day);
		checkvvod(ptr[i].data[1], 1, 12, month);
		checkvvod(ptr[i].data[2], 1900, 2019, year);
	}
}
void sort(ZNAK *ptr, int n) {
	ZNAK temp;
	for (int i = 0; i < (n-1); i++) {
		for (int j = (i + 1); j < n; j++) {
			if (ptr[i].data[2] > ptr[j].data[2]) {
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
			else if(ptr[i].data[2]==ptr[j].data[2]){
				if (ptr[i].data[1] > ptr[j].data[1])
				{
					temp = ptr[i];
					ptr[i] = ptr[j];
					ptr[j] = temp;
				}
				else if (ptr[i].data[1] == ptr[j].data[1]) {
					if (ptr[i].data[0] > ptr[j].data[0]) {
						temp = ptr[i];
						ptr[i] = ptr[j];
						ptr[j] = temp;
					}
				}
			}
		}
	}
}
void show(ZNAK *ptr, int n) {
	for (int j = 0; j < n; j++) {
		cout << (j + 1) << ".*********" << endl;
		cout << "Фамилия/Имя:           " << ptr[j].family << " " << ptr[j].name << endl;
		cout << "Знак зодиака:          " << ptr[j].ZOD << endl;
		cout << "Дата рождения (д.м.г): " << ptr[j].data[0] << "." << ptr[j].data[1] << "." << ptr[j].data[2] << endl;
		cout << "\n";
	}
	cout << "\nНажмите ENTER";
}
void search(ZNAK *ptr, int n) {
	char str[80];
	int m;
	do {
		m = 0;
		cout << "Если хотите вернуться к меню, то введите stop" << endl;
		cout << "Введите Фамилию:";
		cin.getline(str, 79);
		for (int i = 0; i < n; i++) {
			if (!strcmp(ptr[i].family, str)) {
				cout << "\n" << (i + 1) << ".*********" << endl;
				cout << "Фамилия/Имя:           " << ptr[i].family << " " << ptr[i].name << endl;
				cout << "Знак зодиака:          " << ptr[i].ZOD << endl;
				cout << "Дата рождения (д.м.г): " << ptr[i].data[0] << "." << ptr[i].data[1] << "." << ptr[i].data[2] << endl;
				m++;
			}
			cout << "\n";
		}
		if (m == 0 && strcmp("stop",str)) {
			cout << "Данные об этом человеке отсутствуют.\n" << endl;
		}
		if (!strcmp("stop", str)) {
			cout << "Чтобы продолжить, нажмите ENTER" << endl;
		}
	} while (strcmp("stop",str));
}
void checkvvod(int &ptr1, int from, int to, char *stroka) {
	int k;
	char str[80];
	do {
		k = 0;
		cout << stroka;
		cin.getline(str, 79);
		if (!atoi(str)) {
			cout << "Вы ввели недопустимое значение! Повторите ввод\n";
			k++;
		}
		else {
			ptr1 = atoi(str);
			if (ptr1 == NULL || ptr1 < from || ptr1 > to) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n";
				k++;
			}
		}
	} while (k != 0);
}
