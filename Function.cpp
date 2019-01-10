#include "iostream"
#include "fstream"
#include <cmath>

using namespace std;


void Generate(int **Arr)
{
	int n = 84, m = 8;
	int min = 31, max = 248, num = min, dva = 1;
	int check = 0;
	for (int i = 0; i < 56; i++)
	{
		while (check != 5)
		{
			dva = 1;
			check = 0;
			while (dva < 256)
			{
				if ((num & dva) != 0)
				check++;
				dva = 2 * dva;
			}
			num++;
			
		}
		    num--;
			for (int j = 0; j < 8; j++)
			{
				dva = dva / 2;
				if ((num & dva) != 0)
					Arr[i][j] = 1;
				else
					Arr[i][j] = 0;
			}
			num++;
			check = 0;
	}

	max = 252;
	min = 63;
	num = min;
	dva = 1;

	for (int i = 56; i < 84; i++)
	{
		while (check != 6)
		{
			dva = 1;
			check = 0;
			while (dva < 256)
			{
				if ((num & dva) != 0)
					check++;
				dva = 2 * dva;
			}
			num++;
			
		}
		    num--;
			for (int j = 0; j < 8; j++)
			{
				dva = dva / 2;
				if ((num & dva) != 0)
					Arr[i][j] = 1;
				else
					Arr[i][j] = 0;
			}
			check = 0;
			num++;
	}


	for (int i = 0; i < 84; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << Arr[i][j];
		}
		cout << "\n";
	}
}



void buleva(int **Arr) //перенести в файл
{
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0)
				cout << "(";
			if (Arr[i][j] == 1)
			{
				cout << "¬";
			}
			switch (j)
			{
				case 0:
				{
					cout << "a";
					break;
				}
				case 1:
				{
					cout << "b";
					break;
				}
				case 2:
				{
					cout << "c";
					break;
				}
				case 3:
				{
					cout << "d";
					break;
				}
				case 4:
				{
					cout << "f";
					break;
				}
				case 5:
				{
					cout << "g";
					break;
				}
				case 6:
				{
					cout << "h";
					break;
				}
				case 7:
				{
					cout << "i)";
					break;
				}
			}
			
		}
		if (i != 83)
		cout << "\\/";
	}


	for (int i = 56; i < 84; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0)
				cout << "(";
			if (Arr[i][j] == 1)
			{
				cout << "¬";
			}
			switch (j)
			{
			case 0:
			{
				cout << "a";
				break;
			}
			case 1:
			{
				cout << "b";
				break;
			}
			case 2:
			{
				cout << "c";
				break;
			}
			case 3:
			{
				cout << "d";
				break;
			}
			case 4:
			{
				cout << "f";
				break;
			}
			case 5:
			{
				cout << "g";
				break;
			}
			case 6:
			{
				cout << "h";
				break;
			}
			case 7:
			{
				cout << "i)е";
				break;
			}
			}

		}
		if (i != 83)
			cout << "\\/";
	}
}


