//friend 返回类型 函数名 （形参表）{}    
//组合类里例子的优化
#include<iostream>
using namespace std;
class Clock {
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M, this->S = S;
	}
	Clock(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M, this->S = S;
		cout << "constructor:" << H << ":" << M << ":" << S << endl;
	}
	friend Clock TripTime(Clock StartTime, Clock EndTime);
};
Clock TripTime(Clock StartTime, Clock EndTime)
{
	int tH, tM, tS;  //临时存储hms
	int carry = 0;  //借位
	Clock tTime;    //临时存储时间
	(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : tS += 60, carry = 1; 
	(tM = EndTime.M - StartTime.M-carry) > 0 ? carry = 0 : tM += 60, carry = 1;
	(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
	tTime.SetTime(tH, tM, tS);
	return tTime;
}
int main()
{
	Clock C = TripTime(Clock(8, 10, 10), Clock(6, 1, 2)); //对象引用与被引用对象必须是同类型的，如果要用引用，因为实参是const Clock类型，所以形参不能写Clock&，而应写const Clock&
		C.ShowTime();
		return 0;
}