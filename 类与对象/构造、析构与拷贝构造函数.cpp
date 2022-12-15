#include<iostream>
using namespace std;
class Clock {
private: int H, M, S;
public:
    //定义构造函数
    Clock* p;
    Clock(int h = 0, int m = 0, int s = 0)
    {
        H = h, M = m, S = s;
        cout << "constructor:" << H << ":" << M << ":" << S << endl;
    }
    //定义拷贝构造函数----重新定义拷贝构造函数后，默认拷贝构造函数与默认构造函数就不存在了，必须自己定义构造函数！！！
    
    Clock(const Clock& p)
    {
        cout << "copy constructor,before call:" << H << ":" << M << ":" << S << endl;
        H = p.H;
        M = p.M;
        S = p.S;
    }
    //定义析构函数
    ~Clock()
    {
        cout << "destructor:" << H << ":" << M << ":" << S << endl;
    }

};
Clock fun(Clock c)
{
    return c;
}
Clock C1;
Clock C2(2, 0, 0);
int main()
{
    Clock C3(3, 0, 0);
    Clock C4;
    C4 = C1;
    fun(C3);//传参及返回时都调用了一次拷贝构造函数
    fun((5, 5, 5));//传参时相当于给c初始化，而不是将另一个变量复制给c，所以调用的是构造函数而不是拷贝构造函数，只在返回时给临时返回对象复制时调用了一次拷贝构造函数
    //但是相当于只传进去一个5，只给H赋值5，MS为默认值   
    //(5,5,5)就是int5，可以cout一下试试
    fun(Clock(5, 5, 5));//相当于传了一个常对象，拷贝构造函数形参要有const，否则类型不匹配
    //为了安全和兼容性一般都用const，因为拷贝构造一般不改变传入的参数
    return 0;
}