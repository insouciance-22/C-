//friend �������� ������ ���βα�{}    
//����������ӵ��Ż�
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
	int tH, tM, tS;  //��ʱ�洢hms
	int carry = 0;  //��λ
	Clock tTime;    //��ʱ�洢ʱ��
	(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : tS += 60, carry = 1; 
	(tM = EndTime.M - StartTime.M-carry) > 0 ? carry = 0 : tM += 60, carry = 1;
	(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
	tTime.SetTime(tH, tM, tS);
	return tTime;
}
int main()
{
	Clock C = TripTime(Clock(8, 10, 10), Clock(6, 1, 2)); //���������뱻���ö��������ͬ���͵ģ����Ҫ�����ã���Ϊʵ����const Clock���ͣ������ββ���дClock&����Ӧдconst Clock&
		C.ShowTime();
		return 0;
}