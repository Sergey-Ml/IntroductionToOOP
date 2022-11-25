#include <iostream>
using namespace std;

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
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

		
	double distance(Point C)
{
		double x_distance = this->x - C.x;
		double y_distance = this->y - C.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}



int main()
{
	setlocale(LC_ALL, "");
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(5);
	B.set_y(7);
	double D = A.distance(B);
	cout << D << endl;
	cout << A.distance(B) << endl;
	D = distance(A,B);
    cout << D << endl;
    cout << distance(A,B) << endl;

}