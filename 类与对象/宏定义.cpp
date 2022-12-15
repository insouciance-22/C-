#include<iostream>
using namespace std;
#define ADD(x)  x+x
int main()
{
	int m = 1, n = 2, k = 3;
	//int sum = ADD(n + m) * k;  //x用n+m代替  相当于int sum=n+m+n+m*k
    int  sum = ADD((n + m)) * k;//这样才是相当于x=n+m，结果才是12
	cout << sum;
}