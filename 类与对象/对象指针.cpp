#include<iostream>
using namespace std;
class Clock {
     private:
         int H, M, S;
     public:
         void SetTime(int h, int m, int s)
         {
             H = h, M = m, S = s;
         }
         void ShowTime() {
             cout << H << ":" << M << ":" << S << endl;
         }
         //构造函数
         Clock(int h = 0, int m = 0, int s = 0)
         {
             H = h, M = m, S = s;
         }
         //拷贝构造
        Clock(const Clock& p)
         {
             H = p.H, M = p.M, S = p.S;
         }
         void TimeAdd(Clock* Cp);
         void TimeAdd(int h, int m, int s);
         void TimeAdd(int s);
         void TimeAdd(Clock& p);
};
void Clock::TimeAdd(Clock*Cp)
{
    H = (Cp->H + H + (Cp->M + M + (Cp->S + S) / 60) / 60) % 24; //Cp->H和H都是指传入的实参对象的H,该函数实现的功能是自己加自己
    M = (Cp->M + M + (Cp->S + S) / 60) % 60;
    S = (Cp->S + S) % 60;
}
void Clock::TimeAdd(int h, int m, int s)
{
    H = (h + H + (m + M + (s + S) / 60) / 60) % 24;
    M = (m + M + (s + S) / 60) % 60;
    S = (s + S) % 60;
}
void Clock::TimeAdd(int s)
{
    H = (H + (M + (s + S) / 60) / 60) % 24;
    M = (M + (s + S) / 60) % 60;
    S = (s + S) % 60;
}
void Clock::TimeAdd(Clock& p)
{
    H = (p.H + H + (p.M + M + (p.S + S) / 60) / 60) % 24;
    M = (p.M + M + (p.S + S) / 60) % 60;
    S = (p.S + S) % 60;
}

int main()
{
    Clock C1;
    Clock C2(8, 20, 20);
    Clock C3(6, 0, 0);
    C1.TimeAdd(4000);
    C1.ShowTime();
    C2.TimeAdd(C2);
    C2.ShowTime();
    C3.TimeAdd(&C3);
    C3.ShowTime();
    return 0;
}




