#pragma once
#ifndef Matrica_S_H
#define Matrica_S_H
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

extern int min, max;
extern int Random(int min, int max);

/*
!!!ИСПОЛЬЗУЕМЫЕ ПЕРЕМЕННЫЕ!!!

vector<vector<int>> matrix;
ofstream fout;
int col_stlb, col_str;
*/
vector<vector<int>> vvod_matrici(int col_stlb, int col_str, vector<vector<int>> matrix)
{
	system("cls");
	for (int i = 0; i <= col_str; i++)
	{
		vector<int> temp;
		for (int j = 0; j <= col_stlb; j++)
		{
			int a;
			cin >> a;
			temp.push_back(a);
		}
		matrix.push_back(temp);
	}
	return matrix;
}
vector<vector<int>> zapolnenie_matrici(int col_stlb0, int col_str0, int col_stlb, int col_str, int chislo, vector<vector<int>> matrix)
{
	if (chislo == 921)
	{
		if (col_stlb0 == 0 && col_str0 == 0)
		{
			for (int i = col_str0; i <= col_str; i++)
			{
				vector<int> temp;
				for (int j = col_stlb0; j <= col_stlb; j++)
				{
					temp.push_back(Random(min, max));
				}
				matrix.push_back(temp);
			}
		}
		else if (col_stlb0 != 0 && col_str0 != 0)
		{
			for (int i = col_str0; i < col_str; i++)
			{
				vector<int> temp;
				for (int j = 0; j <= col_stlb; j++)
				{
					temp.push_back(Random(min, max));
				}
				matrix.push_back(temp);
			}
			for (int a = 0; a < col_str; a++)
			{
				for (int c = col_stlb0; c < col_stlb; c++)
				{
					matrix[a].push_back(Random(min, max));
				}
			}
		}
	}
	else
	{
		if (col_stlb0 == 0 && col_str0 == 0)
		{
			for (int i = col_str0; i < col_str; i++)
			{
				vector<int> temp;
				for (int j = col_stlb0; j < col_stlb; j++)
				{
					temp.push_back(chislo);
				}
				matrix.push_back(temp);
			}
		}
		else if (col_stlb0 != 0 && col_str0 != 0)
		{
			for (int i = col_str0; i < col_str; i++)
			{
				vector<int> temp;
				for (int j = 0; j <= col_stlb; j++)
				{
					temp.push_back(chislo);
				}
				matrix.push_back(temp);
			}
			for (int a = 0; a < col_str; a++)
			{
				for (int c = col_stlb0; c < col_stlb; c++)
				{
					matrix[a].push_back(chislo);
				}
			}
		}
	}
	return matrix;
}
vector<vector<int>> rezapolnenie_matrici(int col_stlb0, int col_str0, int col_stlb, int col_str, int chislo, vector<vector<int>> matrix)
{
	if (chislo == 921)
	{
		for (int i = col_str0; i <= col_str; i++)
		{
			for (int j = col_stlb0; j <= col_stlb; j++)
			{
				matrix[i][j] = Random(min, max);
			}
		}
	}
	else
	{
		for (int i = col_str0; i <= col_str; i++)
		{
			for (int j = col_stlb0; j <= col_stlb; j++)
			{
				matrix[i][j] = chislo;
			}
		}
	}
	return matrix;
}
void vivod_matrici(int col_stlb, int col_str, vector<vector<int>> matrix)
{
	system("cls");
	for (int i = 0; i <= col_str; i++)
	{
		for (int j = 0; j <= col_stlb; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
vector<vector<int>> sortirovka_matrici(int col_stlb, int col_str, vector<vector<int>> matrix, int rej)
{
	system("cls");
	if (rej == 1)
	{
		vector<int> temp;
		for (int i = 0; i <= col_str; i++)
		{
			for (int j = 0; j <= col_stlb; j++)
			{
				temp.push_back(matrix[i][j]);
			}
		}
		int buff;
		for (int i = 0; i < size(temp); i++)
		{
			for (int j = size(temp) - 1; j > i; j--)
			{
				if (temp[j] < temp[j - 1])
				{
					buff = temp[j - 1];
					temp[j - 1] = temp[j];
					temp[j] = buff;
				}
			}
		}
		int n = 0;
		for (int i = 0; i <= col_str; i++)
		{
			for (int j = 0; j <= col_stlb; j++)
			{
				matrix[i][j] = temp[n];
				n++;
			}
		}
	}
	else if (rej == 2)
	{
		vector<int> temp;
		for (int i = 0; i <= col_str; i++)
		{
			for (int j = 0; j <= col_stlb; j++)
			{
				temp.push_back(matrix[i][j]);
			}
		}
		int buff;
		for (int i = 0; i < size(temp); i++)
		{
			for (int j = size(temp) - 1; j > i; j--)
			{
				if (temp[j] > temp[j - 1])
				{
					buff = temp[j - 1];
					temp[j - 1] = temp[j];
					temp[j] = buff;
				}
			}
		}
		int n = 0;
		for (int i = 0; i <= col_str; i++)
		{
			for (int j = 0; j <= col_stlb; j++)
			{
				matrix[i][j] = temp[n];
				n++;
			}
		}
	}
	return matrix;
}
vector<vector<int>> rashr_matrici(int &col_str, int &col_stlb, vector<vector<int>> matrix, int rej, int col)
{
	system("cls");
	vector<vector<int>> matrix2;
	if (rej == 1)
	{
		for (int i = 0; i <= (col_str + col); i++)
		{
			vector<int> temp;
			if (i < col)
			{
				for (int j = 0; j <= col_stlb; j++)
				{
					temp.push_back(0);
				}
				matrix2.push_back(temp);
				
			}
			else
			{
				for (int j = 0; j <= col_stlb; j++)
				{
					temp.push_back(matrix[i-col][j]);
				}
				matrix2.push_back(temp);
			}
		}
		col_str += col;
	}
	else if (rej == 2)
	{
		for (int i = 0; i <= (col_str + col); i++)
		{
			vector<int> temp;
			if (i <= col_str)
			{
				for (int j = 0; j <= col_stlb; j++)
				{
					temp.push_back(matrix[i][j]);
				}
				matrix2.push_back(temp);
			}
			else
			{
				for (int j = 0; j <= col_stlb; j++)
				{
					temp.push_back(0);
				}
				matrix2.push_back(temp);
			}
		}
		col_str += col;
	}
	else if (rej == 3)
	{
		for (int i = 0; i <= col_str; i++)
		{
			vector<int> temp;
			for (int j = 0; j <= (col_stlb + col); j++)
			{
				if (j <= col_stlb)
				{
					temp.push_back(matrix[i][j]);
				}
				else
				{
					temp.push_back(0);
				}
			}
			matrix2.push_back(temp);
		}
		col_stlb += col;
	}
	else if (rej == 4)
	{
		for (int i = 0; i <= col_str; i++)
		{
			vector<int> temp;
			for (int j = 0; j <= (col_stlb + col); j++)
			{
				if (j < col)
				{
					temp.push_back(0);
				}
				else
				{
					temp.push_back(matrix[i][j-col]);
				}
			}
			matrix2.push_back(temp);
		}
		col_stlb += col;
	}
	return matrix2;
}
vector<vector<int>> redriadmatr(int y, int col_stlb, vector<vector<int>> matrix)
{
	y--;
	cout << "|Заполнить вашими значениями (1)|" << endl << "|Заполнить одним значением (2)|" << endl << "|Заполнить случайными значениями(3)|" << endl;
	int lever;
	cin >> lever;
	vector<int> vector;
	if (lever == 1)
	{
		for (int i = 0; i <= col_stlb; i++)
		{
			cout << "[" << i << "] ";
			int a;
			cin >> a;
			vector.push_back(a);
		}
	}
	else if (lever == 2)
	{
		cout << "Значение для заполнения ->";
		int n;
		cin >> n;
		for (int i = 0; i <= col_stlb; i++)
		{
			vector.push_back(n);
		}
	}
	else if (lever == 3)
	{
		for (int i = 0; i <= col_stlb; i++)
		{
			vector.push_back(Random(min, max));
		}
	}
	for (int i = 0; i <= col_stlb; i++)
	{
		matrix[y][i] = vector[i];
	}
	return matrix;
}
vector<vector<int>> redstolbmatr(int x, int col_str, vector<vector<int>> matrix)
{
	x--;
	cout << "|Заполнить вашими значениями (1)|" << endl << "|Заполнить одним значением (2)|" << endl << "|Заполнить случайными значениями(3)|" << endl;
	int lever;
	cin >> lever;
	vector<int> vector;
	if (lever == 1)
	{
		for (int i = 0; i <= col_str; i++)
		{
			cout << "[" << i << "] ";
			int a;
			cin >> a;
			vector.push_back(a);
		}
	}
	else if (lever == 2)
	{
		cout << "Значение для заполнения ->";
		int n;
		cin >> n;
		for (int i = 0; i <= col_str; i++)
		{
			vector.push_back(n);
		}
	}
	else if (lever == 3)
	{
		for (int i = 0; i <= col_str; i++)
		{
			vector.push_back(Random(min, max));
		}
	}
	for (int i = 0; i <= col_str; i++)
	{
		matrix[i][x] = vector[i];
	}
	return matrix;
}
void zapisvfailmatr(int col_stlb, int col_str, vector<vector<int>> matrix, ofstream &fout)
{
	system("cls");
	for (int i = 0; i <= col_str; i++)
	{
		for (int j = 0; j <= col_stlb; j++)
		{
			fout << matrix[i][j] << " ";
		}
		fout << endl;
	}
}
vector<vector<int>> mnojmatrnachisl(int col_stlb, int col_str, int n, vector<vector<int>> matrix)
{
	system("cls");
	for (int i = 0; i <= col_str; i++)
	{
		for (int j = 0; j <= col_stlb; j++)
		{
			matrix[i][j] *= n;

		}
	}
	return matrix;
}
vector<vector<int>> dodmatric(int col_stlb, int col_str, int col_stlb1, int col_str1, vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
	system("cls");
	if (col_str == col_str1 && col_stlb == col_stlb1)
	{
		for (int i = 0; i <= col_str; i++)
		{
			for (int j = 0; j <= col_stlb; j++)
			{
				matrix1[i][j] += matrix2[i][j];

			}
		}
	}
	else
		cout << "Matrici ne odinakovogo razmera!" << endl;
	return matrix1;
}
vector<vector<int>> vidnimmatric(int col_stlb, int col_str, int col_stlb1, int col_str1, vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
	system("cls");
	if (col_str == col_str1 && col_stlb == col_stlb1)
	{
		for (int i = 0; i <= col_str; i++)
		{
			for (int j = 0; j <= col_stlb; j++)
			{
				matrix1[i][j] -= matrix2[i][j];

			}
		}
	}
	else
		cout << "Matrici ne odinakovogo razmera!" << endl;
	return matrix1;
}
vector<vector<int>> mnojmatric(int &col_stlb, int &col_str, int col_stlb1, int col_str1, vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
	vector<vector<int>> matrix;
	if (col_stlb == col_str1)
	{
		for (int i = 0; i <= col_str; i++)
		{
			vector<int> temp;
			for (int j = 0; j <= col_stlb1; j++)
			{
				int a = 0;
				for (int g = 0; g <= col_stlb; g++)
				{
					a += (matrix1[i][g] * matrix2[g][j]);
				}
				temp.push_back(a);
			}
			matrix.push_back(temp);
		}
		col_stlb = col_stlb1;
		//swap(col_str, col_stlb);
		return matrix;
	}
	else
	{
		cout << "Matrici ne mogut bit pomnojeni drug na druga!" << endl;
		Sleep(2000);
		return matrix1;
	}
	
}
vector<vector<int>> stepmatric(int &col_stlb, int &col_str, int n, vector<vector<int>> matrix)
{
	if (col_stlb == col_str)
	{
		vector<vector<int>> matrixor = matrix;
		for (int i = 0; i < n - 1; i++)
		{
			matrix = mnojmatric(col_stlb, col_str, col_stlb, col_str, matrix, matrixor);
		}
	}
	else
		cout << "Tolko kvadratnie matrici mogut bit podneseni v stepen!" << endl;
	return matrix;
}
vector<vector<int>> transp(int &col_stlb, int &col_str, vector<vector<int>> matrix)
{
	vector<vector<int>> buff;
	for (int i = 0; i <= col_stlb; i++)
	{
		vector <int> temp;
		for (int j = 0; j <= col_str; j++)
		{
			temp.push_back(matrix[j][i]);
		}
		buff.push_back(temp);
	}
	swap(col_stlb, col_str);
	return buff;
}
#endif;
