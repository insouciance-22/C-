#include<iostream>
using namespace std;
#define ADD(x)  x+x
int main()
{
	int m = 1, n = 2, k = 3;
	//int sum = ADD(n + m) * k;  //x��n+m����  �൱��int sum=n+m+n+m*k
    int  sum = ADD((n + m)) * k;//���������൱��x=n+m���������12
	cout << sum;
}