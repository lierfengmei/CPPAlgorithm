#include <iostream>
#include <math.h>

using namespace std;

int CalculatePrimes(const unsigned int min,const unsigned int max);

int main()
{
   unsigned int min,max;
   cout<<"Calculate primes between min~max (Including min and max)."<<endl;
   cout<<"Please input min(unsigned int):";
   cin>>min;
   cout<<"Please input max(unsigned int):";
   cin>>max;

  int count =  CalculatePrimes(min,max);
  cout<<"There are total "<<count<<" primes."<<endl;
  return 0;
}

int CalculatePrimes(const unsigned int min,const unsigned int max)
{
  int i,j;
  int count = 0;
  int min_tmp = min;
  
  if(min<=2)
  {
    cout<<2<<" ";
    count ++;
    min_tmp=3;
  } 
     
  for(i=min_tmp;i<=max;i++)
  {
    for(j=2;j<=sqrt(i);j++)
    {
      cout<<"j is" <<j<<endl;
      cout<<"sqrt(i) is "<<sqrt(i)<<endl;
      if(i%j==0)// break;
      {
//        cout<<i <<"is divided by "<<j<<endl;
        break;
      }
    }
  if(j==(sqrt(i)))
  {
    cout<<i<<" ";
    count++;
    if(count%10==0) cout<<endl;
  }
   }
  return count;
}
