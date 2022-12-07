#include<iostream>


using namespace std;

// Одномерные 
void FillRand(int* array, int j);
void Print(int* array, int j);

int* push_back(int* array, int &j, int k);
int* push_front(int* array, int &j, int k);
int* insert(int* array, int& j, int k, int ind);
int* pop_back(int* array, int& j);
int* pop_front(int* array, int& j);
int* erase(int* array, int& j, int ind);

// Двумерные
void FillRand(int** array, int ROWS, int COLLS);
void Print(int** array, int ROWS, int COLLS);

int** push_row_back(int** array, int &ROWS, int COLLS);
int** push_row_front(int** array, int &ROWS, int COLLS);
int** pop_row_back(int** array, int& ROWS, int COLLS);
int** pop_row_front(int** array, int& ROWS, int COLLS);
int** insert_row(int** array, int &ROWS, int COLLS, int index);
int** erase_row(int** array, int& ROWS, int COLLS, int index);

int** push_col_back(int** array, int ROWS, int &COLLS);
int** push_col_front(int** array, int ROWS, int& COLLS);
int** pop_col_back(int** array, int ROWS, int& COLLS);
int** pop_col_front(int** array, int ROWS, int& COLLS);
int** insert_col(int** array, int ROWS, int& COLLS, int index);
int** erase_col(int** array, int ROWS, int& COLLS, int index);


int main()
{
	setlocale(LC_ALL, "");
	
	// Одномерные массивы


	cout << "---------------Одномерные массивы------------" << endl;
	cout << endl;
	int j;
	cout << "Введите размер одномерного массива: ";
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
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	
	// Двумерные массивы
	cout << "---------------Двумерные массивы------------" << endl;
	cout << endl;
	int ROWS, COLLS;
	cout << "Введите кол-во строк двумерного массива: ";
	cin >> ROWS;
	cout << "Введите кол-во столбцов двумерного массива: ";
	cin >> COLLS;
	int** array = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		array[i] = new int[COLLS];
	}
	cout << "---------------FillRand------------" << endl;
	cout << endl;
	FillRand(array, ROWS, COLLS);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "---------------СТРОКИ-------------------" << endl;
	cout << endl;
	cout << "---------------push_row_back------------" << endl; 
	cout << endl;
	array = push_row_back(array, ROWS, COLLS);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "---------------push_row_front------------" << endl;
	cout << endl;
	array = push_row_front(array, ROWS, COLLS);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "---------------pop_row_back------------" << endl;
	cout << endl;
	array = pop_row_back(array, ROWS, COLLS);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "---------------pop_row_front------------" << endl;
	cout << endl;
	array = pop_row_front(array, ROWS, COLLS);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "Введите индекс вставляемой строки: ";
	//int index=0;
	cin >> index;
	array = insert_row(array,ROWS,COLLS, index);
	cout << endl;
	cout << "---------------insert_row----------------" << endl;
	cout << endl;
	Print(array,ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "Введите индекс удаляемой строки: ";
	//int index = 0;
	cin >> index;
	cout << "---------------erase_row----------------" << endl;
	cout << endl;
	array = erase_row(array, ROWS, COLLS, index);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;

	
	cout << "---------------СТОЛБЦЫ-------------------" << endl;
	cout << endl;
	cout << "---------------push_col_back------------" << endl;
	cout << endl;
	array = push_col_back(array, ROWS, COLLS);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "---------------push_col_front------------" << endl;
	cout << endl;
	array = push_col_front(array, ROWS, COLLS);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "---------------pop_col_back------------" << endl;
	cout << endl;
	array = pop_col_back(array, ROWS, COLLS);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "---------------pop_col_front------------" << endl;
	cout << endl;
	array = pop_col_front(array, ROWS, COLLS);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "Введите индекс вставляемого столбца: ";
	//int index=0;
	cin >> index;
	array = insert_col(array,ROWS,COLLS, index);
	cout << endl;
	cout << "---------------insert_col----------------" << endl;
	cout << endl;
	Print(array,ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "Введите индекс удаляемого столбца: ";
	//int index = 0;
	cin >> index;
	cout << "---------------erase_col----------------" << endl;
	cout << endl;
	array = erase_col(array, ROWS, COLLS, index);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
}


// Одномерные

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


int* push_back(int* array, int& j, int k) //массив, размер, доп_элемент
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


int* push_front(int* array, int& j, int k) //массив, размер, доп_элемент
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

	for (int i = ind + 1; i < j + 1; i++)
	{
		array_1[i] = array[i - 1];
	}

	j++;
	delete[]array;
	return array_1;
}


int* pop_back(int* array, int& j) //массив, размер
{
	int* array_1 = new int[j - 1];
	for (int i = 0; i < j - 1; i++)
	{
		array_1[i] = array[i];
	}

	j--;
	delete[]array;
	return array_1;
}


int* pop_front(int* array, int& j) //массив, размер
{
	int* array_1 = new int[j - 1];
	for (int i = 1; i <= j - 1; i++)
	{
		array_1[i - 1] = array[i];
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

	for (int i = ind; i < j - 1; i++)
	{
		array_1[i] = array[i + 1];
	}
	j--;
	delete[]array;
	return array_1;
}


// Двумерные 

void FillRand(int** array, int ROWS, int COLLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
			array[i][j] = rand();
	}
}



