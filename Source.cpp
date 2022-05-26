//Реализовать двумерный динамический зубчатый массив, с хранением размеров строк в нулевой строке.
//Длина строк задается рандомно. Элементы заполняются случайными числами.
//Реализуйте добавление строки, удаление строки. Добавление и удаление элемента в строку.

#include <iostream>
#include "Funk.h"
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

	int* pY = new int;
	std::cout << "Ââåäèòå êîë-âî ñòðîê ";
	std::cin >> *pY;
	std::cout << "\n";
	int** ppArray = new int* [*pY+1];

	void (*cr)(int**, int*);
	void (*pr)(int**);
	void (*ch)(int, int**);
	pr = print;
	cr = create;
	ch = Choise;

	(*cr)(ppArray, pY);

	int choise{0};
	do
	{
		print(ppArray);
		Choise(choise, ppArray);
	} while (choise > 0&&choise<=4);

	return 0;
}
