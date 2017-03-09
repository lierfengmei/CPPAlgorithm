#include <iostream>

using namespace std;

struct CowAgeState
{
	int countAge1;
	int countAge2;
	int countAge3;
	int	countAgeGT4;
	int countAll;
};

CowAgeState YearState(const int year)
{	
	CowAgeState thisYear;
	if(1==year)
	{
		thisYear.countAge1=1;
		thisYear.countAge2=0;
		thisYear.countAge3=0;
		thisYear.countAgeGT4=0;
		thisYear.countAll=1;
		return thisYear;
	}
	CowAgeState lastYear=YearState(year-1);
	thisYear.countAge1=lastYear.countAgeGT4;
	thisYear.countAge2=lastYear.countAge1;
	thisYear.countAge3=lastYear.countAge2;
	thisYear.countAgeGT4=lastYear.countAge2+lastYear.countAgeGT4;
	thisYear.countAll=lastYear.countAll+lastYear.countAgeGT4;
	return thisYear;
}

int main()
{
	int year;
	int num;
	while(1)
	{
		cout<<"Plear input the year you want to count the cows:";
		cin>>year;
		num = YearState(year).countAll;
		cout<<"Tht cow number is :"<<num<<endl;
	}
	return 0;
}
