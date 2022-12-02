#include<iostream>
using namespace std;

void FillRand(int* array, int j);
void Print(int* arr, int j);
int* push_back(int* array, int &j, int k);
int* push_front(int* array, int &j, int k);
int* insert(int* array, int& j, int k, int ind);
int* pop_back(int* array, int& j);
int* pop_front(int* array, int& j);
int* erase(int* array, int& j, int ind);

int main()
{
	setlocale(LC_ALL, "");

	int j;
	cout << "Размер массива: ";
	cin >> j;
	int* arr = new int[j];
	cout << "---------------FillRand------------" << endl;
	cout << endl;
	FillRand(arr, j);
	Print(arr, j);
	cout << endl;
	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
	cout << "Ведите дополнительный элемент: ";

    int l; // Дополнительный элемент
	cin >> l;
	
	arr = push_back(arr, j, l);
	cout << endl;
	cout << "---------------push_back------------" << endl;
	cout << endl;
	Print(arr, j);
	cout << endl;
	cout << endl;
	cout << "---------------push_front------------" << endl;
	cout << endl;
	arr = push_front(arr, j, l);
	Print(arr, j);
	cout << endl;
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << endl;
	cout << "Введите индекс вставляемого элемента в массив из " << j << " элементов: ";
	int index=0;
	cin >> index;
	arr = insert(arr, j, l, index);
	cout << endl;
	cout << "---------------insert----------------" << endl;
	cout << endl;
	Print(arr, j);
	cout << endl;
	cout << endl;
	cout << "---------------pop_back------------" << endl;
	cout << endl;
	arr = pop_back(arr, j);
	Print(arr, j);
	cout << endl;
	cout << endl;
	cout << "---------------pop_front------------" << endl;
	cout << endl;
	arr = pop_front(arr, j);
	Print(arr, j);
	cout << endl;
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << endl;
	cout << "Введите индекс удаляемого элемента в массиве из " << j << " элементов: ";
	cin >> index;
	arr = erase(arr, j, index);
	cout << endl;
	cout << "---------------erase------------" << endl;
	cout << endl;
	Print(arr, j);
	cout << endl;
	cout << endl;
	cout << "------------------------------------" << endl;
}

void FillRand(int* array, int j)
{
	for (int i = 0; i < j; i++)
		array[i] = rand();

}


void Print(int* arr, int j)
{
	for (int i = 0; i < j; i++)
	{
		cout << arr[i] << "\t";
	}

}


int* push_back(int* array, int &j, int k ) //массив, размер, доп_элемент
{
	int* array_1 = new int[j + 1];
	for (int i = 0; i < j; i++)
	{
		array_1[i] = array[i];
	}
	
	array_1[j] = k;
	j++;
	delete[]array;
	return array_1;
}

int* push_front(int* array, int &j, int k) //массив, размер, доп_элемент
{
	int* array_1 = new int[j + 1];
	for (int i = 1; i <= j; i++)
	{
		array_1[i] = array[i - 1];
	}

	array_1[0] = k;
	j++;
	delete[]array;
	return array_1;
}

int* insert(int* array, int& j, int k, int ind) //массив, размер, доп_элемент, индекс
{
	int* array_1 = new int[j + 1];
	for (int i = 0; i < ind; i++)
	{
		array_1[i] = array[i];
	}

	array_1[ind] = k;

	for (int i = ind+1; i < j+1; i++)
	{
		array_1[i] = array[i-1];
	}

	j++;
	delete[]array;
	return array_1;
}

int* pop_back(int* array, int& j) //массив, размер
{
	int* array_1 = new int[j-1];
	for (int i = 0; i < j-1; i++)
	{
		array_1[i] = array[i];
	}

	j--;
	delete[]array;
	return array_1;
}

int* pop_front(int* array, int& j) //массив, размер
{
	int* array_1 = new int[j -1];
	for (int i = 1; i <= j-1; i++)
	{
		array_1[i-1] = array[i];
	}
	j--;
	delete[]array;
	return array_1;
}

int* erase(int* array, int& j, int ind) //массив, размер, индекс
{
	int* array_1 = new int[j - 1];
	for (int i = 0; i < ind; i++)
	{
		array_1[i] = array[i];
	}

	for (int i = ind ; i < j - 1; i++)
	{
		array_1[i] = array[i+1];
	}
	j--;
	delete[]array;
	return array_1;
}