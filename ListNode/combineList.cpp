//合并两个增序列表,合并后的新链表仍然是增序排列。

#include <iostream>
using namespace std;


struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


ListNode* CombineList(ListNode* phead1,ListNode* phead2)
{
	if(phead1==NULL) return phead2;
	if(phead2==NULL) return phead1;

    //两个链表都不为空
	ListNode* pWalk1 = phead1;
	ListNode* pWalk2 = phead2;

	//头结点
	ListNode* phead = NULL;
	if(pWalk1->m_nValue<=pWalk2->m_nValue) 
	{
		phead = pWalk1;
		pWalk1 = pWalk1->m_pNext;
	}		
	else
	{
		phead = pWalk2;
		pWalk2 = pWalk2->m_pNext;
	}
	ListNode* pWalk = phead;

	while(pWalk1!=NULL && pWalk2!=NULL)
	{
		if(pWalk1->m_nValue<=pWalk2->m_nValue)
		{
			pWalk->m_pNext = pWalk1;
			pWalk1 = pWalk1->m_pNext;
			pWalk = pWalk->m_pNext;
		}
		else
		{
			pWalk->m_pNext = pWalk2;
			pWalk2 = pWalk2->m_pNext;
			pWalk = pWalk->m_pNext;
		}
	}

	if(pWalk1==NULL)
	  pWalk->m_pNext = pWalk2;
	else
	  pWalk->m_pNext = pWalk1;

	return phead;
}

void PrintList(ListNode* phead)
{
	if(phead==NULL) 
	{
		cout<<"The list is NULL."<<endl;
		return;
	}

	while(phead->m_pNext!=NULL)
	{
		cout<<phead->m_nValue<<" -> ";
		phead = phead->m_pNext;
	} 
	
	cout<<phead->m_nValue<<" -> NULL "<<endl;
}


int main()
{
	ListNode Anode5 = {5,NULL};
	ListNode Anode4 = {4,&Anode5};
	ListNode Anode3 = {3,&Anode4};
	ListNode Anode2 = {2,&Anode3};
	ListNode Anode1 = {1,&Anode2};

	ListNode nodeB5 = {5, NULL};    
	ListNode nodeB4 = {4, &nodeB5};    
    ListNode nodeB3 = {3, &nodeB4};    
	ListNode nodeB2 = {2, &nodeB3};    
	ListNode nodeB1 = {2, &nodeB2}; 

	ListNode *p = NULL;
	PrintList(&Anode1);
	PrintList(&nodeB1);
	p = CombineList(&Anode1,&nodeB1);
	PrintList(p);
	return 0;
}



