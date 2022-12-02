#include<iostream>
using std::cin;
using std::cout;
using std::endl;

//#define WIDTH 32;

class Fraction
{
	int integer;
	int numerator;
	int denumerator;

public:

	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denumerator()const
	{
		return denumerator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}


	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}


	void set_denumerator(int denumerator)
	{
		if (denumerator == 0) denumerator = 1;
		this->denumerator= denumerator;

	}

	// Constructors

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denumerator =1;
		cout << "DefaultConstructor:" << this << endl;
	}

	Fraction(int integer)
	{
		
		this->integer = integer;
		this->numerator = 0;
		this->denumerator = 1;
		
		cout << std::left<< "SingleArgumentConstructor:" << this << endl;
	}

	Fraction(int numerator, int denumerator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denumerator(denumerator);
		cout << "Constructor:\t" << this << endl;
	}


	Fraction(int integer, int numerator, int denumerator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denumerator(denumerator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denumerator = other.denumerator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// OPerators

	Fraction& operator = (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denumerator = other.denumerator;
		cout << "CopyAssignvent:\t" << this << endl;
		return *this;
	}

	// Metods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denumerator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}


};

void main()
{
	setlocale(LC_ALL, "");

	Fraction A; // Default constructor
	A.print();

	Fraction B = 5; // single argument 
	B.print();

	Fraction C (1,2); // single argument 
	C.print();
    
	Fraction D(2, 3, 4); // single argument 
	D.print();

	Fraction E = D; // single argument 
	E.print();

	Fraction F; // single argument 
	F = E;
	F.print();



}