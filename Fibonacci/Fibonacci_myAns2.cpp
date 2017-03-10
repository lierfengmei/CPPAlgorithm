// 这个答案用的是循环，而不是迭代。因为循环效率会比迭代好。

#include <iostream>


using namespace std;


long long Fibonacci(unsigned int n)
{
  if(n<=0) return 0;
  if(n==1 || n==2) return 1;

  long long a1=1,a2=1,a3=0;

 unsigned int i=3;
  while(i<=n)
  {
    a3 = a1 + a2;
    a1 = a2;
    a2 = a3;
    i++;
  }
 return a3;

}

int main()
{
  unsigned int n = 100;
  for(int i=1;i<=n;i++)
    cout<<"Fibonacci("<<i<<") = "<<Fibonacci(i)<<endl;
  return 0;
}



