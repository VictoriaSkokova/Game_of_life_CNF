#include "iostream"
#include "fstream"
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream file;
	file.open("Game_of_life.txt");
	file << "Составим КНФ для уравнений, описывающих состояние клетки,относительно соседей"<<"\n";
	file << "Обусловимся, что значение в клетке - 0 означает, что клетка мертва, 1 - что она жива." << "\n";
	file << "Рассмотрим правила:"<<"\n"<<"1. Если клетка имеет менее 2 соседей, то на следующем шаге она умирает, то есть ее значение обращается в 0"<<"\n";
	file << "2. Если у клетки 2 соседа, то она сохраняет свое значение" << "\n";
	file << "3. Если у клетки 3 соседа, то она оживает, то есть значение становится равно 1" << "\n";
	file << "4. Если у клетки больше 3 соседей, то она умирает, то есть ее значение становится равно 0" << "\n";
	file << "Рассмотрим поле 3 на 3 и составим уравнения для центральной клетки, то есть клетки е: " << "\n";
	file << "a b c" << "\n";
	file << "d e f" << "\n";
	file << "g h i" << "\n";
	file << "Нам необходимо составить уравнения только для случаев 2 и 3, в остальных случаях клетка умирает и ее значение обращается в 0" << "\n";
	file << "\n";
	file << "Полученные уравнения: \n";

	int **Array = new int*[84]; // две строки в массиве
	for (int count = 0; count < 84; count++)
		Array[count] = new int[8];

	int **KNF = new int*[512]; // две строки в массиве
	for (int count = 0; count < 512; count++)
		KNF[count] = new int[10];

	Generate(Array);
	//Вывод уравнений в файл
	/*buleva(Array);*/
	//___________________________________________________________________________________
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0)
				file << "(";
			if (Array[i][j] == 1)
			{
				file << "¬";
			}
			switch (j)
			{
			case 0:
			{
				file << "a";
				break;
			}
			case 1:
			{
				file << "b";
				break;
			}
			case 2:
			{
				file << "c";
				break;
			}
			case 3:
			{
				file << "d";
				break;
			}
			case 4:
			{
				file << "f";
				break;
			}
			case 5:
			{
				file << "g";
				break;
			}
			case 6:
			{
				file << "h";
				break;
			}
			case 7:
			{
				file << "i)";
				break;
			}
			}

		}
		if (i != 83)
			file << "v";
	}


	for (int i = 56; i < 84; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0)
				file << "(";
			if (Array[i][j] == 1)
			{
				file << "¬";
			}
			switch (j)
			{
			case 0:
			{
				file << "a";
				break;
			}
			case 1:
			{
				file << "b";
				break;
			}
			case 2:
			{
				file << "c";
				break;
			}
			case 3:
			{
				file << "d";
				break;
			}
			case 4:
			{
				file << "f";
				break;
			}
			case 5:
			{
				file << "g";
				break;
			}
			case 6:
			{
				file << "h";
				break;
			}
			case 7:
			{
				file << "i)е";
				break;
			}
			}

		}
		if (i != 83)
			file << "v";
	}
	//___________________________________________________________________________________
	create_knf(Array, KNF);
	file << "\n";
	file << "\n"<<"Построим КНФ по таблице истинности: \n";
	file << "abcdefghiF \n";
	//___________________________________________________________________________________
		for (int i = 0; i < 512; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				file << KNF[i][j];
			}
			file << "\n";
		}
	//___________________________________________________________________________________
	//Вывод таблицы истинности в файл
	make_knf(KNF);
	//___________________________________________________________________________________
	file << "\n";
	file << "Полученная КНФ имеет вид: \n";
	//file << "\n";
	for (int i = 0; i < 512; i++)
	{
		if (KNF[i][9] == 0)
		{
			for (int j = 0; j < 9; j++)
			{
				if (j == 0)
					file << "(";
				if (KNF[i][j] == 1)
				{
					file << "¬";
				}
				switch (j)
				{
				case 0:
				{
					file << "av";
					break;
				}
				case 1:
				{
					file << "bv";
					break;
				}
				case 2:
				{
					file << "cv";
					break;
				}
				case 3:
				{
					file << "dv";
					break;
				}
				case 4:
				{
					file << "ev";
					break;
				}
				case 5:
				{
					file << "fv";
					break;
				}
				case 6:
				{
					file << "gv";
					break;
				}
				case 7:
				{
					file << "hv";
					break;
				}
				case 8:
				{
					file << "i)";
					break;
				}
				}

			}
		}
	}
	//___________________________________________________________________________________
	//Вывод кнф в файл
	file.close();
	system("pause");
	return 0;
}
