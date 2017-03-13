/*
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个是否为栈的弹出顺序。
 * 假设压入栈的所有的数字均不相等。
 * 如序列1,2,3,4,5是某栈的压栈序列。序列4,5,3,2,1是该压栈序列对应的一个弹出顺序；
 * 但是4,3,5,1,2不可能为栈的弹出顺序。
 * */

#include <iostream>
#include <stack>

using namespace std;


//整数序列A，整数序列B
bool IfPopStack(const int *pPushSeq,const unsigned lengthPush,const int *pPopSeq,const unsigned lengthPop)
{
  if(pPushSeq==NULL || pPopSeq == NULL || lengthPush==0 || lengthPop==0 || lengthPush!=lengthPop)
  {
    cout<<"Invalid input parameter!"<<endl;
    return false;
  }

    const int* pPush = pPushSeq;
    const int* pPop = pPopSeq;

    //增加辅助栈
    stack<int> tempStack;
    for(int i=0;i<lengthPush;)
    {
      tempStack.push(*pPush);
      pPush++;
      i++;
      while(tempStack.size()!=0 && tempStack.top()==(*pPop))
      {
        pPop++;
        tempStack.pop();
      }
    }

    if(tempStack.size()==0) return true;
    else return false;
}


int main()
{
  int pPushSeq[]={1,2,3,4,5};
  int pPopSeq[] = {4,5,3,2,1};

  bool result = IfPopStack(pPushSeq,5,pPopSeq,5);
  if(result)
    cout<<"True"<<endl;
  else
    cout<<"False"<<endl;

  int pPopSeq2[]={4,3,5,1,2};
  result = IfPopStack(pPushSeq,5,pPopSeq2,5);
  if(result)
    cout<<"True"<<endl;
  else
    cout<<"False"<<endl;

  return 0;
}


