#include <iostream>
using namespace std;

void FillRand(int* array, int j);

void Print(int* arr, int j);

int main()
{
	setlocale(LC_ALL, "");
	int j;
	int l;
	cout << "Размер массива: " << endl;
	cin >> j;

	int* arr = new int[j];
	FillRand(arr, j);
	Print(arr, j);
	cout << endl;


	int chetn = 0;
for (int i = 0; i < 10; i++)
{
	if (arr[i] % 2 == 0)
		chetn++;
}
int* array_nech = new int[10 - chetn];
int* array_chetn = new int[chetn];
int x = 0; int y = 0;
for (int i = 0; i < 10; i++)
{
	if (arr[i] % 2 == 0)
	{
		array_chetn[x] = arr[i];                      
		x++;
	}
	
	else
	{
		array_nech[y] = arr[i];
		y++;
	}

}
cout << endl;
Print(array_nech, 10-chetn);
cout << endl;
Print(array_chetn, chetn);
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


