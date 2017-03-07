/*问题描述

一个笼子里面关了鸡和兔子（鸡有2 只脚，兔子有4 只脚，没有例外）。已经知道了笼

子里面脚的总数a，问笼子里面至少有多少只动物，至多有多少只动物

输入数据

第1 行是测试数据的组数n，后面跟着n 行输入。每组测试数据占1 行，包括一个正整

数a (a < 32768)。

输出要求

n 行，每行输出对应一个输入。输出是两个正整数，第一个是最少的动物数，第二个是

最多的动物数，两个正整数用空格分开。如果没有满足要求的情况出现，则输出2 个0。

输入样例

2

3

20

输出样例

0 0

5 10
*/


#include <iostream>
#include <vector>

using namespace std;

void Calculate(const int n,unsigned int *pMin,unsigned int *pMax);

int main()
{
    unsigned int n;
    unsigned int *pMin = new unsigned int;
    unsigned int *pMax = new unsigned int;

    vector<unsigned int> inputData;
    vector<unsigned int> outData;

    cout<<"Please input data number n and datas.\n"<<endl;
    cin>>n;
    for(unsigned int i=0;i<n;i++)
    {
      unsigned int temp;
      cin>>temp;
      inputData.push_back(temp);
      Calculate(temp,pMin,pMax);

      outData.push_back(*pMin);
      outData.push_back(*pMax);
    }

// show the outputs
     cout<<"The result is:"<<endl;
     vector<unsigned int>::iterator it = outData.begin();
     while(it!=outData.end())
     {
       cout<<*it++<<" ";
       cout<<*it++<<endl;
     } 

     delete pMin;
     delete pMax;
     pMin = NULL;
     pMax = NULL;
     return 0;
}

void Calculate(const int n,unsigned int *pMin,unsigned int *pMax)
{
 if(n%2) 
  {
   *pMin = 0;
   *pMax = 0;
   return; 
  }

  *pMax = n/2;
  
  if(n%4==0)  *pMin = n/4;
  else     *pMin = n/4+1;
  return;
}
