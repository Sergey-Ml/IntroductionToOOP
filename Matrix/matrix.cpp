#include <iostream>
using namespace std;

class Matrix;
void Print(int* arr, int j);
void Print(int** array, int ROWS, int COLLS);


class Matrix
{
	int ROWS; //строки
	int COLS; // столбцы
	int** array; // двумерн динамическ массив
public:
	int get_ROWS()const
	{
		return ROWS;
	}
	int get_COLS()const
	{
		return COLS;
	}
	int** get_array()const
	{
		return array;
	}
	void set_ROWS(int ROWS)
	{
		if (!(this->ROWS))
		{
			this->ROWS = ROWS;
		}
	}
	void set_COLS(int COLS)
	{
		if (!(this->COLS))
		{
			this->COLS = COLS;
		}
	}
	void set_array()
	{
		if ((this->ROWS >0) && (this->COLS >0))
		{
			for (int i = 0; i < this->ROWS; i++)
			{
				for (int j = 0; j < this->COLS; j++)
				{
					array[i][j] = rand();
				}
			}
		}
	}


	//Constructor
	Matrix(int ROWS, int COLS, int** array)
	{
		this-> array = new int* [ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			array[i] = new int[COLS];
		}
		this->array = array;
	}

	Matrix(int ROWS, int COLS)
	{
		this->ROWS = ROWS;
		this->COLS = COLS;
		this->array = new int* [ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			array[i] = new int[COLS];
		}
		set_array();
	}

	Matrix()
	{
		ROWS = 2;
		COLS = 2;
		this->array = new int* [ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			array[i] = new int[COLS];
		}
		set_array();
	}

	~Matrix()
	{

		for (int i = 0; i < ROWS; i++)
		{
			delete[] array[i];
		}
		delete[] array;
	}

	//Operators
	Matrix operator+(const Matrix& other)
	{
		Matrix C(ROWS, COLS);

		if (!(this->ROWS = other.ROWS) && (this->COLS = other.COLS))
			cout << "Матрицы не раывны, сложение невозможно" << endl;
		else
		{
			
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					C.array[i][j] = this->array[i][j] + other.array[i][j];
				}
			}
		}
		return C;
	}

}; 

void Print(int* arr, int j)
{
	for (int i = 0; i < j; i++)
	{
		cout << arr[i] << "\t";
	}

}
void Print(int** array, int ROWS, int COLLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		Print(array[i], COLLS);
		cout << endl;
	}

}

void main()
{
	Matrix A(2,2);
	Matrix B(2,2);
	Matrix C(2,2);
	Matrix C = A + B;
	Print(C.get_array(), C.get_ROWS(), C.get_COLS());
}