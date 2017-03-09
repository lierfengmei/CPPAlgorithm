
/*奶牛生子问题


描述：一只刚出生的奶牛，第4年开始生一只奶牛（假设只生母牛），以后每年生一只。现在给

你一只刚出生的奶牛，求20年后有多少奶牛？
*/

#include <iostream>

using namespace std;

unsigned int calCowNum(const unsigned int iYear)
{
	if(iYear<=3) return 1;
	if(iYear==4) return 2;
	return calCowNum(iYear-1)+calCowNum(iYear-4);
}

int main()
{
	int iYear,Num;
	while(1)
	{
	cout<<"Input the year:";
	cin>>iYear;
	cout<<"The num is "<<calCowNum(iYear)<<endl;
	}
	return 0;
}
