#include"Circle.h"
using namespace std;
int main()
{
	Circle Cir1(10, 100, 200);
	Cir1.ShowCircle();
	cout << "area is:" << Cir1.area() << endl;
	Cir1.move(10, 20);
	Cir1.ShowXY();
	return 0;
}