void create_knf(int **Arr, int **knf) //Вывод таблицы истинности в файл
{
	//9 на 256
	int num = 0, dva = 128;
	for (int i = 0; i < 256; i++) //заполнение под значения переменных
	{
		for (int j = 0; j < 8; j++)
		{
			if ((num & dva) != 0)
				knf[i][j] = 1;
			else
				knf[i][j] = 0;
			dva = dva / 2;
		}
		dva = 128;
		num++;
	}


	int result = 0;
	int a = 0, b = 0, c = 0, d = 0, f = 0, g = 0, h = 0, i = 0;

	for (int k = 0; k < 256; k++) //получение значения уравнения 10 заменить на 256
	{
		 for (int j = 0; j < 84; j++)
		 {if ((Arr[j][0] == 1) && (knf[k][0] == 1))
			 a = 0;
		 if ((Arr[j][0] == 1) && (knf[k][0] == 0))
			 a = 1;
		 if ((Arr[j][0] == 0) && (knf[k][0] == 1))
			 a = 1;
		 if ((Arr[j][0] == 0) && (knf[k][0] == 0))
			 a = 0;
	//_____________________________________________________________________________
		 if ((Arr[j][1] == 1) && (knf[k][1] == 1))
			 b = 0;
		 if ((Arr[j][1] == 1) && (knf[k][1] == 0))
			 b = 1;
		 if ((Arr[j][1] == 0) && (knf[k][1] == 1))
			 b = 1;
		 if ((Arr[j][1] == 0) && (knf[k][1] == 0))
			 b = 0;
	//_____________________________________________________________________________
		 if ((Arr[j][2] == 1) && (knf[k][2] == 1)) 
			 c = 0;
		 if ((Arr[j][2] == 1) && (knf[k][2] == 0))
			 c = 1;
		 if ((Arr[j][2] == 0) && (knf[k][2] == 1))
			 c = 1;
		 if ((Arr[j][2] == 0) && (knf[k][2] == 0))
			 c = 0;
	//_____________________________________________________________________________
		 if ((Arr[j][3] == 1) && (knf[k][3] == 1)) 
			 d = 0;
		 if ((Arr[j][3] == 1) && (knf[k][3] == 0))
			 d = 1;
		 if ((Arr[j][3] == 0) && (knf[k][3] == 1))
			 d = 1;
		 if ((Arr[j][3] == 0) && (knf[k][3] == 0))
			 d = 0;
	//_____________________________________________________________________________
		 if ((Arr[j][4] == 1) && (knf[k][4] == 1)) 
			 f = 0;
		 if ((Arr[j][4] == 1) && (knf[k][4] == 0))
			 f = 1;
		 if ((Arr[j][4] == 0) && (knf[k][4] == 1))
			 f = 1;
		 if ((Arr[j][4] == 0) && (knf[k][4] == 0))
			 f = 0;
	//_____________________________________________________________________________
		 if ((Arr[j][5] == 1) && (knf[k][5] == 1)) 
			 g = 0;
		 if ((Arr[j][5] == 1) && (knf[k][5] == 0))
			 g = 1;
		 if ((Arr[j][5] == 0) && (knf[k][5] == 1))
			 g = 1;
		 if ((Arr[j][5] == 0) && (knf[k][5] == 0))
			 g = 0;
	//_____________________________________________________________________________
		 if ((Arr[j][6] == 1) && (knf[k][6] == 1)) 
			 h = 0;
		 if ((Arr[j][6] == 1) && (knf[k][6] == 0))
			 h = 1;
		 if ((Arr[j][6] == 0) && (knf[k][6] == 1))
			 h = 1;
		 if ((Arr[j][6] == 0) && (knf[k][6] == 0))
			 h = 0;
	//_____________________________________________________________________________
		 if ((Arr[j][7] == 1) && (knf[k][7] == 1)) 
			 i = 0;
		 if ((Arr[j][7] == 1) && (knf[k][7] == 0))
			 i = 1;
		 if ((Arr[j][7] == 0) && (knf[k][7] == 1))
			 i = 1;
		 if ((Arr[j][7] == 0) && (knf[k][7] == 0))
			 i = 0;
		 result = a&b&c&d&f&g&h&i;
		 if (result == 1)
			 break;
		 }
		 knf[k][8] = result;
	}
	
	//for (int i = 0; i < 256; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		cout << knf[i][j];
	//	}
	//	cout << "\n";
	//}
	
}



void make_knf(int **knf) //перенести в файл
{
	cout << "\n";
	for (int i = 0; i < 256; i++)
	{
		if (knf[i][8] == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				if (j == 0)
					cout << "(";
				if (knf[i][j] == 1)
				{
					cout << "¬";
				}
				switch (j)
				{
				case 0:
				{
					cout << "a\\/";
					break;
				}
				case 1:
				{
					cout << "b\\/";
					break;
				}
				case 2:
				{
					cout << "c\\/";
					break;
				}
				case 3:
				{
					cout << "d\\/";
					break;
				}
				case 4:
				{
					cout << "f\\/";
					break;
				}
				case 5:
				{
					cout << "g\\/";
					break;
				}
				case 6:
				{
					cout << "h\\/";
					break;
				}
				case 7:
				{
					cout << "i)";
					break;
				}
				}

			}
		}
	}
}
