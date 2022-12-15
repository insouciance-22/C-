#include"Circle.h"
class Cylinder :public Circle
{
private:
	double height;
public:
	Cylinder(int X, int Y, double R, double H) :Circle(X, Y, R)
	{
		height = H;
	}
	void ShowCylinder()
	{
		ShowCircle();
		cout << "height of cylinder:" << height << endl;
	}
};
int main()
{
	Point P(1, 1);
	Circle Cir(20, 20, 15.5);
	Cylinder CY(300, 300, 15.5, 50);
	Point* Pp;
	Pp = &P;
	Pp->ShowXY();
	P.ShowXY();
	Circle& RC = CY;
	RC.ShowXY();
	P = Cir;
	P.ShowXY();
	return 0;
}