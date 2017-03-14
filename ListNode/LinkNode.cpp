#include <iostream>

using namespace std;

struct ListNode
{
  int m_data;
  ListNode *pNext;
};


//在该链表的末尾添加一个节点
ListNode* AddTailNode(ListNode** pphead,const int m_data)
{
  ListNode *pNode = new ListNode;
  pNode->m_data = m_data;
  pNode->pNext = NULL;
 
  ListNode* phead = *pphead;

  if(NULL==phead) 
  {
    phead = pNode; 
    return phead;
  }

  ListNode *p =phead;
  while(p->pNext!=NULL)
  {
    p = p->pNext;
  }
  p->pNext = pNode;

  return phead;

}

//在链表中找到第一个含有某值的节点并删除该节点
//考虑情况：1 该链表为空 2 找不到该值 3 该值在phead节点上 4 该值在最末节点上.
//如果删除了head节点，那么phead指针发生变化，所以需要二级指针

void RemoveNode(ListNode **phead,const int m_data)
{
    if(NULL==*phead)      //case 1:链表为空
    {
      cout<<"该链表为空"<<endl;
      return ;
    }
    // case3:只有1个节点，删除完后该链表为空
  /*  if(*phead->pNext==NULL)
    {
      if(m_data==*phead->m_data)
       *phead = NULL; 
      return;
    }
*/
    //case3 and 4:该值在head节点上
    if(m_data==*phead->m_data)
    {
      ListNode *pDelete = *phead;
        *phead = *phead->pNext;
        delete pDelete;
        pDelete = NULL;
        return;
    }   

   ListNode *pWalk = *phead;
   while(NULL!=pWalk->pNext)   //在中间，删除了该节点 
   {
     if(m_data==pWalk->pNext->m_data)
     {
       ListNode *pDelete = pWalk->pNext;
       pWalk->pNext = pWalk->pNext->pNext;
       delete  pDelete;
       pDelete = NULL;
       return ;
     }
     else
        pWalk = pWalk->pNext; 
   }    

   if(pWalk->pNext->m_data==m_data)  //data在最后一个节点里面，删除了最后一个节点。
   {
     ListNode *pDelete = pWalk->pNext;
     pWalk->pNext = NULL;
     delete pDelete;
     pDelete = NULL;
     return;
   }

   return;
}

struct ListNode
{
    int m_nkey;
    ListNode* m_pNext;
};



//输入一个链表的头结点，从尾到头反过来打印出每个结点的值
//1.考虑是否可以修改该链表，如果可以的话，把链表先反过来即可。
//2.把数据存入栈中，因为栈先进后出，最后把栈的值打印出来即可。
//3.数据存入到vector中也可以，到时候从.end()到.begin()打印出来即可。
void typeReverseNode(const ListNode* phead)
{
  if(NULL==phead) return;
    
  ListNode* pWalk = phead;
  stack<int> nodes;

  while(pWalk!=NULL)
  {
    nodes.push(pWalk->m_nkey);
    pWalk = pWalk->m_pNext;
  }
  int count = 0;
  while(!nodes.empty())
  {
    cout<<nodes.top()<<" ";
   // printf("%d\t",nodes.top());
   // fprintf(stdout,"%d\t",nodes.top());
    count ++;
    if(0==count%10) cout<<endl;
    node.pop();
  }
}






int main()
{
  
}
