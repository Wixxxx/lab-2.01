// Lab 2.01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//Функция поиска в зеленой области
int Max_negative(int(**matrix), int n, int* i_of_max_negative, int* j_of_max_negative) {

	int max_negative = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (matrix[i][j] < max_negative)
			{
				max_negative = matrix[i][j];
				(*i_of_max_negative) = i;
				(*j_of_max_negative) = j;
			}
		}
	}
	return max_negative;
}


//Функция поиска в красной области
int Min_positive(int(**matrix), int n, int* i_of_min_positive, int* j_of_min_positive) {

	int min_positive = 10000;
	int k = 0;


	for (int i = n - 1; i > n / 2; i--)
	{
		for (int j = k; j < n - k; j++)
		{
			if (matrix[i][j] >= 0 && min_positive > matrix[i][j])
			{
				min_positive = matrix[i][j];
				*i_of_min_positive = i;
				*j_of_min_positive = j;
			}
		}
		k++;
	}
	return min_positive;
}

void Print_matrix(int** matrix, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void Create_matrix_and_other(int a, int b, int n) {
	srand(time(NULL));
	//Создание динамической матрицы
	int** matrix;
	matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];


	//Заполнение матрицы рандомными значениями и выведение на экран
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % (a - b + 1) + a;
		}
	}

	Print_matrix(matrix, n);

	cout << endl;
	int i_of_max_negative = 0, j_of_max_negative = 0, i_of_min_positive = 0, j_of_min_positive = 0;

	int min_positive = Min_positive(matrix, n, &i_of_min_positive, &j_of_min_positive);
	int max_negative = Max_negative(matrix, n, &i_of_max_negative, &j_of_max_negative);

	cout << "Максимальный среди отрицательных это — " << max_negative << endl;
	cout << "Минимальный среди положительных это — " << min_positive << endl;
	cout << endl;

	//Меняем местами те самые два элемента
	matrix[i_of_max_negative][j_of_max_negative] = min_positive;
	matrix[i_of_min_positive][j_of_min_positive] = max_negative;
	cout << "Позиция макстимального среди отрицательных элементов: " << i_of_max_negative + 1 << " строка и " << j_of_max_negative + 1 << endl;
	cout << "Позиция минимального среди положительных элементов: " << i_of_min_positive + 1 << " строка и " << j_of_min_positive + 1 << endl;

	//Выводим матрицу после смены позиции
	cout << "Новая матрица:" << endl;
	Print_matrix(matrix, n);

	//Удаление матрицы
	for (int i = 0; i < n; i++)
		delete[] matrix[i];

}


int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, n;
	int k = 0;
	bool check = true;
	do {
		if (k == 1) {
			cout << "Хотите еще? \nНажмите 1 чтобы продолжить\nНажмите 0 чтобы остановить\n";
			cin >> k;

			while (k < 0 && k > 1) {
				cout << "Неверное знвчение.\nНажмите 1 чтобы продолжить\nНажмите 0 чтобы остановить\n";
				cin >> k;
			}
			if (k == 0) check = false;
		}

		if (!check)break;

		cout << "Введите a: ";
		cin >> a;

		cout << "Введите b (b > a): ";
		cin >> b;

		while (b < a)
		{
			cout << "Введите b (b > a): ";
			cin >> b;
		}

		cout << "Введите размер матрицы: ";
		cin >> n;

		while (n <= 0)
		{
			cout << "Значения должны быть больше чем 0. Пожалуйста, введите занова." << endl;

			cout << "Введите размер матрицы: ";
			cin >> n;
		}

		Create_matrix_and_other(a, b, n);

		k = 1;
	} while (k = 1);

	cout << "Досвидания!";
}