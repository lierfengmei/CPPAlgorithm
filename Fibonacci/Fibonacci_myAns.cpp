#include <iostream>

using namespace std;

int Fibonacci(const int n)
{
  if(1==n||2==n) return 1;
  else    return Fibonacci(n-1)+Fibonacci(n-2);
}


int main()
{
    int n;
    while(1)
    {
     cout<<"Please input n:";
     cin>>n;
     cout<<"Fibonacci(n) is: "<<Fibonacci(n)<<endl;
    }
    return 0;
}
