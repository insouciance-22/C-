#include<iostream>
using namespace std;
const int MaxN = 100;
const double Rate = 0.6;//平时成绩比例
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
	//构造函数
	Score(int = 0,char *name= NULL, int = 0, int = 0, int = 0);
};
Score::Score(int no,char *name, int usual, int final, int total)//函数的默认参数只能给一次，声明时给了，定义时就不能再给一次，即使完全一样也不行
{
	No = no;
	Name = name;
	Usual = usual;
	Final = final;
	Total = total;
}
void Score::Count()
{
	Total = Usual * Rate + Final * (1 - Rate)+0.5;  //+0.5是为了四舍五入，如果分数为84.6，转换成int型时直接舍去小数，所以加0.5，就可以实现四舍五入
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
		ClassScore2[i].Count();  //调用函数时记得写形参表，就算形参表为空也要写个括号,否则一直报错还找不到错在哪
	}
	for (int i = 0; i < 3; i++)
	{
		ClassScore2[i].ShowScore();
	}
	return 0;
}