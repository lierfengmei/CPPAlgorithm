#include <iostream>
#include <math.h>

using namespace std;

int Count(int n, int s);
void PrintProbability(int n);


void PrintProbability(int n)
{
	if(n<=0) return;
	
	int base = pow(6,n);

	for(int i=n;i<=6*n;i++)
	{
		double pro = 0.0;
		if(Count(n,i)!=0)
		{
			pro =(double)Count(n,i)/base;
			cout<<"when n= "<<n<<", s = "<<i<<" , Probabilyty = "<<pro<<endl;
		}
	}
}


int Count(int n, int s)
{
	if(n<=0) return 0;
	if(n==1 && s>=1 && s<=6) return 1;
	if(n==1) return 0;

    int result = Count(n-1,s-1) +Count(n-1,s-2)+Count(n-1,s-3)+Count(n-1,s-4)+Count(n-1,s-5)+Count(n-1,s-6);
	return result;
}

int main()
{
	PrintProbability(1);
	
	PrintProbability(2);

	PrintProbability(3);
}
