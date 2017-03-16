/* 输入一个字符串，打印出该字符串中字符的所有排列。
 * 这个程序是参考《剑指offer》的参考代码。*/
#include <iostream>
#include <stdio.h>

using namespace std;

void Swap(char& a,char& b);
void Permutation(char* pString);
void Permutation(char* pStr,char* pBegin);

void Permutation(char* pString)
{
  if(pString==NULL) return;

  else Permutation(pString,pString);
}

void Permutation(char* pStr,char* pBegin)
{
  if(*pBegin=='\0')
  {
    cout<<pStr<<endl;
    return;
  }

  for(char* pCh = pBegin;*pCh!='\0';pCh++)
  {
    Swap(*pCh,*pBegin);
    Permutation(pStr,pBegin+1);
    Swap(*pCh,*pBegin);
  }
}

void Swap(char& a,char& b)
{
  char temp = a;
  a = b;
  b = temp;
}

int main()
{
  char pString[] = "abc";
  Permutation(pString);

  getchar();

  char pString2[]="aab";
  Permutation(pString2);

  return 0;
}
