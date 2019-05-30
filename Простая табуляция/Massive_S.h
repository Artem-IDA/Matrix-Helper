#pragma once
#ifndef Massive_S_H
#define Massive_S_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
!!!ИСПОЛЬЗУЕМЫЕ ПЕРЕМЕННЫЕ!!!

vector<int> massiv;
ofstream fout;
int size, size2; 

По сути size - это индекс начального элемента отрезка, size - конечного.
Функции данного хед. файла работают с отрезками определенного массива.

ТАКЖЕ ПРИ УКАЗАНИИ ОТРЕЗКА СТОИТ УЧИТЫВАТЬ ЧТО ЦИКЛЫ УСТОЕНЫ ТАК - for (int i = size; i <= size2; i++)
ТОЕСТЬ ПОСЛИ ВВОДА ПОЛЬЗОВАТЕЛЕМ РАЗМЕРА МАССИВА, ПЕРЕД ИСПОЛЬЗОВАНИЕМ ФУНКЦИИ НУЖНО ОТНЯТЬ -1 от size2
*/
extern int min, max;
extern int Random(int min, int max);

vector<int> zapolnenie(int size, int size2, int chislo, vector<int> massiv)
{
	if (chislo == 921)
	{
		for (int i = size; i <= size2; i++)
		{
			massiv.push_back(Random(min, max));
		}
	}
	else
	{
		for (int i = size; i <= size2; i++)
		{
			massiv.push_back(chislo);
		}
	}
	return massiv;
}
vector<int> rezapolnenie(int size, int size2, int chislo, vector<int> massiv)
{
	if (chislo == 921)
	{
		for (int i = size; i <= size2; i++)
		{
			massiv[i] = Random(min, max);
		}
	}
	else
	{
		for (int i = size; i <= size2; i++)
		{
			massiv[i] = chislo;
		}
	}
	return massiv;
}
vector<int> sortirovka(int size2, vector<int> massiv, int rej)
{
	if (rej == 1)
	{
		int buff;
		for (int i = 0; i <= size2; i++)
		{
			for (int j = size2; j > i; j--)
			{
				if (massiv[j] < massiv[j - 1])
				{
					buff = massiv[j - 1];
					massiv[j - 1] = massiv[j];
					massiv[j] = buff;
				}
			}
		}
		for (int i = 0; i <= size2; i++)
			cout << "[" << i << "] " << massiv[i] << endl;
	}
	else if (rej == 2)
	{
		int buff;
		for (int i = 0; i <= size2; i++)
		{
			for (int j = size2; j > i; j--)
			{
				if (massiv[j] > massiv[j - 1])
				{
					buff = massiv[j - 1];
					massiv[j - 1] = massiv[j];
					massiv[j] = buff;
				}
			}
		}
		for (int i = 0; i <= size2; i++)
			cout << "[" << i << "] " << massiv[i] << endl;
	}

	return massiv;
}
void vivod_massiva(int size2, vector<int> massiv)
{
	system("cls");
	for (int i = 0; i <= size2; i++)
		cout << "[" << i << "] " << massiv[i] << endl;
}
vector<int> vvod_massiva(int size2, vector<int> massiv)
{
	system("cls");
	for (int i = 0; i <= size2; i++)
	{
		cout << "[" << i << "] ";
		int a;
		cin >> a;
		massiv.push_back(a);
	}
	return massiv;
}
vector<int> vstavka(int nomer, int znachenie, int size2, vector<int> massiv)
{
	vector<int> massiv2;
	for (int i = nomer; i < (size2 + 1); i++)
		massiv2.push_back(massiv[i]);
	massiv[nomer] = znachenie;
	massiv.push_back(0);
	size2++;
	for (int i = (nomer + 1); i < (size2 + 1); i++)
		massiv[i] = massiv2[i - (nomer + 1)];
	return massiv;
}
// size2 надо увеличивать на 1 вручную после прогона функции.
void zapisvfailmass(int size2, vector<int> massiv, ofstream &fout)
{
	for (int i = 0; i <= size2; i++)
		fout << "[" << i << "] " << massiv[i] << endl;
}
#endif;