#include <iostream>
#include <string.h>
using namespace std;


void ReplaceBlank(char str[], const unsigned int length)
{
    if(NULL==str || 0==length)
      return;

    int BlankCount = 0;

    //计算Blank的个数
    for(int i=0;i<length;i++)
    {
      if(*(str+i)==' ') BlankCount++; //pay attention!字符用‘’，字符串用""，不要写Python写晕了- -
    }

    //从后往前一一替换空格
    int oldLength = length;
    int newLength = length + 2*BlankCount;
    while(BlankCount>=0)
    {
      if(str[oldLength]!=' ') str[newLength] = str[oldLength];
      else
      {
        str[newLength--]='0';
        str[newLength--]='2';
        str[newLength]='%';
        BlankCount--;
      }
      oldLength--;
      newLength--;
    }
    return;

}

int main()
{
  char str[]="   ";
  cout<<"Old string is : "<<str<<endl;

  ReplaceBlank(str,strlen(str));
  cout<<"New string is:"<<str<<endl;
    
  return 0;
}
