
#include<stdio.h>
#include<deque> //队列

using namespace std;

struct BinaryTreeNode
{
  int m_value;
  BinaryTreeNode* pLeft;
  BinaryTreeNode* pRight;
};


void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
  if(NULL==pTreeRoot) return;
 
  std::deque<BinaryTreeNode*> dequeTreeNode;
  dequeTreeNode.push_back(pTreeRoot);

  while(dequeTreeNode.size()!=0)
  {
    BinaryTreeNode* pFirst = dequeTreeNode.front();

    print("%d",pFirst->m_value);

    if(pFirst->pLeft!=NULL)  dequeTreeNode.push_back(pFirst->pLeft);
    if(pFirst->pRight!=NULL) dequeTreeNode.push_back(pFirst->pRight);

    dequeTreeNode.pop_front();  //删除头一个元素
  }

    

}
