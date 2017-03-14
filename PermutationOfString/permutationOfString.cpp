/* 输入一个字符串，打印出该字符串中字符的所有排列。
 * */
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <iterator>
#include <stdio.h>

using namespace std;

void PrintPermutation(char *pString);
void PrintVec(const vector<char>& vec);
void SubPrintPermutation(int length,map<char,int> charNumberMap,vector<char> vec);
void SubSubPrint(int length,map<char,int> charNumberMap,map<char,int>::iterator iter,vector<char> vec);


//　需要考虑的情况：１空格　2相同的字符。
//　step1:使用map 统计字符串种类，和字符串个数。
//  step2:  　
void PrintPermutation(char *pString)
{
  map<char,int> charNumberMap;

  char *pWalk = pString;

  //使用map统计每个字符的个数
  map<char,int>::iterator iter;
  while((*pWalk)!='\0') 
  {
    iter = charNumberMap.find(*pWalk);
    if(iter==charNumberMap.end()) charNumberMap[*pWalk] = 1;
    else charNumberMap[*pWalk]++;
    pWalk++;
  }

  int length = strlen(pString);

  vector<char> vec;
  vec.clear();
  SubPrintPermutation(length,charNumberMap,vec);
}

void PrintVec(const vector<char>& vec)
{
  vector<char>::const_iterator iter = vec.begin();
  while(iter!=vec.end())
  {
    cout<<*iter;
    iter++;
  }
  cout<<endl;
}

void SubPrintPermutation(int length,map<char,int> charNumberMap,vector<char> vec)
{
  if(length<0) return;

  if(length==0)
  {
    PrintVec(vec);
    return;
  }

  map<char,int>::iterator iter = charNumberMap.begin();

  cout<<"a's number is:"<<charNumberMap['a']<<endl;
  getchar();

  while(iter!=charNumberMap.end())
  {
    if(iter->second>0) 
    {
      /*
      iter->second--;
      vec.push_back(iter->first);
      SubPrintPermutation(length-1,charNumberMap,vec);
  */
      SubSubPrint(length,charNumberMap,iter,vec);
    }
    iter++;
  }
}

void SubSubPrint(int length,map<char,int> charNumberMap,map<char,int>::iterator iter,vector<char> vec)
{
  length--;
  iter->second--;
  vec.push_back(iter->first);
  SubPrintPermutation(length,charNumberMap,vec);
}

int main()
{
  char pString[] = "abc";
  PrintPermutation(pString);

  getchar();

//  char pString2[]="aabcd";
//  PrintPermutation(pString2);

  return 0;
}
