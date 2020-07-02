/*
*Вариант №15
Написать программу, которая считывает текст из файла и выводит 
на экран сначала вопросительные, а затем восклицательные предложения.
*Версия 1.0
*2019 г.
*Разработчик Бровцын Олег
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL,"rus");
	string str;//принимающая строка
	char path[100];//путь к файлу
	int n;//длина строки
	int from;//Начало предложения
	int to;//Конец предложения
	int flag = 0;//флаг на наличие нужных предложений
	int flagr = 0;//флаг заглавной буквы
	int point = 0;//точка отсчёта от заглавной буквы(начало самого предложения)
	cout << "ЗАДАНИЕ:" << endl;
	cout << "Написать программу, которая считывает текст из файла и выводит" << endl;
	cout << "на экран сначала вопросительные, а затем восклицательные предложения." << endl;
	cout << "\nПеред началом работы убедитесь, что вы создали текстовый файл и внесли в него информацию" << endl;
	cout << "Нажмите ENTER";
	_getch();
	do {//цикл для многократного повторения действий программы
		system("cls");
		cout << "Если вы хотите выйти из программы, введите stop" << endl;
		cout << "Укажите путь к файлу:";
		cin.getline(path, 100);
		if (!strcmp(path, "stop")) {
			cout << "До свидания!" << endl;
		}
		else {
			ifstream file(path);
			if (!file.is_open()) {//проверка на успешность открытия файла
				cout << "\nError! File is invalid" << endl;
			}
			else {
				cout << "\nExcellent!! Файл успешно открыт!" << endl;
				string end_flag;//начало проверки на пустоту файла
				getline(file, end_flag);
				if (file.eof() && end_flag.empty()) {
					cout << "\nФайл пуст!" << endl;
				}
				else {
					file.clear();
					file.seekg(0);//конец проверки на пустоту и возвращение на начало файла
					cout << "\nИсходный текст в файле:\n" << endl;
					while (!file.eof()) {
						str = "";
						getline(file, str);
						cout << str << endl;
					}
					file.clear();
					file.seekg(0);
					cout << "\nНажмите ENTER" << endl;
					_getch();
					system("cls");
					cout << "Результат обработки:" << endl;
					cout << "\nВопросительные предложения:\n";
					while (!file.eof()) {
						from = 0;
						to = 0;
						flagr = 0;
						str = "";
						getline(file, str);
						n = str.size();
						for (int i = 0; i < n; i++) {
							if (str[i] == '?' || str[i] == '!' || str[i] == '.') {
								if (str[i] == '!' || str[i] == '.') {
									from = i + 1;//сдвиг на одну позицию вправо
								}
								to = i;
								if (str[to] == '?') {
									cout << " ";
									for (int j = from; j <= to; j++) {
										if (((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'А' && str[j] <= 'Я')) && flagr == 0) {//поиск начала предложения
											point = j;
											flagr++;
										}
										if (j >= point && flagr > 0) {
											cout << str[j];//посимвольно выводим предложение
										}
									}
									cout << "\n";
									from = to + 1;
									flag++;
									flagr = 0;
								}
							}
						}
					}
					if (flag == 0) {
						cout << "\nВ этом файле нет вопросительных предложений\n" << endl;
					}
					file.clear();
					file.seekg(0);//возвращение в начало
					cout << "\nВосклицательные предложения:\n";
					flag = 0;
					while (!file.eof()) {
						from = 0;
						to = 0;
						flagr = 0;
						str = "";
						getline(file, str);
						n = str.size();
						for (int i = 0; i < n; i++) {
							if (str[i] == '?' || str[i] == '!' || str[i] == '.') {
								if (str[i] == '?' || str[i] == '.') {
									from = i + 1;
								}
								to = i;
								if (str[to] == '!') {
									cout << " ";
									for (int j = from; j <= to; j++) {
										if (((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'А' && str[j] <= 'Я')) && flagr == 0) {
											point = j;
											flagr++;
										}
										if (j >= point && flagr > 0) {
											cout << str[j];
										}
									}
									cout << "\n";
									from = to + 1;
									flag++;
									flagr = 0;
								}
							}
						}
					}
					if (flag == 0) {
						cout << "\nВ этом файле нет восклицательных предложений\n" << endl;
					}
				}
				file.close();
			}
		}
		cout << "\nНажмите ENTER, чтобы продолжить" << endl;
		_getch();
	}while (strcmp(path, "stop"));
	return 0;
}


