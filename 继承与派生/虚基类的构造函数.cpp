#include<iostream>
using namespace std;
class Automobile       //Æû³µÀà
{
private:
	int power;
public:
	Automobile(int power)
	{
		this->power = power;
		cout << "Automobile constructing..." << endl;
	}
	void show()
	{
		cout << "	power:" << power;
	}
};
class Car :virtual public Automobile
{
private:
	int seat;
public:
	Car(int power, int seat) :Automobile(power)
	{
		this->seat = seat;
		cout << "Car constructing..." << endl;
	}
	void show()
	{
		cout << "car:";
		Automobile::show();
		cout << "		seat:" << seat << endl;
	}
};
class Wagon :virtual public Automobile
{
private:
	int load;
public:
	Wagon(int power, int load) :Automobile(power)
	{
		this->load = load;
		cout << "Wagon constructing..." << endl;
	}
	void show()
	{
		cout << "wagon:";
		Automobile::show();
		cout << "		load:" << load << endl;
	}
};
class StationWagon :public Car, public Wagon
{
public:
	StationWagon(int CPower, int WPower, int seat, int load) :Automobile(CPower), Wagon(WPower, load), Car(CPower, seat)
	{
		cout << "StationWagon constructing..." << endl;
	}
	void show()
		{
			cout << "StationWagon:";
			Car::show();
			Wagon::show();
		}
};
int main()
{
	StationWagon SW(105, 108, 3, 8);
	SW.show();
	return 0;
}