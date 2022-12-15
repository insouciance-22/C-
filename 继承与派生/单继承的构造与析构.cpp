#include<iostream>
using namespace std;
class Point {
private:
	int X, Y;
public:
	Point(int X = 0, int Y = 0)
	{
		this->X = X, this->Y = Y;
		cout << "point(" << X << "," << Y << ")constructing..." << endl;
	}
	~Point()
	{
		cout << "point(" << X << "," << Y << ")destructing..." << endl;
	}
};
class Circle :protected Point
{
protected:
	double radius;
public:
	Circle(double R = 0, int X = 0, int Y = 0) :Point(X, Y)
	{
		radius = R;
		cout << "circle constructing,radius:" << R << endl;
	}
	~Circle()
	{
		cout << "circle destructing ,radius:" << radius << endl;
	}
};
class tube :protected Circle
{
private:
	double height;
	Circle InCircle;
public:
	tube(double H, double R1, double R2 = 0, int X = 0, int Y = 0) :
		InCircle(R2, X, Y), Circle(R1, X, Y)
	{
		height = H;
		cout << "tube constructing ,height:" << H << endl;
	}
	~tube()
	{
		cout << "tube destructing,height:" << height << endl;
	}
};
int main()
{
	tube TU(100, 20, 5);
	return 0;
}