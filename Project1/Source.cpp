#include <iostream>
using namespace std;


//////////////////////////////////////////////////////////
//void test(int *A, int C, int &E)
//	{
//		cout << A << endl;
//		cout << *A << endl;
//		*A = *A * (*A);
//		C = C * C;                                /////////Работа с переменными//////////////
//		cout << C << endl;
//		int X = *A;
//		X = X * X;
//		cout << X << endl;
//		E = E * E;
//
//	}

///////////////////////////////////////////////////

void FillRand(int *array, int j)
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



int* push_back(int* array, int j, int k)
{
	int* array_1 = new int[j + 1];
	for (int i = 0; i < j; i++)
	{
		array_1[i] = array[i];
	}
	array_1[j] = k;
		
    return array_1;
}

int main() 

{
	setlocale(LC_ALL, "");
	//////////////////////////////////////////////////////
	/*int b = 10;
	int d = 10;
	int f = 10;                                          /////////Работа с переменными//////////////
	test(&b, d, f);
	cout << b << endl;
	cout << d << endl;
	cout << f << endl;*/
    ///////////////////////////////////////////////////////////
	
	
	int j;
	int l;
	cout << "Размер массива: " << endl;
	cin >> j;
	
	int* arr = new int[j];
	FillRand(arr, j);
	Print(arr, j);
	cout << endl;
	cout << "Дополнительный элемент: " << endl;
	cin >> l;
	//int* array_1 = new int[j + 1];
	//push_back(arr, j, l);
	//Print(array_1, j + 1);

	arr = push_back(arr, j, l);
	Print(arr, j+1);
	///////////////////////////////////////////////////////////////

}
////////////////////////////////////////////////////////////////////////////