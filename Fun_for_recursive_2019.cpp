#include "pch.h"
#include "functions.h"

using namespace std;

double change(int n, double u, double v) {
	static int i = 1;//счётчик
	static double sum = 0;//сумма
	static double a;//пошагово изменяемое действительное число №1
	static double b;//пошагово изменяемое действительное число №2
	static int temp1;//факториал
	double s = 0;//временная переменная для сложения
	double temp = 0;//переменная, которая будет хранить предыдущую переменную a
	if (i == 1) {
		a = u;
		b = v;
		sum = 0;
		temp1 = 1;
	}
	s = (a*b) / (temp1 *= (i + 1));
	temp = a;
	a = 2 * b + a;
	b = 2 * (temp*temp) + b;
	sum += s;
	i++;
	if (i > n) {
		a = 0;
		b = 0;
		i = 1;
		return sum;
	}
	else {
		return change(n, a, b);
	}
}
double proverka(double u, double v, int n) {
	double a = 0;
	double b = 0;
	double sum = 0;
	int temp1 = 0;
	double temp = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			a = u;
			b = v;
			temp1 = 1;
		}
		else {
			temp = a;
			a = 2 * b + a;
			b = 2 * (temp*temp) + b;
			temp1 *= i;
		}
		sum = sum + (a*b) / (temp1*(i + 1));
	}
	return sum;
}
L protector(int i) {
	int flag = 0;
	L first;
	char str[80];
	do {
		flag = 0;
		if (i == 1 || i == 2) {
			cout << "(от -999,99 до 999,99)(Вместо точки запятая!!)" << endl;
			if (i == 1) {
				cout << "\nВведите первое действительное число: ";
			}
			else {
				cout << "\nВведите второе действительное число: ";
			}
			cin.getline(str, 79);
			if (!atof(str)) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
				flag++;
			}
			else {
				first.n = atof(str);
				if (first.n > 999.99 || first.n < -999.99) {
					cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
					flag++;
				}
			}
		}else {
			cout << "\nВведите натуральное число(от 0 до 8): ";
			cin.getline(str, 79);
			if (!atoi(str)) {
				cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
				flag++;
			}
			else {
				first.m = atoi(str);
				if (first.m < 0 || first.m > 8) {
					cout << "Вы ввели недопустимое значение! Повторите ввод\n\n";
					flag++;
				}
			}
		}
	} while (flag != 0);
	return first;
}
void output(int n, double u, double v, double result_1, double result_2, int flag_1, int flag_2, int &flag_write) {
	if (flag_1 > 0 || flag_2 > 0) {
		cout << "При u = " << u << " ; v = " << v << " ; n = " << n << endl;
		if (flag_1 > 0) {
			cout << "\nРезультат рекурсии: " << result_1 << endl;
		}
		else {
			cout << "\nЧерез рекурсию вы ещё не решали!" << endl;
		}
		if (flag_2 > 0) {
			cout << "\nРезультат цикла: " << result_2 << endl;
		}
		else {
			cout << "\nЧерез цикл вы ещё не решили!" << endl;
		}
		if (flag_1 > 0 && flag_2 > 0 && flag_write == 0) {
			cout << "\nВы хотите записать данные в файл(Введите yes or no)?" << endl;
			string str_temp;
			cout << "\nВаш выбор: ";
			getline(cin, str_temp);
			while (str_temp.length() == 0 || (str_temp != "yes" && str_temp != "no")) {
				cin.clear();
				cin.sync();
				cout << "Вы ввели некорректное значение!" << endl;
				cout << "\nВаш выбор: ";
				getline(cin, str_temp);
			}
			if (str_temp == "yes") {
				cout << "\nВведите название файла(с расширением): ";
				getline(cin, str_temp);
				while (str_temp.length() == 0) {
					cin.clear();
					cin.sync();
					cout << "Вы ничего не ввели!" << endl;
					cout << "\nВведите название файла(с расширением): ";
					getline(cin, str_temp);
				}
				ofstream file(str_temp, ios::app);
				if (file.is_open()) {
					cout << "Файл для записи данных успешно открыт!" << endl;
					file << "При u = " << u << " ; v = " << v << " ; n = " << n << endl;
					file << "\nРезультат рекурсии: " << result_1 << endl;
					file << "\nРезультат цикла: " << result_2 << endl;
					file << "\n";
					cout << "\nДанные успешно записаны в файл" << endl;
					flag_write++;
					file.close();
				}
				else {
					cout << "Файл не удалось открыть, данные не будут записаны в файл" << endl;
				}

			}
		}
	}
	else {
		cout << "Вы  ещё не решили одну задачу!" << endl;
	}
}
void about() {
	cout << "Вариант 15. Задание в Абрамове № 99\nВерсия 1.0\n2019 г.\nРазработчик Бровцын Олег" << endl;

}
void help() {
	cout << "Задание:\nПусть:\na[1] = u, b[1] = v, a[k] = 3*b[k-1] + a[k-1];\nb[k] = 2*(a[k-1])^2 + b[k-1]; k = 2, 3....\n\n";
	cout << "Даны действительные u, v и натуральное n. Найти:\n\nСУММА[от k до n]((a[k]*b[k])/(k+1)!) где k = 1, 2....." << endl;
}