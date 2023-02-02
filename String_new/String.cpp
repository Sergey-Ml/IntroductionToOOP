#include"String_s.h"


size_t get_SI() const
{
	return SI;
}

const char* get_str() const
{
	return str;
}

char* get_str()
{
	return str;
}

//Constructor

explicit String(size_t size = 80) :SI(size), str(new char[SI] {})
{
	cout << "DefaultConstructor" << this << endl;
}



String(const char* st) :SI(strlen(st) + 1), str(new char[SI] {})
{
	strcpy(str, st);
	cout << "Constructor  " << this << endl;
}


String(const String& other) :SI(other.SI), str(new char[SI] {})
{
	strcpy(str, other.str);
	cout << "CopyConstructor  " << this << endl;
}

String(String&& other)
{
	this->SI = other.SI;
	this->str = other.str;
	other.SI = 0;
	other.str = nullptr;
	cout << "MoveConstructor  " << this << endl;

}

~String()
{
	delete[] str;
	cout << "Destructor  " << this << endl;
}

// Operators

String& operator=(const String& other)
{
	if (this == &other)
		return *this;
	delete[] str;
	this->SI = other.SI;
	str = new char [SI] {};
	strcpy(str, other.str);
	return *this;
	cout << "CopyAssignment: " << this << endl;
}

String& operator+=(const String& other)
{
	return *this = *this + other;
	cout << "PlusAssignment: " << this << endl;
}

String& operator=(String&& other)
{
	if (this == &other)
		return *this;
	delete[] str;
	this->SI = other.SI;
	str = other.str;
	other.SI = 0;
	other.str = nullptr;
	return *this;
	cout << "MoveAssignment: " << this << endl;
}

char& operator[](int i)
{
	return str[i];

}
const char& operator[](int i) const
{
	return str[i];

}



void print()
{
	cout << SI << endl;
	if (str != nullptr)
		cout << str << endl;
	else
		cout << "Строка пуста" << endl;
}



// Operators

String operator+(const String& left, const String& right)
{
	//int j = 0;
	int Ch = left.get_SI() + right.get_SI() - 1;
	String C(Ch);
	for (int i = 0; i < left.get_SI(); i++)
	{
		C[i] = left[i];
	}
	//for (int i = 6; i < 13; i++)
	//{

	//	C[i] = right[j];
	//	//j++;
	//}

	for (int i = 0; i < right.get_SI(); i++)
	{
		C[i + left.get_SI() - 1] = right[i];

	}
	return C;
}

std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}