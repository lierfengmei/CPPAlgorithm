#include <iostream>
using namespace std;

void printAllMethod(const unsigned int Yuan)
{
	int Cent = 100*Yuan;
	unsigned int Max1Cent = Cent/1;
	unsigned int Max2Cent = Cent/2;
	unsigned int Max5Cent = Cent/5;
	int methodCount=0;
	for(int i=0;i<=Max1Cent;i++)
	  for(int j=0;j<=Max2Cent;j++)
		for(int z=0;z<=Max5Cent;z++)
		{
			if(Cent==i+j*2+z*5)
			{
				methodCount++;
				cout<<" 1Cent:"<<i<<" 2Cent:"<<j<<" 5Cent:"<<z<<endl;
			}
		}
	cout<<"There are totally "<<methodCount<<" methods"<<endl;
}




int main()
{
	int Yuan;
	while(1)
	{
	cout<<"Input the mondy you want to Combine(Yuan):";
	cin>>Yuan;
	printAllMethod(Yuan);
	}
	return 0;
}
