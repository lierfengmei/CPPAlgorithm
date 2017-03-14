/* * 给定单向链表的头指针和一个结点指针，定义一个函数在O(1)
 * 时间删除该结点。
 */

#include <iostream>

#include <stdio.h>
using namespace std;


struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};


//因为如果删除的是头结点，那么就会改变pHead，应该用二级指针！
void DeleteNode(ListNode** ppHead,ListNode* pToBeDeleted)
{
	if(ppHead==NULL || *ppHead==NULL || pToBeDeleted==NULL) return;

	//如果删除的是头结点
	if(pToBeDeleted==*ppHead)
	{
		*ppHead = (*ppHead)->m_pNext;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		return;
	}	

	//如果删除的是尾结点
	if(pToBeDeleted->m_pNext==NULL)
	{
		ListNode* pWalk = *ppHead;
		while(pWalk->m_pNext!=pToBeDeleted) pWalk = pWalk->m_pNext;
		pWalk->m_pNext = NULL;

		delete pToBeDeleted;
		pToBeDeleted = NULL;
		return;
	}
	
	//如果删除的既不是头结点，也不是尾结点
	ListNode *ptemp = pToBeDeleted->m_pNext;
	pToBeDeleted->m_nValue = ptemp->m_nValue;
	pToBeDeleted->m_pNext = ptemp->m_pNext;

	delete ptemp; 
	ptemp = NULL;

	return;
}

void PrintNodeList(const ListNode *phead)
{
	if(phead == NULL)
	{
		cout<<"NULL"<<endl;
		return;
	}	 
	while(phead->m_pNext!=NULL)
	{
		cout<<phead->m_nValue<<"->";
		phead = phead->m_pNext;
	}
	cout<<phead->m_nValue<<"->NULL"<<endl;}

int main()
{

ListNode *pNode1 = new ListNode;
ListNode *pNode2 = new ListNode;
ListNode *pNode3 = new ListNode;
ListNode *pNode4 = new ListNode;

pNode1->m_nValue = 1;
pNode2->m_nValue = 2;
pNode3->m_nValue = 3;
pNode4->m_nValue = 4;

pNode1->m_pNext = pNode2;
pNode2->m_pNext = pNode3;
pNode3->m_pNext = pNode4;
pNode4->m_pNext = NULL;


PrintNodeList(pNode1);

DeleteNode(&pNode1,pNode4);

PrintNodeList(pNode1);


   return 0;

}
