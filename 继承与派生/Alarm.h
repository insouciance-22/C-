#include<iostream>
using namespace std;
class Clock {
private:
	int H, M, S;
public:
	void SetTime(int H = 0, int M = 0, int S = 0);
	void ShowTime();
	Clock(int H = 0, int M = 0, int S = 0);
	~Clock();
};
class AlarmClock : public Clock
{
private:
	int AH, AM;
	bool OpenAlarm;
public:
	void SetAlarm(int AH, int AM);
	void SwitchAlarm(bool OpenAlarm = true);
	void ShowTime();
};
