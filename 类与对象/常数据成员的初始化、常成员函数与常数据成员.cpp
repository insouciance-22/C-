#include<iostream>
using namespace std;
class Test {
public:
	Test():c(0)  //c是常数据成员，其初始化只能通过构造函数的初始化列表进行  括号内写初始值
	{ a = 0; }//c = 0; }//c是常数据成员，其初始化只能通过构造函数的初始化列表进行------静态常数据成员在类外进行说明和初始化eg.const int Test::d=3;
	int f(int a)const { this->a; }//常成员函数不能更新对象的数据成员，不能调用没有const修饰的成员函数，但是可以访问非常数据成员
	static int g() { return 0; }//静态成员函数不能直接访问类中的非静态成员,不能用const修饰
	                            //不能用const修饰原因：C++语法规定，const修饰符用于表示函数不能修改成员变量的值，该函数必须是含有this指针的类成员函数
	                            //既然一个静态成员函数根本不访问非静态数据成员，那么就没有必要使用const了
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