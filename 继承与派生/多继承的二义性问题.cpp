#include<iostream>
using namespace std;
class Car               // 小客车类
{
private:
	int power; 
	int seat;
public:
	Car(int power, int seat)
	{
		this->power = power;
		this->seat = seat;
	}
	void show()
	{
		cout << "car power:" << power << "   seat:" << seat << endl;
	}
};
class Wagon               //小货车类
{
private:
	int power;
	int load;
public:
	Wagon(int power, int load)
	{
		this->power = power, this->load = load;
	}
	void show()
	{
		cout << "wagon power:" << power << "    load:" << load << endl;
	}
};
class StationWagon :public Car, public Wagon                //客货两用车类
{
public:
	StationWagon(int power,int seat,int load):Wagon(power,load),
		Car(power,seat){}
	void ShowSW()
	{
		cout << "StationWagon:" << endl;
		Car::show();
		Wagon::show();
	}
};
int main()
{
	StationWagon SW(105, 3, 8);
	//SW.show();          //错误，出现二义性  解决方法：1、通过类的作用域分辨符  Car：：show()   2、同名覆盖
	SW.ShowSW();
	return 0;
}