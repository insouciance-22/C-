//火车旅途时间
#include<iostream>
using namespace std;
class Clock {
private:
	int H, M, S;
public:
	Clock(const Clock& p)
	{
		cout << "copy constructor,before call:" << H << ":" << M << ":" << S << endl;
		H = p.H;
		M = p.M;
		S = p.S;
	}
	~Clock()
	{
		cout << "destructor:" << H << ":" << M << ":" << S << endl;
	}
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
	int GetH()
	{
		return H;
	}
	int GetM()
	{
		return M;
	}
	int GetS()
	{
		return S;
	}

};
class TrainTrip {
private:
	char* TrainNo; //车次
	Clock StartTime; //出发时间
	Clock EndTime; //到达时间
public:
	TrainTrip(char* TrainNo,Clock S,Clock E) : StartTime(S), EndTime(E)
	{
		this->TrainNo = TrainNo;

	}
	Clock TripTime()
	{
		int tH, tM, tS;  //临时存储hms
		int carry = 0;  //借位
		Clock tTime;    //临时存储时间
		(tS = EndTime.GetS() - StartTime.GetS()) > 0 ? carry = 0 : tS += 60, carry = 1;
		(tM = EndTime.GetM() - StartTime.GetM()-carry) > 0 ? carry = 0 : tM += 60, carry = 1;
		(tH = EndTime.GetH() - StartTime.GetH()-carry) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}
};
int main()
{
	TrainTrip T1((char*)"K16", Clock(8, 10, 10), Clock(6, 1, 2));
	Clock C=T1.TripTime();
	C.ShowTime();
	return 0;
}
