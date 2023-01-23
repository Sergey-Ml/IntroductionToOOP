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
					array[i][j] = rand()%10;
				}
			}
		}
	}


	//Constructor
	Matrix(int ROWS, int COLS, int** array)
	{
		this->ROWS = ROWS;
		this->COLS = COLS;
		this-> array = new int* [ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			this->array[i] = new int[COLS];
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

	Matrix(const Matrix& A)
	{
		this->ROWS = A.ROWS;
		this->COLS = A.COLS;
		this->array = new int* [ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			array[i] = new int[COLS];
		}
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				this->array[i][j] = A.array[i][j];
			}
		}

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
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				C.array[i][j] = 0;
			}
		}

		if ((this->ROWS != other.ROWS) || (this->COLS != other.COLS))
			cout << "Матрицы не равны, сложение невозможно" << endl;
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

	Matrix operator-(const Matrix& other)
	{
		Matrix C(ROWS, COLS);
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				C.array[i][j] = 0;
			}
		}

		if ((this->ROWS != other.ROWS) || (this->COLS != other.COLS))
			cout << "Матрицы не равны, вычитание невозможно" << endl;
		else
		{

			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					C.array[i][j] = this->array[i][j] - other.array[i][j];
				}
			}
		}
		return C;
	}

	Matrix operator*(const Matrix& other)
	{
		Matrix C(ROWS, other.COLS);
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < other.COLS; j++)
			{
				C.array[i][j] = 0;
			}
		}

		if ((this->ROWS != other.COLS) || (this->COLS != other.ROWS))
			cout << "Умножение невозможно" << endl;
		else
		{

			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < other.COLS; j++)

					for (int k = 0; k < COLS; k++)
					{

						{
							C.array[i][j] += this->array[i][k] * other.array[k][j];
						}
					}
			}
		}
		return C;
	}


	Matrix& operator=(const Matrix& other)
	{
		for (int i = 0; i < ROWS; i++)
		{
			delete[] array[i];
		}
		delete[] array;
		this->ROWS = other.ROWS;
		this->COLS = other.COLS;
		this->array = new int* [ROWS];
		for (int i = 0; i < ROWS; i++)
		{
			array[i] = new int[COLS];
		}

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
			this->array[i][j] = other.array[i][j];
			}
		}
		return *this;
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

void Print(Matrix C)
{

	Print(C.get_array(), C.get_ROWS(), C.get_COLS());
	cout << endl;
}


void main()
{
	setlocale(LC_ALL, "");
	Matrix A(2,2);
	Print(A);
	Matrix B(2,2);
	Print(B);
	Matrix C(3,3);
	Print(C);
	//C = A + C;
	//Print(C);
	//C = A - C ;
	//Print(C);
	C = A * B;
	Print(C);

}