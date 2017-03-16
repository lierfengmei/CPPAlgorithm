#include <iostream>

using namespace std;


enum Status{Invalid,Valid}status;
long long strToIntCore(char* pString,bool minus);
int strToInt(char* pString);


//pString==NULL "" 异常字符　＋－ 0x7FFF FFFF 0x8000 0000溢出
int strToInt(char* pString)
{
  if(pString==NULL || *pString=='\0') 
  {
    status = Invalid;
    return 0;
  }

  char FirstChar = *pString;
  if((FirstChar=='+' || FirstChar=='-')&&(*(pString+1)=='\0'))
  {
    status = Invalid;
    return 0;
  }

  if(FirstChar=='+') return strToIntCore(pString+1,false);
  else if(FirstChar=='-') return strToIntCore(pString+1,true);
  else return strToIntCore(pString,false);
}

long long strToIntCore(char* pString,bool minus)
{
  if(pString==NULL || *pString=='\0')
  {
    status = Invalid;
    return 0;
  }

  int flag = minus?-1:1;
  long long Sum = 0;

  while(*pString!='\0')
  {
    if((*pString)<'0'||(*pString)>'9')
    {
      status = Invalid;
      return 0;
    }
    
    Sum = Sum*10 +flag*(*pString-'0');
    if((minus&&Sum<0x80000000)||(!minus&&Sum>0x7fffffff))
    {
      status = Invalid;
      return 0;
    }

    pString++;
  }
  
  return Sum;
}
