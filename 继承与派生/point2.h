#include<iostream>
using namespace std;
class Point {
protected:
	int X, Y;
public:
	Point(int X = 0, int Y = 0)
	{
		this->X = X, this->Y = Y;
	}
	void move(int OffX, int OffY)
	{
		X += OffX, Y += OffY;
	}
	void ShowXY()
	{
		cout << "(" << X << "," << Y << "£©" << endl;
	}
};

