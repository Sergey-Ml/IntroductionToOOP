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
		set_z(z);

		set_y(y);
		this->x = x;
			if (x >= y)
			{
				cout << "Неправильная дробь: " << this -> z << this-> x << "/" << this-> y << endl;
			}
			else
			{
				cout << "Правильная дробь: " << this -> z << this-> x << "/" << this-> y << endl;
			}
	}

	Fraction(int x, int y)
	{
		this->z = '+';
		set_y(y);
		this->x = x;
			if (x >= y)
			{
				cout << "Неправильная дробь: " << this->z << this->x << "/" << this->y << endl;
			}
			else
			{
				cout << "Правильная дробь: " << this->z << this->x << "/" << this-> y << endl;
			}
	}
	Fraction(const Fraction& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
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

		x1 = this->x;

		if (this->z == '-')
		{
			x1 = x1 * (-1);
		}
		x2 = A.x;
		if (A.z == '-')
		{
			x2 = x2 * (-1);
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

	Fraction operator-(const Fraction& A)
	{
		Fraction C(1, 1);
		Fraction B(A);
		B.x = B.x * (-1);
		C = *this + B;
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

	Fraction& operator+=(const Fraction& A)
	{
		*this = *this + A;
		return *this;
	}
	Fraction& operator-=(const Fraction& A)
	{
		*this = *this - A;
		return *this;
	}
	Fraction& operator*=(const Fraction& A)
	{
		*this = *this * A;
		return *this;
	}
	Fraction& operator/=(const Fraction& A)
	{
		*this = *this / A;
		return *this;
	}

	Fraction& operator ++()
	{
		x = x + y;
		return *this;
	}

	Fraction operator ++(int)
	{
		Fraction C(*this);
		x = x + y;
		return C;
	}

	Fraction& operator --()
	{
		x = x - y;
		return *this;
	}

	Fraction operator --(int)
	{
		Fraction C(*this);
		x = x - y;
		return C;
	}

	bool operator ==(const Fraction& A)
	{
		if (this->x == A.x && this->y == A.y && this->z == A.z)
			return true;
		else return false;
	}
	bool operator !=(const Fraction& A)
	{
		if (!(this->x == A.x && this->y == A.y && this->z == A.z))
			return true;
		else return false;
	}

	bool operator >(const Fraction& A)
	{
		int x1, x2;
		x1 = this->x;
		x2 = A.x;
		if (this->z == '-')
			x1 = x1 * (-1);
		if (A.x == '-')
			x2 = x2 * (-1);

		if (this->z != A.z)
		{
			if (this->z == '+')
				return true;

			else false;
		}
		else
		{
			if (x1 * A.y > x2 * this->y)
				return true;
			else return false;
		}
	}
	bool operator >=(const Fraction& A)
	{
		if (*this == A || *this > A)

			return true;
		else return false;

	}

	bool operator <(const Fraction& A)
	{
		if (*this > A || *this ==A )

			return false;
		else return true;

	}

	bool operator <=(const Fraction& A)
	{
		if (*this > A)

			return false;
		else return true;

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

	Fraction A(1, 2);
	Fraction B(1, 3);

	if (A!=B) 
	cout <<"Да" << endl;
	else cout << "Нет" << endl;



	/*A = A - B;
	cout << A.get_z() << A.get_x() << "/" << A.get_y() << endl;
	A += B;
	cout << A.get_z() << A.get_x() << "/" << A.get_y() << endl;
	A -= B;
	cout << A.get_z() << A.get_x() << "/" << A.get_y() << endl;
	A *= B;
	cout << A.get_z() << A.get_x() << "/" << A.get_y() << endl;
	A /= B;
	cout << A.get_z() << A.get_x() << "/" << A.get_y() << endl;*/



	//A = B;
	//cout << A.get_z() <<A.get_x()<<"/"<< A.get_y() << endl;

	//A =A + B;

	//cout << A.get_z() << A.get_x() << "/" << A.get_y() << endl;

	//A = A * B;

	/*A = A / B;

	cout << A.get_z() << A.get_x() << "/" << A.get_y() << endl;*/
}

