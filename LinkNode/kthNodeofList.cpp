/*
 * 输入一个链表，输出该链表中的倒数第k个结点。为了符合大多数人的习惯，本题
 * 从1开始计数，即链表的尾结点是倒数第1个结点。
 * 如果一个链表有6个结点，从头开始它们的值依次为1,2,3,4,5,6。则这个链表倒数
 * 第3个结点是值为4的结点。
 * */

#include <iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};



//使用两个指针，这样可以只遍历1次。

ListNode* ReverseKNodeofList(ListNode* phead,int k)
{
	if(phead==NULL || k<=0 ) return NULL;
	
	ListNode* pAhead = phead;
	ListNode* pBehind = phead;   //pBehind后走k-1步。

	int walkSteps = 0;

	while(pAhead->m_pNext!=NULL && walkSteps<(k-1))
	{
		pAhead = pAhead->m_pNext;
		walkSteps ++;
	}

	if(pAhead->m_pNext==NULL && walkSteps<(k-1)) //pAhead已经走到尾结点
	{
		cout<<"Invalid input parameter k"<<endl;
		return NULL;
	}

	//Now let both pAhead and pBehind walks
	while(pAhead->m_pNext!=NULL)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}





//要遍历两遍，效率比较差。
ListNode* ReverseKNodeofList_myAns(ListNode* phead,int k)
{
	if(phead==NULL || k<=0) return NULL;

	int count = 0;

	//总共有count个结点。
	ListNode* pWalk = phead;
	while(pWalk!=NULL) 
	{
		count ++;
		pWalk = pWalk->m_pNext;
	}
	//倒数第k个结点= 顺数count+1-k个。
	//有可能k超过了链表的长度，则返回NULL
    if(k>count) return NULL;
	
	int kWalk = count+1-k;
	pWalk = phead;

	for(int i=1;i<kWalk;i++)
	{
		pWalk = pWalk->m_pNext;	
	}

	return pWalk;
}



int main()  
{  
    ListNode *pNode0 = new ListNode; pNode0->m_nValue= 0;  
    ListNode *pNode1 = new ListNode; pNode1->m_nValue = 1;  
    ListNode *pNode2 = new ListNode; pNode2->m_nValue = 2;  
    ListNode *pNode3 = new ListNode; pNode3->m_nValue = 3;  
    ListNode *pNode4 = new ListNode; pNode4->m_nValue = 4;  
    pNode0->m_pNext = pNode1;  
    pNode1->m_pNext = pNode2;  
    pNode2->m_pNext = pNode3;  
    pNode3->m_pNext = pNode4;  
    pNode4->m_pNext = NULL;  

	int n;

     n = 1;
	ListNode *pReverseKNode = ReverseKNodeofList(pNode0,n);
	cout<<"k is: "<<n<<" , value is: "<<pReverseKNode->m_nValue<<endl; 

  n = 2;
pReverseKNode = ReverseKNodeofList(pNode0,n);
cout<<"k is: "<<n<<" , value is: "<<pReverseKNode->m_nValue<<endl; 

 n = 3;
pReverseKNode = ReverseKNodeofList(pNode0,n);
	cout<<"k is: "<<n<<" , value is: "<<pReverseKNode->m_nValue<<endl; 

 n = 4;
pReverseKNode = ReverseKNodeofList(pNode0,n);
cout<<"k is: "<<n<<" , value is: "<<pReverseKNode->m_nValue<<endl; 

 n = 5;
pReverseKNode = ReverseKNodeofList(pNode0,n);
cout<<"k is: "<<n<<" , value is: "<<pReverseKNode->m_nValue<<endl; 


 n = 6;
pReverseKNode = ReverseKNodeofList(pNode0,n);

if(pReverseKNode!=NULL)
cout<<"k is: "<<n<<" , value is: "<<pReverseKNode->m_nValue<<endl; 
else
  cout<<"return NULL"<<endl;

 n =0; 
pReverseKNode = ReverseKNodeofList(pNode0,n);

if(pReverseKNode!=NULL)
cout<<"k is: "<<n<<" , value is: "<<pReverseKNode->m_nValue<<endl; 
else
  cout<<"return NULL"<<endl;


return 0;

}
