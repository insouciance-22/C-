#include<iostream>
using namespace std;
class Clock {
private: int H, M, S;
public:
    //���幹�캯��
    Clock* p;
    Clock(int h = 0, int m = 0, int s = 0)
    {
        H = h, M = m, S = s;
        cout << "constructor:" << H << ":" << M << ":" << S << endl;
    }
    //���忽�����캯��----���¶��忽�����캯����Ĭ�Ͽ������캯����Ĭ�Ϲ��캯���Ͳ������ˣ������Լ����幹�캯��������
    
    Clock(const Clock& p)
    {
        cout << "copy constructor,before call:" << H << ":" << M << ":" << S << endl;
        H = p.H;
        M = p.M;
        S = p.S;
    }
    //������������
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
    fun(C3);//���μ�����ʱ��������һ�ο������캯��
    fun((5, 5, 5));//����ʱ�൱�ڸ�c��ʼ���������ǽ���һ���������Ƹ�c�����Ե��õ��ǹ��캯�������ǿ������캯����ֻ�ڷ���ʱ����ʱ���ض�����ʱ������һ�ο������캯��
    //�����൱��ֻ����ȥһ��5��ֻ��H��ֵ5��MSΪĬ��ֵ   
    //(5,5,5)����int5������coutһ������
    fun(Clock(5, 5, 5));//�൱�ڴ���һ�������󣬿������캯���β�Ҫ��const���������Ͳ�ƥ��
    //Ϊ�˰�ȫ�ͼ�����һ�㶼��const����Ϊ��������һ�㲻�ı䴫��Ĳ���
    return 0;
}