/*
Вариант 15
Задание:
1.)	Составить программу, которая содержит текущую информацию о книгах в библиотеке.
Сведения о книгах включают:
•	фамилию и инициалы автора;
•	название;
•	год издания;
•	количество экземпляров данной книги в библиотеке.
2.)	Программа должна обеспечивать:
•	хранение всех данных обо всех книгах в библиотеке в виде односвязного списка (очередь);
•	добавление данных о книгах, вновь поступивших в библиотеку;
•	удаление данных о списываемой книге, название которой введено с клавиатуры;
•	вывод информации обо всех книгах в библиотеке;
•	по запросу выводится информация обо всех книгах автора, имеющихся в библиотеке, чья фамилия введена с клавиатуры.
3.)	Программа должна обеспечивать диалог с помощью меню.
*Версия 1.0
*2019 г.
*Разработчик Бровцын Олег
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#define QUEUE struct List

using namespace std;



 QUEUE {
	string family;//фамилия автора
	string ins;//инициалы автора
	string name;//название
	int data;//дата издания
	int number;//количество экземпляров
	QUEUE *next;//указатель на следующий элемент очереди
};

 void vvod_with_insert(QUEUE **q);//ввод и добавление данных в очередь
 void show(QUEUE **q);//показать всех
 void take_out(QUEUE  **q);//удаление из очереди
 void search(QUEUE **q);//поиск книги
 void del(QUEUE **q);//удаление по выбору

int main()
{
	setlocale(LC_ALL,"rus");
	int end_flag = 0;//флаг выхода из программы
	int flag_v = 0;//флаг ввода
	QUEUE *q = nullptr;//очередь
	int n;//номер пункта меню
	char str[80];//строка для проверки ввода целых
	int flag = 0;//флаг для проверки ввода целых
	do {
		system("cls");
		cout << "1.Добавить новые книги" << endl;
		cout << "2.Удалить списываемую книгу из списка" << endl;
		cout << "3.Вывод данных о всех книгах в списке" << endl;
		cout << "4.Вывод данных по запросу" << endl;
		cout << "5.О программе" << endl;
		cout << "6.Помощь" << endl;
		cout << "7.Выход" << endl;
		do {//защита для ввода пункта меню
			flag = 0;
			cout << "\nВведите номер пункта меню:";
			cin.getline(str, 79);
			if (!atoi(str)) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n";
				flag++;
			}
			else {
				n = atoi(str);
				if (n == NULL || n < 1 || n > 7) {
					cout << "Вы ввели недопустимое значение! Повторите ввод\n";
					flag++;
				}
			}
		} while (flag != 0);
		cout << "\nНажмите ENTER" << endl;
		_getch();
		system("cls");
		switch (n) {
		case 1://ввод
			do {
				vvod_with_insert(&q);
				cout << "\nЕсли хотите продолжить введите 1, иначе 2" << endl;				
				do {//проверка ввода
					flag = 0;
					cout << "Ваш выбор: ";
					cin.getline(str, 79);
					if (!atoi(str)) {
						cout << "Вы ввели недопустимое значение! Повторите ввод\n";
						flag++;
					}
					else {
						flag_v = atoi(str);
						if ( flag_v < 1 || flag_v > 2) {
							cout << "Вы ввели недопустимое значение! Повторите ввод\n";
							flag++;
						}
					}
				} while (flag != 0);
			} while (flag_v == 1);
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 2://удалить книгу
			if (q) {
				flag_v = 0;
				do {
					del(&q);
					cout << "\nЕсли хотите продолжить введите 1, иначе 2" << endl;
					do {//проверка ввода
						flag = 0;
						cout << "Ваш выбор: ";
						cin.getline(str, 79);
						if (!atoi(str)) {
							cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
							flag++;
						}
						else {
							flag_v = atoi(str);
							if (flag_v < 1 || flag_v > 2) {
								cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
								flag++;
							}
						}
					} while (flag != 0);
					cout << "\n";
				} while (flag_v == 1);
			}
			else {
				cout << "\nБиблиотека пуста!" << endl;
			}
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 3://показать всё
			if (q) {
				show(&q);
			}
			else {
				cout << "\nБиблиотека пуста!" << endl;
			}
			cout << "\n\nНажмите ENTER" << endl;
			_getch();
			break;
		case 4://поиск и вывод инфы по книге
			flag_v = 0;
			if (q) {
				do {
					search(&q);
					cout << "\nЕсли хотите продолжить введите 1, иначе 2" << endl;
					do {//проверка ввода
						flag = 0;
						cout << "Ваш выбор: ";
						cin.getline(str, 79);
						if (!atoi(str)) {
							cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
							flag++;
						}
						else {
							flag_v = atoi(str);
							if (flag_v < 1 || flag_v > 2) {
								cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
								flag++;
							}
						}
					} while (flag != 0);
					cout << "\n";
				} while (flag_v == 1);
			}
			else {
				cout << "\nБиблиотека пуста!" << endl;
			}
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 5:
			cout << "Вариант 15" << endl;
			cout << "Версия 1.0" << endl;
			cout << "2019 г." << endl;
			cout << "Разработчик Бровцын Олег" << endl;
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 6:
			cout <<"Задание:\n1.)Составить программу, которая содержит текущую информацию о книгах в библиотеке.\nСведения о книгах включают :\n*фамилию и инициалы автора;\n*название;\n*год издания;\n*количество экземпляров данной книги в библиотеке.\n2.)Программа должна обеспечивать :\n*хранение всех данных обо всех книгах в библиотеке в виде односвязного списка(очередь);\n*добавление данных о книгах, вновь поступивших в библиотеку;\n*удаление данных о списываемой книге, название которой введено с клавиатуры;\n*вывод информации обо всех книгах в библиотеке;\n*по запросу выводится информация обо всех книгах автора, имеющихся в библиотеке, чья фамилия введена с клавиатуры.\n3.)Программа должна обеспечивать диалог с помощью меню." <<  endl;
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 7://выход
			take_out(&q);
			end_flag++;
			cout << "До свидания!" << endl;
		}
	} while (end_flag == 0);
	cout << "\nНажмите ENTER" << endl;
	_getch();
	return 0;
}

void vvod_with_insert(QUEUE **q) {
	system("cls");
	QUEUE *current = *q;//указатель на текущий элемент списка
	QUEUE *previous = 0;//указатель на последний элемент
	QUEUE *new_node;//указатель на новый элемент
	string str;//строка для ввода
	int temp;//переменная для целых чисел
	int flag = 0;//флаг для проверки ввода целых чисел
	char str1[80];//строка для проверки ввода целых чисел
	while (current)
	{
		previous = current;
		current = current->next;
	}
	new_node = new QUEUE;//выделение памяти под новый элемент
	cout << "Ввод слов на ЛАТИННИЦЕ!\n\n";
	cout << "Введите Фамилию автора: ";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите Фамилию автора: ";
		getline(cin, str);
	}
	new_node->family = str;
	str = "";
	cout << "\nВведите инициалы автора: ";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите инициалы автора: ";
		getline(cin, str);
	}
	new_node->ins = str;
	str = "";
	cout << "\nВведите название книги: ";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите название книги: ";
		getline(cin, str);
	}
	new_node->name = str;
	do {
		flag = 0;
		cout << "\nВведите год издания: ";
		cin.getline(str1, 79);
		if (!atoi(str1)) {
			cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
			flag++;
		}
		else {
			temp = atoi(str1);
			if (temp < 0 || temp > 2019) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
				flag++;
			}
		}
	} while (flag != 0);
	new_node->data = temp;
	temp = 0;
	do {
		flag = 0;
		cout << "\nВведите количество экземпляров(не более 1000!): ";
		cin.getline(str1, 79);
		if (!atoi(str1)) {
			cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
			flag++;
		}
		else {
			temp = atoi(str1);
			if (temp < 0 || temp > 1000) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
				flag++;
			}
		}
	} while (flag != 0);
	new_node->number = temp;
	if (previous)//если в очереди что-то было, связываем с последним
	{
		new_node->next = previous->next;
		previous->next = new_node;
	}
	else//связываем с заголовком
	{
		*q = new_node;
		(*q)->next = 0;
	}
}
void show(QUEUE **q)
{
	int i = 1;//счётчик 
	QUEUE *temp = *q;
		cout << "Данные обо всех книгах в библиотеке:\n";
		while (temp)
		{
			cout << "\n" << i << ".***********\n";
			cout << "Фамилия И.О. автора:    " << temp->family << " " << temp->ins << endl;
			cout << "Название книги:         " << temp->name << endl;
			cout << "Дата издания:           " << temp->data << endl;
			cout << "Количество экземпляров: " << temp->number << endl;
			temp = temp->next;
			i++;
			cout << "\n";
		}
}
void search(QUEUE **q) {
	int flag = 0;
	int i = 1;//счётчик
	string str;
	QUEUE *current = *q;
	QUEUE *previous = 0;
	cout << "Введите фамилию автора:";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите Фамилию автора: ";
		getline(cin, str);
	}
	while(current){
		if (current->family == str) {
			cout << "\n" << i << ".***********\n";
			cout << "Фамилия И.О. автора:    " << current->family << " " << current->ins << endl;
			cout << "Название книги:         " << current->name << endl;
			cout << "Дата издания:           " << current->data << endl;
			cout << "Количество экземпляров: " << current->number << endl;
			cout << endl;
			flag++;
			current = current->next;
			i++;
		}
		else {
			previous = current;
			current = current->next;
			i++;
		}
	} 
	if (flag == 0) {
		cout << "\nВ библиотеке нет данных по этому запросу!" << endl;
	}
}
void take_out(QUEUE  **q)
{
	QUEUE *old_header = *q;
	while (*q) {
			*q = (*q)->next;
			delete(old_header);
			old_header = *q;
	}
}
void del(QUEUE **q) {
	int i = 1;
	int end_flag = 0;//флаг для вывода сообщения об удалении
	string str;//строка для ввода названия книги  
	string str1;//утверждения удаления
	QUEUE *current = *q;//указатель на текущий элемент
	QUEUE *previous = 0;//указатель на предыдущий элемент
	cout << "Введите название книги:";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите название книги: ";
		getline(cin, str);
	}
	if (*q) {
		if ((*q)->name == str) {//если первый элемент, то указатель на заголовок сместится
			cout << "\nЭлемент: " << endl;
			cout << "\n" << i << ".***********\n";
			cout << "Фамилия И.О. автора:    " << (*q)->family << " " << (*q)->ins << endl;
			cout << "Название книги:         " << (*q)->name << endl;
			cout << "Дата издания:           " << (*q)->data << endl;
			cout << "Количество экземпляров: " << (*q)->number << endl;
			cout <<"\nВы действительно хотите удалить этот элемент?(Введите yes or no)" << endl;
			cout << "\nВаш выбор:";
			getline(cin, str1);
			while (str1 != "yes" && str1 != "no") {
				cin.clear();
				cin.sync();
				cout << "\nВы ввели некорректное значение!" << endl;
				cout << "\nВаш выбор: ";
				getline(cin, str1);
			}
			if (str1 == "yes") {
				cout << "\nЭлемент: " << endl;
				cout << "\n" << i << ".***********\n";
				cout << "Фамилия И.О. автора:    " << (*q)->family << " " << (*q)->ins << endl;
				cout << "Название книги:         " << (*q)->name << endl;
				cout << "Дата издания:           " << (*q)->data << endl;
				cout << "Количество экземпляров: " << (*q)->number << endl;
				cout << "\nУДАЛЁН!" << endl;
				QUEUE *tmp = (*q)->next;
				delete (*q);
				(*q) = tmp;
			}
			end_flag++;
		}
		else {
			while (current) {//пока не конец
				if (current->name != str) {
					previous = current;
					current = current->next;
					i++;
				}
				else {
					cout << "\nЭлемент: " << endl;
					cout << "\n" << i << ".***********\n";
					cout << "Фамилия И.О. автора:    " << current->family << " " << current->ins << endl;
					cout << "Название книги:         " << current->name << endl;
					cout << "Дата издания:           " << current->data << endl;
					cout << "Количество экземпляров: " << current->number << endl;
					cout << "\nВы действительно хотите удалить этот элемент?(Введите yes or no)" << endl;
					cout << "\nВаш выбор:";
					getline(cin, str1);
					while (str1 != "yes" && str1 != "no") {
						cin.clear();
						cin.sync();
						cout << "\nВы ввели некорректное значение!" << endl;
						cout << "\nВаш выбор: ";
						getline(cin, str1);
					}
					if (str1 == "yes") {
						previous->next = current->next;
						cout << "\nЭлемент: " << endl;
						cout << "\n" << i << ".***********\n";
						cout << "Фамилия И.О. автора:    " << current->family << " " << current->ins << endl;
						cout << "Название книги:         " << current->name << endl;
						cout << "Дата издания:           " << current->data << endl;
						cout << "Количество экземпляров: " << current->number << endl;
						cout << "\nУДАЛЁН!" << endl;
						delete (current);
						i++;
						current = previous->next;//указатель на следующий элемент, чтобы дойти до конца
					}
					else {
						previous = current;
						current = current->next;
					}
					end_flag++;
				}
			}
		}
	}
	if (end_flag == 0) {
		cout << "\nВ библиотеке нет данных по этому запросу!" << endl;
	}
}