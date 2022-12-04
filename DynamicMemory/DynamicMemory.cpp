#include<iostream>
using namespace std;

void FillRand(int* array, int j);
void FillRand(int** array, int ROWS, int COLLS);
//void Print(int* array, int j);
void Print(int** array, int ROWS, int COLLS);
//int* push_back(int* array, int &j, int k);
int** push_row_back(int** array, int &ROWS, int COLLS);
int** push_col_back(int** array, int ROWS, int &COLLS);
//int* push_front(int* array, int &j, int k);
int** push_row_front(int** array, int &ROWS, int COLLS);
int** push_col_front(int** array, int ROWS, int& COLLS);
//int* insert(int* array, int& j, int k, int ind);
int** insert_row(int** array, int &ROWS, int COLLS, int index);
//int* pop_back(int* array, int& j);
int** pop_row_back(int** array, int& ROWS, int COLLS);
//int* pop_front(int* array, int& j);
int** pop_row_front(int** array, int& ROWS, int COLLS);
//int* erase(int* array, int& j, int ind);
int** erase_row(int** array, int& ROWS, int COLLS, int index);

int main()
{
	setlocale(LC_ALL, "");
	int ROWS, COLLS;
	cout << "Введите кол-во строк двумерного массива: " << endl;
	cin >> ROWS;
	cout << "Введите кол-во столбцов двумерного массива: " << endl;
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




	//int j;
	//cout << "Размер массива: ";
	//cin >> j;
	//int* arr = new int[j];
	//cout << "---------------FillRand------------" << endl;
	//cout << endl;
	//FillRand(arr, j);
	//Print(arr, j);
	//cout << endl;
	//cout << endl;
	//cout << "-----------------------------------" << endl;
	//cout << endl;
	//cout << "Ведите дополнительный элемент: ";

 //   int l; // Дополнительный элемент
	//cin >> l;
	//
	//arr = push_back(arr, j, l);
	//cout << endl;
	//cout << "---------------push_back------------" << endl;
	//cout << endl;
	//Print(arr, j);
	//cout << endl;
	//cout << endl;
	//cout << "---------------push_front------------" << endl;
	//cout << endl;
	//arr = push_front(arr, j, l);
	//Print(arr, j);
	//cout << endl;
	//cout << endl;
	//cout << "------------------------------------" << endl;
	//cout << endl;
	//cout << "Введите индекс вставляемого элемента в массив из " << j << " элементов: ";
	//int index=0;
	//cin >> index;
	//arr = insert(arr, j, l, index);
	//cout << endl;
	//cout << "---------------insert----------------" << endl;
	//cout << endl;
	//Print(arr, j);
	//cout << endl;
	//cout << endl;
	 
	cout << "Введите индекс вставляемой строки: " << endl;
	int index=0;
	cin >> index;
	array = insert_row(array,ROWS,COLLS, index);
	cout << endl;
	cout << "---------------insert_row----------------" << endl;
	cout << endl;
	Print(array,ROWS, COLLS);
	cout << endl;
	cout << endl;
	cout << "Введите индекс удаляемой строки: " << endl;
	//int index = 0;
	cin >> index;
	array = erase_row(array, ROWS, COLLS, index);
	Print(array, ROWS, COLLS);
	cout << endl;
	cout << endl;
	
	//cout << "---------------pop_back------------" << endl;
	//cout << endl;
	//arr = pop_back(arr, j);
	//Print(arr, j);
	//cout << endl;
	//cout << endl;
	//cout << "---------------pop_front------------" << endl;
	//cout << endl;
	//arr = pop_front(arr, j);
	//Print(arr, j);
	//cout << endl;
	//cout << endl;
	//cout << "------------------------------------" << endl;
	//cout << endl;
	//cout << "Введите индекс удаляемого элемента в массиве из " << j << " элементов: ";
	//cin >> index;
	//arr = erase(arr, j, index);
	//cout << endl;
	//cout << "---------------erase------------" << endl;
	//cout << endl;
	//Print(arr, j);
	//cout << endl;
	//cout << endl;
	//cout << "------------------------------------" << endl;
}

void FillRand(int* array, int j)
{
	for (int i = 0; i < j; i++)
		array[i] = rand();

}

void FillRand(int** array, int ROWS, int COLLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLS; j++)
			array[i][j] = rand();
	}
}
//
//void Print(int* arr, int j)
//{
//	for (int i = 0; i < j; i++)
//	{
//		cout << arr[i] << "\t";
//	}
//
//}

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


//
//int* push_back(int* array, int &j, int k ) //массив, размер, доп_элемент
//{
//	int* array_1 = new int[j + 1];
//	for (int i = 0; i < j; i++)
//	{
//		array_1[i] = array[i];
//	}
//	
//	array_1[j] = k;
//	j++;
//	delete[]array;
//	return array_1;
//}
//
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

	//FillRand(array1[ROWS], COLLS);
	ROWS--;
	return array1;
}
// 
// 
// 
//int* push_front(int* array, int &j, int k) //массив, размер, доп_элемент
//{
//	int* array_1 = new int[j + 1];
//	for (int i = 1; i <= j; i++)
//	{
//		array_1[i] = array[i - 1];
//	}
//
//	array_1[0] = k;
//	j++;
//	delete[]array;
//	return array_1;
//}

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

	//FillRand(array1[0], COLLS);
	ROWS--;
	return array1;
}
//int* insert(int* array, int& j, int k, int ind) //массив, размер, доп_элемент, индекс
//{
//	int* array_1 = new int[j + 1];
//	for (int i = 0; i < ind; i++)
//	{
//		array_1[i] = array[i];
//	}
//
//	array_1[ind] = k;
//
//	for (int i = ind+1; i < j+1; i++)
//	{
//		array_1[i] = array[i-1];
//	}
//
//	j++;
//	delete[]array;
//	return array_1;
//}

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


//int* pop_back(int* array, int& j) //массив, размер
//{
//	int* array_1 = new int[j-1];
//	for (int i = 0; i < j-1; i++)
//	{
//		array_1[i] = array[i];
//	}
//
//	j--;
//	delete[]array;
//	return array_1;
//}
//
//int* pop_front(int* array, int& j) //массив, размер
//{
//	int* array_1 = new int[j -1];
//	for (int i = 1; i <= j-1; i++)
//	{
//		array_1[i-1] = array[i];
//	}
//	j--;
//	delete[]array;
//	return array_1;
//}
//
//int* erase(int* array, int& j, int ind) //массив, размер, индекс
//{
//	int* array_1 = new int[j - 1];
//	for (int i = 0; i < ind; i++)
//	{
//		array_1[i] = array[i];
//	}
//
//	for (int i = ind ; i < j - 1; i++)
//	{
//		array_1[i] = array[i+1];
//	}
//	j--;
//	delete[]array;
//	return array_1;
//}