void Print(int** array, int ROWS, int COLLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	
}


int** push_row_back(int** array, int& ROWS, int COLLS)
{
	
	int** array1 = new int* [ROWS+1];
	for (int i = 0; i < ROWS+1; i++)
	{
		array1[i] = new int[COLLS];
	}
		
	for (int i = 0; i < ROWS; i++)
	{
		array1[i] = array[i];
	 }
		
	FillRand(array1[ROWS], COLLS);
	ROWS++;
	return array1;
}


int** push_row_front(int** array, int& ROWS, int COLLS)
{
	int** array1 = new int* [ROWS + 1];
	for (int i = 0; i < ROWS + 1; i++)
	{
		array1[i] = new int[COLLS];
	}

	for (int i = 1; i <= ROWS; i++)
	{
		array1[i] = array[i-1];
	}

	FillRand(array1[0], COLLS);
	ROWS++;
	return array1;
}


int** insert_row(int** array, int& ROWS, int COLLS, int index)
{
	int** array1 = new int* [ROWS + 1];
	for (int i = 0; i < ROWS + 1; i++)
	{
		array1[i] = new int[COLLS];
	}

	for (int i = 0; i < index; i++)
	{
		array1[i] = array[i];
	}

	FillRand(array1[index], COLLS);
	for (int i = index+1; i <=ROWS; i++)
	{
		array1[i] = array[i-1];
	}
	ROWS++;
	return array1;
}

int** pop_row_back(int** array, int& ROWS, int COLLS)
{

	int** array1 = new int* [ROWS -1];
	for (int i = 0; i < ROWS -1; i++)
	{
		array1[i] = new int[COLLS];
	}

	for (int i = 0; i < ROWS-1; i++)
	{
		array1[i] = array[i];
	}

	ROWS--;
	return array1;
}


int** pop_row_front(int** array, int& ROWS, int COLLS)
{
	int** array1 = new int* [ROWS- 1];
	for (int i = 0; i < ROWS- 1; i++)
	{
		array1[i] = new int[COLLS];
	}

	for (int i = 0; i < ROWS-1; i++)
	{
		array1[i] = array[i + 1];
	}

	ROWS--;
	return array1;
}


int** erase_row(int** array, int& ROWS, int COLLS, int index)
{
	int** array1 = new int* [ROWS - 1];
	for (int i = 0; i < ROWS - 1; i++)
	{
		array1[i] = new int[COLLS];
	}

	for (int i = 0; i < index; i++)
	{
		array1[i] = array[i];
	}

	for (int i = index; i < ROWS-1; i++)
	{
		array1[i] = array[i + 1];
	}
	ROWS--;
	return array1;
}


int** push_col_back(int** array, int ROWS, int& COLLS)
{

	int** array1 = new int* [COLLS + 1];
	for (int i = 0; i < ROWS; i++)
	{
		array1[i] = new int[COLLS+1];
	}

	for (int i = 0; i < ROWS; i++)
	{
		array1[i] = array[i];
		array1[i][COLLS] = rand();
	}
		
	COLLS++;
	return array1;
}

int** push_col_front(int** array, int ROWS, int& COLLS)
{

	int** array1 = new int* [COLLS + 1];
	for (int i = 0; i < ROWS; i++)
	{
		array1[i] = new int[COLLS + 1];
	}

	for (int i = 0; i < ROWS; i++)
	{
		array1[i][0] = rand();
		for (int j = 1; j < COLLS + 1; j++)
		{
			array1[i][j] = array[i][j - 1];
		}
	}

	COLLS++;
	return array1;
}

int** pop_col_back(int** array, int ROWS, int& COLLS)
{

	int** array1 = new int* [COLLS -1];
	for (int i = 0; i < ROWS; i++)
	{
		array1[i] = new int[COLLS - 1];
	}

	for (int i = 0; i < ROWS; i++)
	{
		array1[i] = array[i];
		
	}

	COLLS--;
	return array1;
}

int** pop_col_front(int** array, int ROWS, int& COLLS)
{

	int** array1 = new int* [COLLS - 1];
	for (int i = 0; i < ROWS; i++)
	{
		array1[i] = new int[COLLS - 1];
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
		{
			array1[i][j] = array[i][j+1];
		}

	}

	COLLS--;
	return array1;
}
 
int** insert_col(int** array, int ROWS, int& COLLS, int index)
{

	int** array1 = new int* [COLLS + 1];
	for (int i = 0; i < ROWS; i++)
	{
		array1[i] = new int[COLLS + 1];
	}

	for (int i = 0; i < ROWS; i++)
	{
		array1[i][index] = rand();
		for (int j = 0; j < index; j++)
		{
			array1[i][j] = array[i][j];
		}
		for (int j = index; j < COLLS+1; j++)
		{
			array1[i][j+1] = array[i][j];
		}

	}

	COLLS++;
	return array1;
}

int** erase_col(int** array, int ROWS, int& COLLS, int index)
{

	int** array1 = new int* [COLLS - 1];
	for (int i = 0; i < ROWS; i++)
	{
		array1[i] = new int[COLLS - 1];
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < index; j++)
		{
			array1[i][j] = array[i][j];
		}
		for (int j = index; j < COLLS-1; j++)
		{
			array1[i][j] = array[i][j+1];
		}

	}

	COLLS--;
	return array1;
}

