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
	void move(int OffX, int OffY) //ͬ�����ǣ��������ͨ���������
	{
		Point::move(OffX, OffY);
	}
};