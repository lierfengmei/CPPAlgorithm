//题目;输入数字n，按顺序打印出从1到最大的n位十进制数。
//比如输入3.则打印1,2,3...,97,998,999.

//分析: 1 n<=0 无意义
//2 n是大数的情况 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void Print1ToMaxOfNDigits(int n);
bool Increment(char* number,int n);
void PrintNumber(char* number,int n);

void Print1ToMaxOfNDigits(int n)
{
    if(n<=0) return;

    char* number = new char[n+1];
    memset(number,'0',n);
    number[n]='\0';
    
    while(Increment(number,n))
    {
      PrintNumber(number,n);
//      getchar();
    }

    delete [] number;
}


bool Increment(char* number,int n)
{
  number[n-1] ++;
  for(int i=n-1;i>0;i--)
  {
    if(number[i]=='9'+1)
    {
      number[i] = '0';
      number[i-1] ++;
    }
    else break;
  }
  
  if(number[0]=='9'+1) return false;
  return true;
}

void PrintNumber(char* number,int n)
{

/*   char *number_print = new char[n+1];
   strcpy(number_print,number);
    int i=0;
    while(number_print[i]=='0')
    {
      number_print[i]=' ';
      i++;
    }  

  
    int  cout<<number_print<<endl;
    delete [] number_print;*/
 int i=0;
 while(number[i]=='0') i++;

 cout<<(number+i)<<endl;

}

int main()
{
  int n = 2;
  Print1ToMaxOfNDigits(n);
  cout<<"above ,n = "<<n<<endl;
getchar();

  n = -5;
  Print1ToMaxOfNDigits(n);
 cout<<"above ,n = "<<n<<endl;
getchar();

  n = 1;
  Print1ToMaxOfNDigits(n);
 cout<<"above ,n = "<<n<<endl;
getchar();

  n = 3;
  Print1ToMaxOfNDigits(n);
 cout<<"above ,n = "<<n<<endl;
getchar();

  n = 7;
  Print1ToMaxOfNDigits(n);
 cout<<"above ,n = "<<n<<endl;
getchar();

  n = 10;
  Print1ToMaxOfNDigits(n);
 cout<<"above ,n = "<<n<<endl;
getchar();

 n = 20;
  Print1ToMaxOfNDigits(n);
 cout<<"above ,n = "<<n<<endl;
getchar();
}




