#include<iostream>
using namespace std;
class Test {
public:
	Test():c(0)  //c�ǳ����ݳ�Ա�����ʼ��ֻ��ͨ�����캯���ĳ�ʼ���б����  ������д��ʼֵ
	{ a = 0; }//c = 0; }//c�ǳ����ݳ�Ա�����ʼ��ֻ��ͨ�����캯���ĳ�ʼ���б����------��̬�����ݳ�Ա���������˵���ͳ�ʼ��eg.const int Test::d=3;
	int f(int a)const { this->a; }//����Ա�������ܸ��¶�������ݳ�Ա�����ܵ���û��const���εĳ�Ա���������ǿ��Է��ʷǳ����ݳ�Ա
	static int g() { return 0; }//��̬��Ա��������ֱ�ӷ������еķǾ�̬��Ա,������const����
	                            //������const����ԭ��C++�﷨�涨��const���η����ڱ�ʾ���������޸ĳ�Ա������ֵ���ú��������Ǻ���thisָ������Ա����
	                            //��Ȼһ����̬��Ա�������������ʷǾ�̬���ݳ�Ա����ô��û�б�Ҫʹ��const��
	void h(int b) { Test::b = b; };
private:
	int a;
	static int b;
	const int c;
};
int main()
{
	const Test c;
	c.f(0);
}