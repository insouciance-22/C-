#include<iostream>
using namespace std;
const int MaxN = 100;
const double Rate = 0.6;//ƽʱ�ɼ�����
class Score {
private:
	long No;
	char* Name;
	int Usual;
	int Final;
	int Total;
public:
	void Count();
	void ShowScore();
	//���캯��
	Score(int = 0,char *name= NULL, int = 0, int = 0, int = 0);
};
Score::Score(int no,char *name, int usual, int final, int total)//������Ĭ�ϲ���ֻ�ܸ�һ�Σ�����ʱ���ˣ�����ʱ�Ͳ����ٸ�һ�Σ���ʹ��ȫһ��Ҳ����
{
	No = no;
	Name = name;
	Usual = usual;
	Final = final;
	Total = total;
}
void Score::Count()
{
	Total = Usual * Rate + Final * (1 - Rate)+0.5;  //+0.5��Ϊ���������룬�������Ϊ84.6��ת����int��ʱֱ����ȥС�������Լ�0.5���Ϳ���ʵ����������
}
void Score::ShowScore()
{
	cout << No << "\t" << Name << "\t" << Usual << "\t" << Final << "\t" << Total << endl;
}
int main()
{
	Score ClassScore1[3];
	Score ClassScore2[3] = { Score(20200701,(char*)"Ye Xiaolu",88,79,0),
						     Score(20200702,(char*)"Luo Zhangxing",90,85,0),
						     Score(20200701,(char*)"Wu Weixue",77,55,0) };
	for (int i = 0; i < 3; i++)
	{
		ClassScore2[i].Count();  //���ú���ʱ�ǵ�д�βα������βα�Ϊ��ҲҪд������,����һֱ�����Ҳ���������
	}
	for (int i = 0; i < 3; i++)
	{
		ClassScore2[i].ShowScore();
	}
	return 0;
}