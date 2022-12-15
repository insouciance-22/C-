//对象计数器
#include<iostream>
using namespace std;
class Student {
private:
	char* Name;
	int No;
public:static int countS;
public:
	static int GetCount()
	{
		return countS;
	}
	Student(char * =NULL, int = 0);
	Student(Student&);
	~Student();
};
Student::Student(char* Name, int No)
{
	this->Name = new char[strlen(Name) + 1];
	//strcpy(this->Name, Name);
	this->No = No;
	++countS;
	cout << "constructing:" << Name << endl;
}
Student::Student(Student& r)
{
	Name = new char[strlen(r.Name) + 1];
	//strcpy(Name, r.Name);
	No = r.No;
	++countS;
	cout << "copy constructing:" << r.Name << endl;
}
Student::~Student()
{
	cout << "destructing:" << Name << endl;
	delete[]Name;
	--countS;
}
int Student::countS = 0;//静态数据成员的定义一定要在全局作用域内定义，
          //派生类对象和基类对象共享基类的静态数据成员
          //静态数据成员可以是所属类的类型
          //静态数据成员在const函数中可以修改，而普通的数据成员不行
 //静态成员函数后不能使用修饰符const
int main()
{
	cout << Student::GetCount() << endl;
	Student s1((char*)"Antony");
	s1.countS;
	cout << s1.GetCount() << endl;

}