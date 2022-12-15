//���������
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
int Student::countS = 0;//��̬���ݳ�Ա�Ķ���һ��Ҫ��ȫ���������ڶ��壬
          //���������ͻ�����������ľ�̬���ݳ�Ա
          //��̬���ݳ�Ա�����������������
          //��̬���ݳ�Ա��const�����п����޸ģ�����ͨ�����ݳ�Ա����
 //��̬��Ա��������ʹ�����η�const
int main()
{
	cout << Student::GetCount() << endl;
	Student s1((char*)"Antony");
	s1.countS;
	cout << s1.GetCount() << endl;

}