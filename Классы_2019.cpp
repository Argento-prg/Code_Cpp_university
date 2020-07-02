/*
Вариант №15
Версия 1.0
2019 г.
Разработчик Бровцын Олег
*/

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Library {
private:
		string surname;//фамилия
		string ins;//инициалы
		string name;//название
		int year;//год издания
		int number;//число экземпляров
		Library *next;//указатель на следующий
public:
	void set_all_data(Library **top);//заполнить данные
	void del(Library **top);//удалить элемент стека по названию
	void show(Library **top);//показать всё
	void search(Library **top);//найти по фамилии
	void swap(Library **first, Library **second);//сдать или вернуть
	void take_out(Library **top);//удалить всё
};
void Protect(int &n, string temp, int m, int k);
void Library::set_all_data(Library **top) {
	system("cls");
	Library *new_item = new Library;
	string str;
	int temp;
	cout << "Ввод слов на ЛАТИННИЦЕ!\n" << endl;
	cout << "Введите Фамилию автора: ";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите Фамилию автора: ";
		getline(cin, str);
	}
	new_item->surname = str;
	cout << "\nВведите инициалы автора: ";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите инициалы автора: ";
		getline(cin, str);
	}
	new_item->ins = str;
	cout << "\nВведите название книги: ";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите название книги: ";
		getline(cin, str);
	}
	new_item->name = str;
	Protect(temp, "\nВведите год издания: ", 0, 2019);
	new_item->year = temp;
	temp = 0;
	Protect(temp, "\nВведите количество экземпляров(не более 1000!): ", 0, 1000);
	new_item->number = temp;
	new_item->next = *top;
	(*top) = new_item;
}
void Library::del(Library **top){
	Library *current = *top;
	Library *previous = 0;
	string str;
	int i = 1;
	int end_flag = 0;//флаг для вывода сообщения об удалении 
	string str1;//утверждения удаления
	cout << "Введите название книги: ";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите название книги: ";
		getline(cin, str);
	}
	while (current) {
		if (*top) {
			if ((*top)->name == str) {//если первый элемент, то указатель на заголовок сместится
				cout << "\nЭлемент: " << endl;
				cout << "\n" << i << ".***********\n";
				cout << "Фамилия И.О. автора:    " << (*top)->surname << " " << (*top)->ins << endl;
				cout << "Название книги:         " << (*top)->name << endl;
				cout << "Дата издания:           " << (*top)->year << endl;
				cout << "Количество экземпляров: " << (*top)->number << endl;
				cout << "\nВы действительно хотите удалить этот элемент?(Введите yes or no)" << endl;
				cout << "\nВаш выбор: ";
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
					cout << "Фамилия И.О. автора:    " << (*top)->surname << " " << (*top)->ins << endl;
					cout << "Название книги:         " << (*top)->name << endl;
					cout << "Дата издания:           " << (*top)->year << endl;
					cout << "Количество экземпляров: " << (*top)->number << endl;
					cout << "\nУДАЛЁН!" << endl;
					Library* tmp = (*top)->next;
					delete (*top);
					(*top) = tmp;
					current = *top;
				}
				else {
					current = current->next;
					previous = *top;
				}
				end_flag++;
			}
			if ((*top) && (*top)->name != str || str1 == "no") {
				while (current) {//пока не конец
					if (current->name != str) {
						previous = current;
						current = current->next;
						i++;
					}
					else {
						cout << "\nЭлемент: " << endl;
						cout << "\n" << i << ".***********\n";
						cout << "Фамилия И.О. автора:    " << current->surname << " " << current->ins << endl;
						cout << "Название книги:         " << current->name << endl;
						cout << "Дата издания:           " << current->year << endl;
						cout << "Количество экземпляров: " << current->number << endl;
						cout << "\nВы действительно хотите удалить этот элемент?(Введите yes or no)" << endl;
						cout << "\nВаш выбор: ";
						getline(cin, str1);
						while (str1 != "yes" && str1 != "no") {
							cin.clear();
							cin.sync();
							cout << "\nВы ввели некорректное значение!" << endl;
							cout << "\nВаш выбор: ";
							getline(cin, str1);
						}
						if (str1 == "yes") {
							if (current->next) {
								previous->next = current->next;
							}
							else {
								previous->next = nullptr;
							}
							cout << "\nЭлемент: " << endl;
							cout << "\n" << i << ".***********\n";
							cout << "Фамилия И.О. автора:    " << current->surname << " " << current->ins << endl;
							cout << "Название книги:         " << current->name << endl;
							cout << "Дата издания:           " << current->year << endl;
							cout << "Количество экземпляров: " << current->number << endl;
							cout << "\nУДАЛЁН!" << endl;
							delete (current);
							i++;
							if (previous->next) {
								current = previous->next;//указатель на следующий элемент, чтобы дойти до конца
							}
							else {
								current->next = nullptr;
								current = nullptr;
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
	if (end_flag == 0) {
		cout << "\nВ библиотеке нет данных по этому запросу!" << endl;
	}
}
void Library::show(Library **top) {
	Library *current = *top;
	int i = 1;//счётчик 
	while (current) {
		cout << "\n" << i << ".***********\n";
		cout << "Фамилия И.О. автора:    " << current->surname << " " << current->ins << endl;
		cout << "Название книги:         " << current->name << endl;
		cout << "Дата издания:           " << current->year << endl;
		cout << "Количество экземпляров: " << current->number << endl;
		if (current->next) {
			current = current->next;
		}
		else {
			current = nullptr;
		}
		i++;
		cout << "\n";
	}
}
void Library::search(Library **top) {
	int flag = 0;
	int i = 1;//счётчик
	string str;
	Library *current = *top;
	Library *previous = 0;
	cout << "Введите фамилию автора: ";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите Фамилию автора: ";
		getline(cin, str);
	}
	while (current) {
		if (current->surname == str) {
			cout << "\n" << i << ".***********\n";
			cout << "Фамилия И.О. автора:    " << current->surname << " " << current->ins << endl;
			cout << "Название книги:         " << current->name << endl;
			cout << "Дата издания:           " << current->year << endl;
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
void Library::swap(Library **first, Library **second) {
	string str, str1;
	int end_flag = 0;
	Library *fstack = *first;
	Library *fprevious = 0;
	Library *new_item = new Library;
	cout << "Введите название книги: ";
	getline(cin, str);
	while (str.length() == 0) {
		cin.clear();
		cin.sync();
		cout << "\nВы ничего не ввели!" << endl;
		cout << "\nВведите название книги: ";
		getline(cin, str);
	}
	while (fstack) {
		if ((*first)->name == str) {//если первый элемент, то указатель на заголовок сместится
				cout << "\nЭлемент: " << endl;
				cout << "\n";
				cout << "Фамилия И.О. автора:    " << (*first)->surname << " " << (*first)->ins << endl;
				cout << "Название книги:         " << (*first)->name << endl;
				cout << "Дата издания:           " << (*first)->year << endl;
				cout << "Количество экземпляров: " << (*first)->number << endl;
				cout << "\nВы действительно хотите удалить этот элемент?(Введите yes or no)" << endl;
				cout << "\nВаш выбор: ";
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
					cout << "Фамилия И.О. автора:    " << (*first)->surname << " " << (*first)->ins << endl;
					cout << "Название книги:         " << (*first)->name << endl;
					cout << "Дата издания:           " << (* first)->year << endl;
					cout << "Количество экземпляров: " << (*first)->number << endl;
					cout << "\nУспешно перемещён!" << endl;
					new_item->surname = (*first)->surname;
					new_item->ins = (*first)->ins;
					new_item->name = (*first)->name;
					new_item->year = (*first)->year;
					new_item->number = (*first)->number;
					new_item->next = *second;
					(*second) = new_item;
					Library* tmp = (*first)->next;
					delete (*first);
					(*first) = tmp;
					fstack = *first;
					end_flag++;
				}
				else {
					fstack = fstack->next;
					fprevious = *first;
				}
		}
		if((*first) && (*first)->name != str || str1 == "no"){
			while (fstack) {//пока не конец
				if (fstack->name != str) {
					fprevious = fstack;
					fstack = fstack->next;
				}
				else {
					cout << "\nЭлемент: " << endl;
					cout << "\n";
					cout << "Фамилия И.О. автора:    " << fstack->surname << " " << fstack->ins << endl;
					cout << "Название книги:         " << fstack->name << endl;
					cout << "Дата издания:           " << fstack->year << endl;
					cout << "Количество экземпляров: " << fstack->number << endl;
					cout << "\nВы действительно хотите удалить этот элемент?(Введите yes or no)" << endl;
					cout << "\nВаш выбор: ";
					getline(cin, str1);
					while (str1 != "yes" && str1 != "no") {
						cin.clear();
						cin.sync();
						cout << "\nВы ввели некорректное значение!" << endl;
						cout << "\nВаш выбор: ";
						getline(cin, str1);
					}
					if (str1 == "yes") {
						if (fstack->next) {
							fprevious->next = fstack->next;
						}
						else {
							fprevious->next = nullptr;
						}
						cout << "\nЭлемент: " << endl;
						cout << "\n";
						cout << "Фамилия И.О. автора:    " << fstack->surname << " " << fstack->ins << endl;
						cout << "Название книги:         " << fstack->name << endl;
						cout << "Дата издания:           " << fstack->year << endl;
						cout << "Количество экземпляров: " << fstack->number << endl;
						cout << "\nУспешно перемещён!" << endl;
						new_item->surname = fstack->surname;
						new_item->ins = fstack->ins;
						new_item->name = fstack->name;
						new_item->year = fstack->year;
						new_item->number = fstack->number;
						new_item->next = *second;
						(*second) = new_item;
						delete (fstack);
						if (fprevious->next) {
							fstack = fprevious->next;//указатель на следующий элемент, чтобы дойти до конца
						}
						else {
							fstack->next = nullptr;
							fstack = nullptr;
						}
					}
					else {
						fprevious = fstack;
						fstack = fstack->next;
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
void Library::take_out(Library  **top)
{
	Library *old_header = *top;
	while (*top) {
		(*top) = (*top)->next;
		delete(old_header);
		old_header = *top;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	Library *top_in = nullptr;//книги в библиотеке
	Library *top_out = nullptr;//книги на руках
	Library book;//взаимодейтсвие с функциями класса
	int n;//номер пункта меню
	int end_flag = 0;//выход из программы
	int flag_v = 0;//флаг ввода
	do {
		system("cls");
		cout << "Меню:" << endl;
		cout << "1 - Добавить книги в библиотеку" << endl;
		cout << "2 - Удаление из списка библиотеки" << endl;
		cout << "3 - Посмотреть существующие списки" << endl;
		cout << "4 - Поиск по фамилии в списке библиотеки" << endl;
		cout << "5 - Взять книгу из библиотеки" << endl;
		cout << "6 - Сдать книгу в библиотеку" << endl;
		cout << "7 - О программе" << endl;
		cout << "8 - Помощь" << endl;
		cout << "9 - Выход\n" << endl;
		Protect(n, "\nВведите номер пункта меню: ", 1, 9);
		cout << "\nНажимте ENTER..." << endl;
		_getch();
		system("cls");
		switch (n) {
		case 1:
			do {
				book.set_all_data(&top_in);
				cout << "\nЕсли хотите продолжить введите 1, иначе 2" << endl;
				Protect(flag_v, "\nВаш выбор: ", 1, 2);
			} while (flag_v == 1);
			cout << "\nНажимте ENTER..." << endl;
			_getch();
			break;
		case 2:
			if (top_in) {
				flag_v = 0;
				do {
					book.del(&top_in);
					cout << "\nЕсли хотите продолжить введите 1, иначе 2" << endl;
					Protect(flag_v, "\nВаш выбор: ", 1, 2);
				} while (flag_v == 1);
			}
			else {
				cout << "\nБиблиотека пуста!" << endl;
			}
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 3:
			do {
				system("cls");
				cout << "1 - Посмотреть список библиотеки" << endl;
				cout << "2 - Посмотреть список взятых книг" << endl;
				cout << "3 - Посмотреть оба списка" << endl;
				cout << "4 - Вернуться в главное меню" << endl;
				Protect(n, "\nВведите номер пункта меню: ", 1, 4);
				cout << "\nНажимте ENTER..." << endl;
				_getch();
				system("cls");
				switch (n) {
				case 1:
					if (top_in) {
						cout << "\nКниги в библиотеке:\n" << endl;
						book.show(&top_in);
					}
					else {
						cout << "\nБиблиотека пуста!" << endl;
					}
					cout << "\nНажмите ENTER..." << endl;
					_getch();
					break;
				case 2:
					if (top_out) {
						cout << "\nКниги на руках:\n" << endl;
						book.show(&top_out);
					}
					else {
						cout << "\nВы ещё не брали книги из библиотеки!" << endl;
					}
					cout << "\nНажмите ENTER..." << endl;
					_getch();
					break;
				case 3:
					cout << "Книги из обоих списков:" << endl;
					if (top_in) {
						cout << "\nКниги в библиотеке:\n" << endl;
						book.show(&top_in);
					}
					else {
						cout << "\nВ библиотеке нет книг!\n" << endl;
					}
					if (top_out) {
						cout << "\nКниги на руках:\n" << endl;
						book.show(&top_out);
					}
					else {
						cout << "\nВы ещё не брали книги из библиотеки!\n" << endl;
					}
					cout << "Нажмите ENTER..." << endl;
					_getch();
				}
			} while (n != 4);
			break;
		case 4:
			flag_v = 0;
			if (top_in) {
				do {
					book.search(&top_in);
					cout << "\nЕсли хотите продолжить введите 1, иначе 2" << endl;
					Protect(flag_v, "\nВаш выбор: ", 1, 2);
				} while (flag_v == 1);
			}
			else {
				cout << "\nБиблиотека пуста!" << endl;
			}
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 5:
			if (top_in) {
				flag_v = 0;
				do {
					book.swap(&top_in, &top_out);
					cout << "\nЕсли хотите продолжить введите 1, иначе 2" << endl;
					Protect(flag_v, "\nВаш выбор: ", 1, 2);
				} while (flag_v == 1);
			}
			else {
				cout << "\nБиблиотека пуста!" << endl;
			}
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 6:
			if (top_out) {
				flag_v = 0;
				do {
					book.swap(&top_out, &top_in);
					cout << "\nЕсли хотите продолжить введите 1, иначе 2" << endl;
					Protect(flag_v, "\nВаш выбор: ", 1, 2);
				} while (flag_v == 1);
			}
			else {
				cout << "\nВы ещё не брали книг из библиотеки!" << endl;
			}
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 7:
			cout << "Вариант №15. Классы\nВерсия 1.0\n2019 г.\nРазработчик Бровцын Олег" << endl;
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 8:
			cout << "Задание:\n" << endl;
			cout << "Описать класс, реализующий стек и работу с ним.\n1.)Класс должен содержать следующие сведения о книгах в библиотеке:\n*фамилию и инициалы автора;\n*название;\n*год издания;*количество экземпляров данной книги в библиотеке." << endl;
			cout << "2.)В классе должны быть реализованы следующие операции над стеком:\n*добавление данных о книгах вновь поступивших в библиотеку;\n*удаление данных о списываемой книге, название которой введено с клавиатуры;\n*вывод информации обо всех книгах в библиотеке;*по запросу выводится информация обо всех книгах автора,\nимеющихся в библиотеке, чья фамилия введена с клавиатуры." << endl;
			cout << "3.)Программа должна обеспечивать диалог с помощью меню." << endl;
			cout << "4.)В программе должны быть созданы два экземпляра класса:\nкниги в библиотеке и выданные читателям.Когда читатель берет книгу в\nбиблиотеке, информация о ней (по введенному названию книги) должна быть\nавтоматически удалена из списка книг в библиотеке и переведена в список\nкниг у читателей. Когда читатель сдает книгу в библиотеку, информация о\nней должна быть автоматически удалена из списка книг у читателей и\nперенесена в список книг в библиотеке. При выводе информации о книгах,\nпользователь должен выбрать какой список выводить (книги в библиотеке\nили у читателей), либо вывести все книги из обоих списков." << endl;
			cout << "\nНажмите ENTER" << endl;
			_getch();
			break;
		case 9:
			cout << "До свидания!" << endl;
			book.take_out(&top_in);
			book.take_out(&top_out);
			end_flag++;
		}
	} while (end_flag == 0);
	cout << "\nНажмите ENTER...." << endl;
	_getch();
	return 0;
}
void Protect(int &n, string temp, int m, int k) {
	int flag = 0;
	char str[80];
	do {//проверка ввода
		flag = 0;
		cout << temp;
		cin.getline(str, 79);
		if (!atoi(str)) {
			cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
			flag++;
		}
		else {
			n = atoi(str);
			if (n < m || n > k) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
				flag++;
			}
		}
	} while (flag != 0);
	cout << "\n";
}


