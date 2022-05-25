
#include "Funk.h"

#include <iostream>

void create(int** array, int* pY)
{             
	array[0] = new int[*pY+1]; //массив 0 не входит в массивы что должны быть созданны,
	//а следовательно должен быть длинее на 1 и массивов должно быть больше на 1. Это решается выставлением в циклах условия <= вместо <.
	
	array[0][0] = *pY;//число остается прежним.
	delete pY; //т.к размер теперь хранится в массиве переменная больше не нужна.

	for (int i = 1; i <= array[0][0]; i++) {array[0][i] = (rand() % 10)+1;} //заполнение массива размеров строк.

	for (int i = 1; i <= array[0][0]; i++) {array[i] = new int[array[0][i]];} //создание массивов.

	for (int i = 1; i <= array[0][0]; i++)  //заполнение массивов.
	{
		for (int j = 0; j < array[0][i]; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
}

void print(int** array)
{
	for (int i = 0; i <= array[0][0]; i++)  //технически вывод массива 0 не нужен - он рабочей частью не является,
		                                   //ниже есть часть кода с условием 0, что бы было удобнее проверять.
	{
		std::cout << "строка N" << i << "   ";
		if (i > 9) std::cout<< "\b";
		std::cout << "| ";
		for (int j = 0; j < array[0][i]; j++)
		{
			if(!i) 
			{
				std::cout << array[i][j+1] << " ";
				if (array[i][j+1] < 10)std::cout << " ";
				std::cout << "| ";
			}
		else 
		{
			std::cout << array[i][j] << " ";
			if (array[i][j] < 10)std::cout << " ";
			std::cout << "| ";
		}
		}
		std::cout << "\n";
	}
}

void Choise(int choise, int** array)
{
	do {
		std::cout << "Введите 1 для добавления строки.\n";
		std::cout << "Введите 2 для удаления строки.\n";
		std::cout << "Введите 3 для удаления элемента строки.\n";
		std::cout << "Введите 4 для добавления элемента строки.\n";
		std::cin >> choise;
		std::cout << "\n";
		if (choise < 0 || choise > 5) std::cout << "Введена неверная опция повторите ввод!!!\n";
	} while (choise < 0 && choise > 4);
	
	switch (choise)
	{
	case 1:
		void (*x1)(int**);
		x1=createNewLine;
		(*x1)(array);
		break;
	case 2:
		void (*x2)(int, int**);
		x2 = deleteLine;
		int deleteL;
		std::cout << "Введите номер удаляемой строки ";
		std::cin >> deleteL;
		std::cout << "\n";
		(*x2)(deleteL, array);
		break;
	case 3:
		void (*x3)(int, int, int**);
		x3 = deleteNum;
		int deleteY, deleteX;
		std::cout << "Введите номер строки удаляемого числа ";
		std::cin >> deleteY;
		std::cout << "\n";
		std::cout << "Введите индекс удаляемого числа ";
		std::cin >> deleteX;
		std::cout << "\n";
		(*x3)(deleteY, deleteX, array);
		break;
	case 4:
		void (*x4)(int, int**);
		x4 = addNum;
		int createY;
		std::cout << "Введите номер строки для добавления числа ";
		std::cin >> createY;
		std::cout << "\n";
		(*x4)(createY, array);
		break;
	case 0: std::cout << "Завершение работы.\n";
		break;
	}
}

void createNewLine(int** arrayOld)
{
	arrayOld[0][0] += 1;//сразу увеличиваем число отвечающее за кол-во строк.
	int** arrayNew = new int* [arrayOld[0][0] + 1];    //создаем новый массив указателей.
	arrayNew[0] = new int[arrayOld[0][0]+1];          //создаем новую массив - величины строк.
	arrayNew[0][arrayOld[0][0]] = (rand() % 9) + 1;  //заполняем значение отвечающее за размер нового массива

	for (int i = 0; i < arrayOld[0][0]; i++){arrayNew[0][i] = arrayOld[0][i];} //заполнение массива величины массивов в новом массиве.
	
	arrayNew[arrayNew[0][0]] = new int[arrayNew[0][arrayNew[0][arrayNew[0][0]]]];
	delete[] arrayOld[0];  //удаляем старый массив размеров строк.
	
	for (int i = 0; i < arrayNew[0][arrayNew[0][0]]; i++) { arrayNew[arrayNew[0][0]][i] = (rand() % 9) + 1;} //заполняем новый массив.
	for (int i = 1; i < arrayNew[0][0]; i++) { arrayNew[i] = arrayOld[i]; } //переносим указатели на массивы из старого массива в новый.

	int** arrayDel = arrayOld; //сохраняем указатель на старый массив указателей на массивы.
	arrayOld = arrayNew;      //передаем в адрес старого массива адрес нового массива.
	delete[] arrayDel;       //удаляем старый массив.
}

void deleteLine(int Y, int** array)
{
	if (Y <= 0) Y = 1;
	if (Y > array[0][0]) Y = array[0][0];            //устраняем возможные ошибки

	delete[] array[Y];                              //удаляем ненужный массив.

	array[0][0] -= 1;                              //сразу уменьшаем число отвечающее за кол-во строк.
	int** arrayNew = new int* [array[0][0] + 1];  //создаем новый указатель на массив указателей.
	arrayNew[0] = new int[array[0][0] + 1];      //создаем новый массив размеров массивов.

	for (int i = 0; i <= array[0][0]; i++)     //заполняем новый массив размеров массивов.
	{
		bool j = 0;
		if (i == Y)j=1;
		arrayNew[0][i] = array[0][i+j];
	}

	delete[] array[0];                      //Удаляем старый массив размеров массивов.

	for (int i = 1; i <= array[0][0]; i++) //передаем указатели массивов в новый массив указателей массивов.
	{
		bool j = 0;
		if (i >= Y)j=1;
		arrayNew[i] = array[i+j];
	}
	int** arrayDel = array; //сохраняем указатель на старый массив указателей на массивы.
	array = arrayNew;      //передаем в адрес старого массива адрес нового массива.
	delete[] arrayDel;    //удаляем старый массив.
}

void deleteNum(int Y, int X, int** array)
{
	X -= 1;
	array[0][Y] -= 1;                      //Вносим изменения в размер и корректируем ввод X.
	if (Y <= 0)Y = 1;
	if (Y > array[0][0])Y = array[0][0];
	if (X < 0)X = 0;
	if (Y > array[0][0])Y = array[0][0];  //Устраняем возможные ошибки.

	int* newRow = new int[array[0][Y]];  //Создаем новый массив.

	for (int i=0; i< array[0][Y]; i++)
	{
		bool j = 0;
		if (i >= X)j = 1;
		newRow[i] = array[Y][i+j];
	}

	int* arrayDel = array[Y]; //сохраняем указатель на старый массив.
	array[Y] = newRow;      //передаем в адрес старого массива адрес нового массива.
	delete[] arrayDel;     //удаляем старый массив.
}

void addNum(int Y, int** array)
{
	array[0][Y] += 1;                      //Вносим изменения в размер и корректируем ввод X.
	if (Y <= 0)Y = 1;
	if (Y > array[0][0])Y = array[0][0];  //Устраняем возможные ошибки.

	int* newRow = new int[array[0][Y]];  //Создаем новый массив.

	for (int i = 0; i < array[0][Y]; i++) //Переносим данные в новый массив.
	{
		newRow[i] = array[Y][i];
	}
	newRow[array[0][Y]] = (rand() % 9) + 1;//Заполняем новое место.

	int* arrayDel = array[Y]; //сохраняем указатель на старый массив.
	array[Y] = newRow;      //передаем в адрес старого массива адрес нового массива.
	delete[] arrayDel;     //удаляем старый массив.
}
