#include "String_s.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	String A("hello");
	A.print();

	//String B(A);
	String B (" World!!");
	B.print();
	
	String C = A + B;
	C.print();

	B += A;
	C.print();
	cout << B << endl;

}