/*
 * 题目：用两个栈实现队列
 *用两个栈实现一个队列。队列的声明如下：请实现它的两个函数appendTail和deleteHead，
 *分别完成在队列尾部插入结点和队列头部删除结点的功能。
 * */
#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

template <typename T> class CQueue
{
  public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();

  private:
    stack<T> stack1;
    stack<T> stack2;
};


template<typename T> void CQueue<T>::appendTail(const T& node)
{
  stack1.push(node);
}

template<typename T>T CQueue<T>::deleteHead()
{
   //stack1和stack2都为空
   if((stack1.empty()) && (stack2.empty()))
  {
    cout<<"the Queue is empty,can not delelte!"<<endl;
    exit(1);
  }

 //stack2为空，stack1不为空。需要先将stack1中的值压入stack2中.
 if(!stack1.empty() && stack2.empty())
 {
   while(!stack1.empty())
   {
     T temp = stack1.top();
     stack1.pop();
     stack2.push(temp);
   }
 }
   
  if(!stack2.empty())
  {
    T deleteNum = stack2.top();
    stack2.pop();
    return deleteNum;
  }  

}

int main()
{
  return 0;
}
