/**包含因子 2 3 5的数称为丑数，求输入n，输出第n个丑数
 */
#include <iostream>
using namespace std;

long long FindUglyNum(int n)
{
	if(n<1) return 0;

	if(1==n) return 1;

	long long* UglyNum = new long long[n+1];
	UglyNum[1] = 1;
	int index2 = 1;
	int index3 = 1;
	int index5 = 1;

	for(int i=2;i<=n;i++)
	{
		//get index2,index3,index5
		while((UglyNum[index2]*2)<=UglyNum[i-1]) index2++;
		while((UglyNum[index3]*3)<=UglyNum[i-1]) index3++;
		while((UglyNum[index5]*5)<=UglyNum[i-1]) index5++;
		//get UglyNum[i]
		UglyNum[i] = min(UglyNum[index2]*2,UglyNum[index3]*3);
		UglyNum[i] = min(UglyNum[index5]*5,UglyNum[i]);
	}

	for(int i=1;i<=n;i++)
		cout<<"n = "<<i<<" The nth unglyNumber is "<<UglyNum[i]<<endl;

	long long result = UglyNum[n];

	delete [] UglyNum;
	UglyNum = NULL;

	return result; 
}


int main()
{
	int n =50;
	FindUglyNum(n);
	return 0;
}
