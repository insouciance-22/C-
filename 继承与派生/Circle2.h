#include"Point.h"
const double PI =3.14159;
class Circle :private Point
{
private:
	double radius;
public:
	Circle(double R, int X, int Y);
	double area();
	void ShowCircle();
	void move(int OffX, int OffY) //同名覆盖，类外可以通过对象访问
	{
		Point::move(OffX, OffY);
	}
};