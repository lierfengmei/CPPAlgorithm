/*
 * 题目：第一个只出现一次的字符
 * 问题描述：在字符串中找出第一个只出现一次的字符，如输入"abaccdeff"，则输出'b'
 * */
#include <iostream>
using namespace std;


char FirstNotRepeatingChar(char* pString)
{
  if(pString==NULL) return '\0';

  unsigned int times[256]={0};
    
  //记录每个字符出现的次数
  char *pWalk = pString;
  while((*pWalk)!='\0')
  {
    times[*pWalk]++;
    pWalk++;
  }

  //查找第一个不重复的字符，并返回
  pWalk = pString;
  while((*pWalk)!='\0')
  {
    if(times[*pWalk]==1) return *pWalk;
    else pWalk++;
  }
  
  return '\0';
}

int main()
{
  //char *pString = "abaccdeff";  //deprecated conversiton from string constant to char*,不能修改该字符串的内容。
  char pString[] = "abaccdeff";
  char FirstChar = FirstNotRepeatingChar(pString);
  cout<<"The first not repeating char is: "<<FirstChar<<endl;

  return 0;
}
