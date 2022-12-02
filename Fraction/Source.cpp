#include<iostream>
using namespace std;

class Fraction
{
	int x;   // числитель
	int y;   // знаменатель
	char z;  // знак 

public:

	int get_x() const
	{
		return x;
	}

	int get_y() const
	{
		return y;
	}

	char get_z() const
	{
		return z;
	}

	

	void set_x(int x)
	{
		this->x = x;
	}


	void set_y(int y) 
	{
		if (y != 0) {
			this->y = y;
		}
		else
		{
			this->y = 1;
			cout << "Дробь не создана, делить на 0 нельзя" << endl;
		}
	}

	void set_z(char z)
	{
		
		if (z == '-' || z == '+')
		{
			this->z = z;
		}
		else
			this->z = '+';
	}

	Fraction(int x, int y, char z)
	{
		if (z == '-' || z == '+')
		{
			this->z = z;
		}
		else
			this->z = '+';

		if (y != 0)
		{
			this->x = x;
			this->y = y;
			if (x >= y)
			{
				cout << "Неправильная дробь: " << this -> z << this-> x << "/" << this-> y << endl;
			}
			else
			{
				cout << "Правильная дробь: " << this -> z << this-> x << "/" << this-> y << endl;
			}
		}
		else
		{
			this ->x = 1;
			this ->y = 1;
			cout << "Дробь не создана, делить на 0 нельзя" << endl;
		}
		

	}

	Fraction(int x, int y)
	{
		this->z = '+';
		if (y != 0)
		{
			this->x = x;
			this->y = y;
			if (x >= y)
			{
				cout << "Неправильная дробь: " << this->z << this->x << "/" << this->y << endl;
			}
			else
			{
				cout << "Правильная дробь: " << this->z << this->x << "/" << this-> y << endl;
			}
		}
		else
		{
			this->x = 1;
			this->y = 1;
			cout << "Дробь не создана, делить на 0 нельзя" << endl;
		}
	}
	~Fraction()
	{

	}

	
	void operator=(const Fraction& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	Fraction operator+(const Fraction& A)
	{
		Fraction C(1, 1);
		int x1, x2;
		if (this->z == '-')
		{
			x1 = this->x * (-1);
		}
		else
		{
			x1 = this->x;
		}
			if (A.z == '-')
		{
			x2 = A.x * (-1);
		}
		else
		{
			x2 = A.x;
		}

		C.x = x1 * A.y + x2 * this->y;
		
		C.y = this->y * A.y;

		if (C.x < 0)
		{
			C.z = '-';
			C.x = C.x * (-1);
		}

		return C;
	}
	
	Fraction operator*(const Fraction& A)
	{
		Fraction C(1, 1);
		C.x = this->x * A.x;
		C.y = this->y * A.y;
		if (A.z == this->z)
			C.z = '+';
		else
			C.z = '-';

		return C;

	}

	Fraction operator/(const Fraction& A)
	{
		Fraction C(1, 1);
		C.x = this->x * A.y;
		C.y = this->y * A.x;
		if (A.z == this->z)
			C.z = '+';
		else
			C.z = '-';

		return C;

	}

};


void main()
{

	setlocale(LC_ALL, "");

	int x, y;
	char z;
	/*cout <<"Введите числитель" << endl;
	cin >> x;
	cout << "Введите знаменатель" << endl;
	cin >> y;
	cout << "Введите знак дроби ( '+' или '-' )" << endl;
	cin >> z;*/

	Fraction A(1, 2,'-');
	Fraction B(1, 3,'-');

	//A = B;
	//cout << A.get_z() <<A.get_x()<<" / "<< A.get_y() << endl;

	//A =A + B;

	//cout << A.get_z() << A.get_x() << "/" << A.get_y() << endl;

	//A = A * B;

	A = A / B;

	cout << A.get_z() << A.get_x() << "/" << A.get_y() << endl;
}
//  создать третий  объект для вывода данных
