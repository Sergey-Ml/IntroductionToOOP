#include<iostream>
using namespace std;

#define WIDTH 22

class Point
{
double x;
	double y;
	
public:
	double get_x()const
	{
		return x;
	} 
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this ->x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

	/*Point()
	{
		x = y = double();
		cout.width(WIDTH);
		cout << left << "Constructor: \t " << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout.width(WIDTH);
		cout << left << "SingleArgContructor: \t " << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout.width(WIDTH);
		cout << left << " Contructor: \t " << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout.width(WIDTH);
		cout << left << " CopyContructor: \t " << this << endl;
	}


	~Point()
	{
		cout.width(WIDTH);
		cout << left << " Destructor: \t " << this << endl;
	}
	// Operators:

	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout.width(WIDTH);
		cout << left << " CopyAssingment: \t " << this << endl;
	}
}; 


void main()
{
	setlocale(LC_ALL, "");
	Point A;
	//A.print();
	//Point B = 5;
	//B.print();
	//Point C (2,3);
	//C.print();
	//Point D=C; // 
	//D.print();
	//Point E;
	//E = D;
	//E.print();



	/*A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA << endl;
	cout << pA->x << "\t" << pA->y << endl;*/
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
} 