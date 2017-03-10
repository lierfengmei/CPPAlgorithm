//请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。如9表示为1001,输出2.

#include <iostream>

using namespace std;

int CountOne(int n)
{
  if(n==0) return 0;


  int count = 0;
 // count += n>>31; //错误，负数的话右移是补1的！！！！！
 if(n<0) count++;
  cout<<"now ,count is:"<<count<<endl;
  n = n&0x7fffffff;
 while(n)
  {
    if(n&1) count++;
    n = n>>1;
  }

  return count;


}


int main()
{
  int n =-100;
  cout<<"CountOne("<<n<<") = "<<CountOne(n)<<endl;

  n = -199;
  cout<<"CountOne("<<n<<") = "<<CountOne(n)<<endl;

  n = 0x80000000;
  cout<<"CountOne("<<n<<") = "<<CountOne(n)<<endl;

  return 0;

}







