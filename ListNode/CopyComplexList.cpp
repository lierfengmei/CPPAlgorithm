/* 题目：复杂链表的复制
 * 问题描述：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)
 * 复制一个复杂链表。在复杂链表中，每个节点除了有一个m_pNext指针指向下一个节点外，
 * 还有一个m_pString指向链表中的任意节点或者NULL。
 * */

#include<iostream>
using namespace std;

struct ComplexListNode
{
  int m_value;
  ComplexListNode* m_pNext;
  ComplexListNode* m_pString;
};

void CloneNext(ComplexListNode* pHead);
void CloneComplex(ComplexListNode* pHead);
ComplexListNode* RebuildClone(ComplexListNode* pHead);
ComplexListNode* Clone(ComplexListNode* pHead);


ComplexListNode* Clone(ComplexListNode* pHead)
{
  if(pHead==NULL) return NULL;

  CloneNext(pHead);
  CloneComplex(pHead);
  
  return RebuildClone(pHead);
}

//将链表A->B->C->D  修改成 A->A1->B->B1->C->C1->D->D1的形式。
void CloneNext(ComplexListNode* pHead)
{
  if(pHead==NULL) return;

  ComplexListNode* pWalk = pHead;
 
  while(pWalk!=NULL)
  {
    ComplexListNode* pNode = new ComplexListNode;
    pNode->m_value = pWalk->m_value;
    pNode->m_pNext = pWalk->m_pNext;
    pNode->m_pString = NULL;
    
    pWalk->m_pNext = pNode;
    pWalk = pNode->m_pNext;
  }
}

void CloneComplex(ComplexListNode* pHead)
{
  if(pHead==NULL)  return;

  //对于每一个A,确定A1的m_pString
  ComplexListNode* pWalk = pHead;

  while(pWalk!=NULL)
  {
    pWalk->m_pNext->m_pString = pWalk->m_pString->m_pNext;
    pWalk = pWalk->m_pNext->m_pNext;
  }
}

//rebuid original List and clone List.
ComplexListNode* RebuildClone(ComplexListNode* pHead)
{
  if(pHead==NULL)  return NULL;

  ComplexListNode* pCloneHead = pHead->m_pNext;

  ComplexListNode* pWalk = pHead;
  ComplexListNode* pCloneWalk = pCloneHead;
  while(pWalk!=NULL)
  {
    pWalk->m_pNext = pWalk->m_pNext->m_pNext;
    pWalk = pWalk->m_pNext;
    if(pCloneWalk->m_pNext!=NULL) 
    {
        pCloneWalk->m_pNext = pCloneWalk->m_pNext->m_pNext;
        pCloneWalk = pCloneWalk->m_pNext;
    } 
  }
    
  return pCloneHead;
}




















