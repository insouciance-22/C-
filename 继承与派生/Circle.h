#include"Point.h"
const double PI = 3.14159;
class Circle :public Point
{
private:
	double radius;
public:
	Circle(double R, int X, int Y) :Point(X, Y)
	{
		radius = R;
	}
	double area()
	{
		return PI * radius * radius;
	}
	void ShowCircle()
	{
		cout << "Centre of circle:";
		ShowXY();
		cout << "radius:" << radius << endl;
	}
};

