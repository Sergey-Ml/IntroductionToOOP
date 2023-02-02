#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define WIDTH	20
#define delimiter "\n--------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	size_t size;	//ðàçìåð ñòðîêè â Áàéòàõ (size_t - unsigned int)
	char* str;		//àäðåñ ñòðîêè â äèíàìè÷åñêîé ïàìÿòè
public:
	size_t get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//				Constructors:
	explicit String(size_t size = 80):size(size), str(new char[size]{})
	{
		
		cout.width(WIDTH);
		cout << std::left << "DefaultConstructor:" << this << endl;
	}
	String(const char* str) :size(strlen(str) + 1), str(new char[size] {})
	{
		strcpy(this->str, str);	//strcpy - string copy
		//strcpy(dst, src);
		//dst - destination string (ñ òðîêà Â êîòîðóþ êîïèðóåì - ñòðîêà ïîëó÷àòåëü)
		//src - source string (ñòðîêà èñòî÷íèê - ñòðîêà, èç êîòîðîé êîïèðóåì)
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	String(const String& other) :size(other.size), str(new char[size] {})
	{
		strcpy(this->str, other.str);
		cout.width(WIDTH);
		cout << std::left << "CopyConstructor:" << this << endl;
	}
	String(String&& other):size(other.size), str(other.str)
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout.width(WIDTH);
		cout << std::left << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}

	//					Operators:
	String& operator=(const String& other)
	{
		//0) Ïðîâåðÿåì, íå ÿâëÿåòñÿ ëè ïðèíÿòûé îáúåêò íàøèì îáúåêòîì:
		if (this == &other)return *this;
		//1) Óäàëÿåì ñòàðîå çíà÷åíèå îáúåêòà
		delete[] this->str;
		//2) Deep copy:
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout.width(WIDTH);
		cout << std::left << "CopyAssignment:" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		//Shallow copy:
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout.width(WIDTH);
		cout << std::left << "MoveAssignment:" << this << endl;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}


	//					Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
#define WAYS_TO_CALL_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1(10);		//Default constructor
	str1.print();

	String str2 = "Hello";
	str2 = str2;
	str2.print();

	String str3 = str2;		//Copy constructor
	str3.print();

	String str4;
	str4 = str3;			//CopyAssignment
	str4.print();
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;

	str1 += str2;
	cout << str1 << endl;

	//cout << delimiter << endl;
	//String str3;
	//str3 = str1 + str2;
	//cout << delimiter << endl;
	//cout << str3 << endl;
	//Move semantic
	//MoveConstructor
	//MoveAssignment
	//Shallow copy  
#endif // OPERATOR_PLUS_CHECK

#ifdef WAYS_TO_CALL_CONSTRUCTORS
	String str1;			//Default constructor
	str1.print();

	String str2 = "Hello";	//Single-argument constructor
	str2.print();

	String str3 = str2;		//Copy constructor
	str3.print();

	String str4();	//Çäåñü ÍÅ âûçûâàåòñÿ Default constructor, 
	//çäåñü îáúÿâëÿåòñÿ ôóíêöèÿ str4, êîòîðàÿ íè÷åãî íå ïðèíèìàåò,
	//è âîçâðàùàåò çíà÷åíèå òèïà String
//str4.print();	//str4 - ýòî ôóíêöèÿ, à íå îáúåêò
//ßâíî âûçâàòü Default constructor ìîæíî òàê:
	String str5{};	//ßâíûé âûçîâ êîíñòðóêòîðà ïî óìîë÷àíèþ
	str5.print();

	String str6{ 8 };
	str6.print();

	String str7{ "Hello constructors" };
	str7.print();
#endif // WAYS_TO_CALL_CONSTRUCTORS

}