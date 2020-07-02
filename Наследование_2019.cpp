/*
*Вариант 15
*Версия 1.0
*2019г
*Разработчик: Бровцын Олег
*ЗАДАНИЕ:
Задан базовый класс book
class book {
public:
book(char *, char *, int);
void show_book(void);
private:
char title[64]; //Заголовок
char author[64]; // Автор
int pages; //Число страниц
};
Необходимо создать класс library_card,
который будет добавлять следующие элементы данных в класс book:
char catalog[64];
int checked_out; // 1, если проверена, иначе 0.
Программа должна использовать наследование, чтобы породить класс library card из класса book.
Написать программу, которая считывает информацию о книге и распечатывает ее.
Конструктор library_card вызывает конструктор класса book для инициализации элементов класса book.
Кроме того, необходимо использовать функцию-элемент show_book класса book внутри функции show_card.
Поскольку класс library_card наследует методы
класса book, функция show_card может вызвать этот метод (show_book) без помощи оператора точки, как если бы этот метод был методом класса library_card.
*/

#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

class book {
private:
	char title[64]; //Заголовок 
	char author[64]; // Автор 
	int pages; //Число страниц 
public:
	book();
	void show_book();//показать книги
	void input_1();//ввести книги
	void search_1(char *str, int &n);//поиск по каталогу
};
//базовый класс
book::book() {
	//ничего не делает
}
void book::show_book() {
	cout << "Заголовок:          " << title << endl;
	cout << "Автор:              " << author << endl;
	cout << "Количество страниц: " << pages << endl;
}
void book::input_1() {
	system("cls");
	int flag = 0;//флаг на защиту
	char str[80];//строка для ввода числа
	cout << "Ввод на латинице!!!\n" << endl;
	cout << "Введите Заголовок: ";
	cin.getline(title, 64);
	while (strlen(title) == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!!!\n" << endl;
		cout << "Введите Заголовок: ";
		cin.getline(title, 64);
	}
	cout << "\nВведите фамилию автора (С большой буквы!): ";
	cin.getline(author, 64);
	while (strlen(author) == 0 || author[0] < 'A' || author[0] > 'Z') {
		cin.clear();
		cin.sync();
		cout << "\nВы ввели некорректное значение!!!\n" << endl;
		cout << "Введите фамилию автора (С большой буквы!): ";
		cin.getline(author, 64);
	}
	do {//защита для ввода пункта меню
		flag = 0;
		cout << "\nВведите количество страниц (до 100000):";
		cin.getline(str, 79);
		if (!atoi(str)) {
			cout << "Вы ввели недопустимое значение! Повторите ввод\n";
			flag++;
		}
		else {
			pages = atoi(str);
			if (pages < 1 || pages > 100000) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n";
				flag++;
			}
		}
	} while (flag != 0);
}
void book::search_1(char *str, int &n) {
	if (str[0] == author[0]) {
		cout << "***************" << endl;
		cout << "Заголовок:          " << title << endl;
		cout << "Фамилия автора:     " << author << endl;
		cout << "Количество страниц: " << pages << endl;
		cout << "\n";
		n++;
	}
}
class library_card : public book {
private:
	char catalog[64];//каталог
	library_card *next;//ссылка не следующий элемент
public:
	library_card();
	void show_card(library_card **q);//вывод
	void input_2(library_card **q);//ввод
	void take_out(library_card **q);//удалить всё
	void search(library_card **q);//вывод по каталогу
};
//наследник
library_card::library_card() {
	//вызывает конструктор базового класса по умолчанию
}
void library_card::show_card(library_card **q) {
	int i = 1;//счётчик 
	library_card *temp = *q;
	cout << "Данные обо всех книгах в библиотеке:\n";
	while (temp)
	{
		cout << "\n" << i << ".***********\n";
		temp->show_book();
		temp = temp->next;
		i++;
		cout << "\n";
	}
}
void library_card::input_2(library_card **q) {
	library_card *current = *q;//указатель на текущий элемент списка
	library_card *previous = 0;//указатель на последний элемент
	library_card *new_node;//указатель на новый элемент
	int flag = 0;//флаг для проверки ввода целых чисел
	while (current)
	{
		previous = current;
		current = current->next;
	}
	new_node = new library_card;
	new_node->input_1();
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
void library_card::take_out(library_card **q)
{
	library_card *old_header = *q;
	while (*q) {
		*q = (*q)->next;
		delete(old_header);
		old_header = *q;
	}
}
void library_card::search(library_card **q) {
	system("cls");
	int count = 0;
	library_card *current = *q;
	cout << "Каталог Должен начинаться с латинской буквы верхнего регистра!\n" << endl;
	cout << "Введите каталог: ";
	cin.getline(catalog, 64);
	while (strlen(catalog) == 0 || catalog[0] < 'A' || catalog[0] > 'Z') {
		cin.clear();
		cin.sync();
		cout << "\nНеправильно!!!!\n" << endl;
		cout << "Введите каталог: ";
		cin.getline(catalog, 64);
	}
	while (current) {
		current->search_1(catalog, count);
		current = current->next;
	}
	if (count == 0) {
		cout << "\nДанных по этому запросу нет!" << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	library_card *q = nullptr;//очередь
	library_card controller;//обЪект
	int end_flag = 0;//флаг выхода из программы
	int flag_v = 0;//флаг ввода
	int n;//номер пункта меню
	char str[80];//строка для проверки ввода целых
	int flag = 0;//флаг для проверки ввода целых
	do {
		system("cls");
		cout << "1.Добавить новые книги" << endl;
		cout << "2.Вывод данных о всех книгах в списке" << endl;
		cout << "3.Вывод по каталогу" << endl;
		cout << "4.О программе" << endl;
		cout << "5.Помощь" << endl;
		cout << "6.Выход" << endl;
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
				if (n < 1 || n > 6) {
					cout << "Вы ввели недопустимое значение! Повторите ввод\n";
					flag++;
				}
			}
		} while (flag != 0);
		system("cls");
		switch (n) {
		case 1://ввод
			do {
				controller.input_2(&q);//вводим
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
			break;
		case 2://показать всё
			if (q) {
					controller.show_card(&q);//показываем
			}
			else {
				cout << "\nБиблиотека пуста!" << endl;
			}
			cout << "\n\nНажмите ENTER" << endl;
			_getch();
			break;
		case 3:
			if (q) {
				do {
					controller.search(&q);//ищем по каталогу
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
			}
			else {
				cout << "\nБиблиотека пуста!" << endl;
				cout << "\n\nНажимте ENTER" << endl;
				_getch();
			}
			break;
		case 4:
			cout << "Вариант 15" << endl;
			cout << "Версия 1.0" << endl;
			cout << "2019 г." << endl;
			cout << "Разработчик Бровцын Олег" << endl;
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 5:
			cout << "ЗАДАНИЕ:\nЗадан базовый класс book\nclass book {\npublic:\nbook(char *, char *, int);\nvoid show_book(void);\nprivate:\nchar title[64]; //Заголовок\nchar author[64]; // Автор\nint pages; //Число страниц\n};\nНеобходимо создать класс library_card, который будет добавлять следующие элементы данных в класс book :\nchar catalog[64];\nint checked_out; // 1, если проверена, иначе 0.\nПрограмма должна использовать наследование, чтобы породить класс library card из класса book.\nНаписать программу, которая считывает информацию о книге и распечатывает ее.\nКонструктор library_card вызывает конструктор класса book для инициализации элементов класса book.\nКроме того, необходимо использовать функцию - элемент show_book класса book внутри функции show_card.\nПоскольку класс library_card наследует методы\nкласса book, функция show_card может вызвать этот метод(show_book) без помощи оператора точки, как если бы этот метод был методом класса library_card." << endl;
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 6://выход
			controller.take_out(&q);
			end_flag++;
			cout << "До свидания!" << endl;
		}
	} while (end_flag == 0);
	cout << "\nНажмите ENTER" << endl;
	_getch();
	return 0;
}

