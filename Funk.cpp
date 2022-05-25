
#include "Funk.h"

#include <iostream>

void create(int** array, int* pY)
{             
	array[0] = new int[*pY+1]; //������ 0 �� ������ � ������� ��� ������ ���� ��������,
	//� ������������� ������ ���� ������ �� 1 � �������� ������ ���� ������ �� 1. ��� �������� ������������ � ������ ������� <= ������ <.
	
	array[0][0] = *pY;//����� �������� �������.
	delete pY; //�.� ������ ������ �������� � ������� ���������� ������ �� �����.

	for (int i = 1; i <= array[0][0]; i++) {array[0][i] = (rand() % 10)+1;} //���������� ������� �������� �����.

	for (int i = 1; i <= array[0][0]; i++) {array[i] = new int[array[0][i]];} //�������� ��������.

	for (int i = 1; i <= array[0][0]; i++)  //���������� ��������.
	{
		for (int j = 0; j < array[0][i]; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
}

void print(int** array)
{
	for (int i = 0; i <= array[0][0]; i++)  //���������� ����� ������� 0 �� ����� - �� ������� ������ �� ��������,
		                                   //���� ���� ����� ���� � �������� 0, ��� �� ���� ������� ���������.
	{
		std::cout << "������ N" << i << "   ";
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
		std::cout << "������� 1 ��� ���������� ������.\n";
		std::cout << "������� 2 ��� �������� ������.\n";
		std::cout << "������� 3 ��� �������� �������� ������.\n";
		std::cout << "������� 4 ��� ���������� �������� ������.\n";
		std::cin >> choise;
		std::cout << "\n";
		if (choise < 0 || choise > 5) std::cout << "������� �������� ����� ��������� ����!!!\n";
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
		std::cout << "������� ����� ��������� ������ ";
		std::cin >> deleteL;
		std::cout << "\n";
		(*x2)(deleteL, array);
		break;
	case 3:
		void (*x3)(int, int, int**);
		x3 = deleteNum;
		int deleteY, deleteX;
		std::cout << "������� ����� ������ ���������� ����� ";
		std::cin >> deleteY;
		std::cout << "\n";
		std::cout << "������� ������ ���������� ����� ";
		std::cin >> deleteX;
		std::cout << "\n";
		(*x3)(deleteY, deleteX, array);
		break;
	case 4:
		void (*x4)(int, int**);
		x4 = addNum;
		int createY;
		std::cout << "������� ����� ������ ��� ���������� ����� ";
		std::cin >> createY;
		std::cout << "\n";
		(*x4)(createY, array);
		break;
	case 0: std::cout << "���������� ������.\n";
		break;
	}
}

void createNewLine(int** arrayOld)
{
	arrayOld[0][0] += 1;//����� ����������� ����� ���������� �� ���-�� �����.
	int** arrayNew = new int* [arrayOld[0][0] + 1];    //������� ����� ������ ����������.
	arrayNew[0] = new int[arrayOld[0][0]+1];          //������� ����� ������ - �������� �����.
	arrayNew[0][arrayOld[0][0]] = (rand() % 9) + 1;  //��������� �������� ���������� �� ������ ������ �������

	for (int i = 0; i < arrayOld[0][0]; i++){arrayNew[0][i] = arrayOld[0][i];} //���������� ������� �������� �������� � ����� �������.
	
	arrayNew[arrayNew[0][0]] = new int[arrayNew[0][arrayNew[0][arrayNew[0][0]]]];
	delete[] arrayOld[0];  //������� ������ ������ �������� �����.
	
	for (int i = 0; i < arrayNew[0][arrayNew[0][0]]; i++) { arrayNew[arrayNew[0][0]][i] = (rand() % 9) + 1;} //��������� ����� ������.
	for (int i = 1; i < arrayNew[0][0]; i++) { arrayNew[i] = arrayOld[i]; } //��������� ��������� �� ������� �� ������� ������� � �����.

	int** arrayDel = arrayOld; //��������� ��������� �� ������ ������ ���������� �� �������.
	arrayOld = arrayNew;      //�������� � ����� ������� ������� ����� ������ �������.
	delete[] arrayDel;       //������� ������ ������.
}

void deleteLine(int Y, int** array)
{
	if (Y <= 0) Y = 1;
	if (Y > array[0][0]) Y = array[0][0];            //��������� ��������� ������

	delete[] array[Y];                              //������� �������� ������.

	array[0][0] -= 1;                              //����� ��������� ����� ���������� �� ���-�� �����.
	int** arrayNew = new int* [array[0][0] + 1];  //������� ����� ��������� �� ������ ����������.
	arrayNew[0] = new int[array[0][0] + 1];      //������� ����� ������ �������� ��������.

	for (int i = 0; i <= array[0][0]; i++)     //��������� ����� ������ �������� ��������.
	{
		bool j = 0;
		if (i == Y)j=1;
		arrayNew[0][i] = array[0][i+j];
	}

	delete[] array[0];                      //������� ������ ������ �������� ��������.

	for (int i = 1; i <= array[0][0]; i++) //�������� ��������� �������� � ����� ������ ���������� ��������.
	{
		bool j = 0;
		if (i >= Y)j=1;
		arrayNew[i] = array[i+j];
	}
	int** arrayDel = array; //��������� ��������� �� ������ ������ ���������� �� �������.
	array = arrayNew;      //�������� � ����� ������� ������� ����� ������ �������.
	delete[] arrayDel;    //������� ������ ������.
}

void deleteNum(int Y, int X, int** array)
{
	X -= 1;
	array[0][Y] -= 1;                      //������ ��������� � ������ � ������������ ���� X.
	if (Y <= 0)Y = 1;
	if (Y > array[0][0])Y = array[0][0];
	if (X < 0)X = 0;
	if (Y > array[0][0])Y = array[0][0];  //��������� ��������� ������.

	int* newRow = new int[array[0][Y]];  //������� ����� ������.

	for (int i=0; i< array[0][Y]; i++)
	{
		bool j = 0;
		if (i >= X)j = 1;
		newRow[i] = array[Y][i+j];
	}

	int* arrayDel = array[Y]; //��������� ��������� �� ������ ������.
	array[Y] = newRow;      //�������� � ����� ������� ������� ����� ������ �������.
	delete[] arrayDel;     //������� ������ ������.
}

void addNum(int Y, int** array)
{
	array[0][Y] += 1;                      //������ ��������� � ������ � ������������ ���� X.
	if (Y <= 0)Y = 1;
	if (Y > array[0][0])Y = array[0][0];  //��������� ��������� ������.

	int* newRow = new int[array[0][Y]];  //������� ����� ������.

	for (int i = 0; i < array[0][Y]; i++) //��������� ������ � ����� ������.
	{
		newRow[i] = array[Y][i];
	}
	newRow[array[0][Y]] = (rand() % 9) + 1;//��������� ����� �����.

	int* arrayDel = array[Y]; //��������� ��������� �� ������ ������.
	array[Y] = newRow;      //�������� � ����� ������� ������� ����� ������ �������.
	delete[] arrayDel;     //������� ������ ������.
}
