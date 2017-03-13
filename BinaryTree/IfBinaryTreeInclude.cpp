//问题描述： 输入两棵二叉树A和B，判断B是不是A的子树。

#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


bool IfBinaryTreeSame(BinaryTreeNode* pRootA,BinaryTreeNode* pRootB);
bool IfBinaryTreeInclude(BinaryTreeNode* pRootA,BinaryTreeNode* pRootB);
bool IfBinaryTreeInclude(BinaryTreeNode* pRootA,BinaryTreeNode* pRootB)
{
	if(pRootA==NULL || pRootB==NULL) return false;

	if(IfBinaryTreeSame(pRootA,pRootB)) return true;
	else
	{
		if(IfBinaryTreeInclude(pRootA->m_pLeft,pRootB)) return true;
		if(IfBinaryTreeInclude(pRootA->m_pRight,pRootB)) return true;
		return false;
	}
	
	return false;
}

bool IfBinaryTreeSame(BinaryTreeNode* pRootA,BinaryTreeNode* pRootB)
{
	if(pRootB->m_pLeft==NULL && pRootB->m_pRight==NULL && pRootB->m_nValue==pRootA->m_nValue) 
	  return true;
	
	if(pRootB->m_pLeft==NULL && pRootB->m_pRight!=NULL && pRootB->m_nValue==pRootA->m_nValue)
	  return IfBinaryTreeSame(pRootA->m_pRight,pRootB->m_pRight);

	if(pRootB->m_pLeft!=NULL && pRootB->m_pRight==NULL && pRootB->m_nValue==pRootA->m_nValue)
	  return IfBinaryTreeSame(pRootA->m_pLeft,pRootB->m_pLeft);

	if(pRootB->m_pLeft!=NULL && pRootB->m_pRight!=NULL && pRootB->m_nValue==pRootA->m_nValue)
	{
		bool b1 = IfBinaryTreeSame(pRootA->m_pRight,pRootB->m_pRight);
		bool b2 = IfBinaryTreeSame(pRootA->m_pLeft,pRootB->m_pLeft);
		return (b1&&b2);
	}

	return false;
}

int main()
{
	BinaryTreeNode* pRootA = NULL;
	BinaryTreeNode* pRootB = NULL;

	bool result = IfBinaryTreeInclude(pRootA,pRootB);
	cout<<result<<endl;

	return 0;

}
