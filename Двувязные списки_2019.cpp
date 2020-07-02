// Двувязные списки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Вариант 15. 8 задание
//Версия 1.0
//2019г
//Разработчик Бровцын Олег

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct List {
	string family;//фамилия автора
	string ins;//инициалы автора
	string name;//название
	int data;//дата издания
	int number;//количество экземпляров
	List *prev;//предыдущий элемент
	List *next;//следующий элемент
};

void vvod_with_insert(List **q);//ввод и добавление данных в очередь
void sort(List **q);//сортировка по дате издания
void show(List **q, int b);//показать всех
void take_out(List **q);//удаление из очереди
void search(List **q);//поиск книги
void del(List **q);//удаление по выбору




int main()
{
	setlocale(LC_ALL, "rus");
	int end_flag = 0;//флаг выхода из программы
	int flag_v = 0;//флаг ввода
	List *q = nullptr;//очередь
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
						if (flag_v < 1 || flag_v > 2) {
							cout << "Вы ввели недопустимое значение! Повторите ввод\n";
							flag++;
						}
					}
				} while (flag != 0);
			} while (flag_v == 1);
			sort(&q);
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
			if (flag_v == 0) {
				cout << "\nНажмите ENTER" << endl;
				_getch();
			}
			break;
		case 3://показать всё
			if (q) {
				do {
					system("cls");
					cout << "1. Вывести с начала" << endl;
					cout << "2. Вывести с конца" << endl;
					cout << "3. Вернуться в главное меню" << endl;
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
							if (n == NULL || n < 1 || n > 3) {
								cout << "Вы ввели недопустимое значение! Повторите ввод\n";
								flag++;
							}
						}
					} while (flag != 0);
					system("cls");
					switch (n) {
					case 1:
						show(&q, 1);
						cout << "\n\nНажмите ENTER" << endl;
						_getch();
						break;
					case 2:
						show(&q, 2);
						cout << "\n\nНажмите ENTER" << endl;
						_getch();
					}
				} while (n != 3);
			}
			else {
				cout << "\nБиблиотека пуста!" << endl;
				cout << "\n\nНажмите ENTER" << endl;
				_getch();
			}
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
			if (flag_v == 0) {
				cout << "\nНажмите ENTER" << endl;
				_getch();
			}
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
			cout << "1.)  Составить программу, которая содержит текущую информацию о книгах в библиотеке.\nСведения о книгах включают :\n*фамилию и инициалы автора;\n*название;\n*год издания;\n*количество экземпляров данной книги в библиотеке.\n2.)   Программа должна обеспечивать :\n*хранение всех данных обо всех книгах в библиотеке в виде двусвязного списка, записи должны быть упорядочены по годам издания;\n*добавление данных о книгах вновь поступивших в библиотеку;\n*удаление данных о списываемой книге, название которой введено с клавиатуры;\n*вывод информации обо всех книгах в библиотеке;\n*по запросу выводится информация обо всех книгах автора, имеющихся в библиотеке, чья фамилия введена с клавиатуры.\n3.)	Программа должна обеспечивать диалог с помощью меню." << endl;
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
void vvod_with_insert(List **q) {
	system("cls");
	List *new_node;//указатель на новый элемент
	string str;//строка для ввода
	int temp;//переменная для целых чисел
	int flag = 0;//флаг для проверки ввода целых чисел
	char str1[80];//строка для проверки ввода целых чисел
	new_node = new List;//выделение памяти под новый элемент
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
	if (!(*q)) {
		(*q) = new_node;
		(*q)->prev = nullptr;
		(*q)->next = nullptr;
	}
	else {
		List *current = (*q)->next;
		List *previous = *q;
		while (current) {
			previous = current;
			current = current->next;
		}
		previous->next = new_node;
		new_node->prev = previous;
		new_node->next = current;
	}
}
void show(List **q, int b)
{
	int i = 1;//счётчик 
	List *temp = *q;
	cout << "Данные обо всех книгах в библиотеке:\n";
	if (b == 1) {
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
	else {
		while (temp->next) {
			temp = temp->next;
		}
		while (temp) {
			cout << "\n" << i << ".***********\n";
			cout << "Фамилия И.О. автора:    " << temp->family << " " << temp->ins << endl;
			cout << "Название книги:         " << temp->name << endl;
			cout << "Дата издания:           " << temp->data << endl;
			cout << "Количество экземпляров: " << temp->number << endl;
			temp = temp->prev;
			i++;
			cout << "\n";
		}
	}
}
void search(List **q) {
	int flag = 0;
	int i = 1;//счётчик
	string str;
	List *current = *q;
	List *previous = 0;
	cout << "Введите фамилию автора:";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите Фамилию автора: ";
		getline(cin, str);
	}
	while (current) {
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
void take_out(List **q)
{
	List *old_header = *q;
	while (*q) {
		*q = (*q)->next;
		delete(old_header);
		old_header = *q;
	}
}
void del(List **q) {
	int i = 1;//счётчик
	int end_flag = 0;//флаг для вывода сообщения об удалении
	string str;//строка для ввода названия книги  
	string str1;//утверждения удаления
	List *current = *q;//указатель на текущий элемент
	List *previous = 0;//указатель на предыдущий элемент
	cout << "Введите название книги:";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите название книги: ";
		getline(cin, str);
	}
	while (current) {
		if (*q) {
			if ((*q)->name == str) {//если первый элемент, то указатель на заголовок сместится
				cout << "\nЭлемент: " << endl;
				cout << "\n" << i << ".***********\n";
				cout << "Фамилия И.О. автора:    " << (*q)->family << " " << (*q)->ins << endl;
				cout << "Название книги:         " << (*q)->name << endl;
				cout << "Дата издания:           " << (*q)->data << endl;
				cout << "Количество экземпляров: " << (*q)->number << endl;
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
					cout << "\nЭлемент: " << endl;
					cout << "\n" << i << ".***********\n";
					cout << "Фамилия И.О. автора:    " << (*q)->family << " " << (*q)->ins << endl;
					cout << "Название книги:         " << (*q)->name << endl;
					cout << "Дата издания:           " << (*q)->data << endl;
					cout << "Количество экземпляров: " << (*q)->number << endl;
					cout << "\nУДАЛЁН!" << endl;
					List *tmp = (*q)->next;
					current = current->next;
					delete (*q);
					(*q) = tmp;
					if (*q) {
						current->prev = nullptr;
					}
				}
				else {
					current = current->next;
					previous = *q;
				}
				end_flag++;
			}
			if (*q) {
				if ((*q)->name != str || str1 == "no") {
					while (current) {
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
								if (current) {
									current->prev = previous;
								}
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
		}
	}
	if (end_flag == 0) {
		cout << "\nВ библиотеке нет данных по этому запросу!" << endl;
	}
}
void sort(List **q) {
    int i = 0;
	List *current = *q;
	List *temp = new List;
	while (current->next) {
		if (current->data > current->next->data) {
			i++;
			temp->family = current->family;
			temp->ins = current->ins;
			temp->name = current->name;
			temp->data = current->data;
			temp->number = current->number;
			current->family = current->next->family;
			current->ins = current->next->ins;
			current->name = current->next->name;
			current->data = current->next->data;
			current->number = current->next->number;
			current->next->family = temp->family;
			current->next->ins = temp->ins;
			current->next->name = temp->name;
			current->next->data = temp->data;
			current->next->number = temp->number;
			current = current->next;
		}
		else {
			current = current->next;
		}
	}
	if (i > 0) {
		sort(q);
	}
	delete(temp);
}

