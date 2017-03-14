/* 题目：二叉搜索树与双向链表
 * 问题描述：输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的节点，只能调整树中节点指针的指向。
 * */

#include <iostream>
#include <assert.h>
using namespace std;

#define LEFT true
#define RIGHT false

struct BinaryTreeNode
{
  int m_value;
  BinaryTreeNode* pLeft;
  BinaryTreeNode* pRight;
};

BinaryTreeNode* BinaryTreeToDeque(BinaryTreeNode* pRoot);
void PrintDeque(BinaryTreeNode* pRoot);
BinaryTreeNode* SubBinaryTreeToDeque(BinaryTreeNode* pRoot,bool Direction);

BinaryTreeNode* BinaryTreeToDeque(BinaryTreeNode* pRoot)
{
  if(pRoot==NULL)  return NULL;

  BinaryTreeNode* pHead = NULL;
  BinaryTreeNode* pTail = NULL;

  if(pRoot->pLeft!=NULL) pTail = SubBinaryTreeToDeque(pRoot->pLeft,LEFT);
  if(pRoot->pRight!=NULL) pHead = SubBinaryTreeToDeque(pRoot->pRight,RIGHT);

  //把pRoot插入到pTail和pHead中间
  pTail->pRight = pRoot;
  pRoot->pLeft = pTail;
  pRoot->pRight = pHead;
  pHead->pLeft = pRoot;
 
  //把最后形成的链表的头尾双向链接起来。
  //find pHead
  pHead = pRoot;
  while(pHead->pLeft!=NULL) pHead = pHead->pLeft;
 
  pTail = pRoot;
  while(pTail->pRight!=NULL) pTail = pTail->pRight;

  pHead->pLeft = pTail;
  pTail->pRight = pHead;  

  return pHead;
}

void PrintDeque(BinaryTreeNode* pRoot)
{
  if(pRoot==NULL) return;

  BinaryTreeNode* pWalk = pRoot;
  cout<<pRoot->m_value<<"->";
  while(pWalk->pRight!=pRoot)
  {
    pWalk = pWalk->pRight;
    cout<<pWalk->m_value<<"->";
  }
}

BinaryTreeNode* SubBinaryTreeToDeque(BinaryTreeNode* pRoot,bool Direction)
{
  assert(pRoot!=NULL);
 // if(pRoot==NULL)  return NULL;

  BinaryTreeNode* pHead = NULL;
  BinaryTreeNode* pTail = NULL;

  if(pRoot->pLeft!=NULL) 
  {
    pTail = SubBinaryTreeToDeque(pRoot->pLeft,LEFT);
    pTail->pRight = pRoot;
    pRoot->pLeft = pTail; 
  }
  else pTail=pRoot;

  if(pRoot->pRight!=NULL) 
  {
    pHead = SubBinaryTreeToDeque(pRoot->pRight,RIGHT);
    pRoot->pRight = pHead;
    pHead->pLeft = pRoot;
  }
  else pHead = pRoot;

//重新更新pTail和pHead
  while(pTail->pRight!=NULL) pTail = pTail->pRight;
  while(pHead->pLeft!=NULL) pHead = pHead->pLeft;

  if(Direction==LEFT) return pTail;
 else return pHead; 
}



int main()
{
  BinaryTreeNode node3 = {4,NULL,NULL};
  BinaryTreeNode node4 = {8,NULL,NULL};
  BinaryTreeNode node5 = {12,NULL,NULL};
  BinaryTreeNode node6 = {16,NULL,NULL};

  BinaryTreeNode node1 = {6,&node3,&node4};
  BinaryTreeNode node2 = {14,&node5,&node6};

  BinaryTreeNode node0 = {10,&node1,&node2};

  BinaryTreeNode* phead = BinaryTreeToDeque(&node0);

  PrintDeque(phead);

  return 0;
}
