/* 题目：从上到下打印二叉树
 * 问题描述：从上到下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
 * */

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct BinaryTreeNode
{
  int m_value;
  BinaryTreeNode* pLeft;
  BinaryTreeNode* pRight;
};

bool PrintBinaryTreeLevel(vector<BinaryTreeNode*> (*pInputVec));
//void PrintVec(vector<BinaryTreeNode*> InputVec);

void PrintBinaryTree(BinaryTreeNode* proot)
{
  if(proot == NULL) return;

  vector<BinaryTreeNode*> (*pInputVec) = new vector<BinaryTreeNode*>;
  (*pInputVec).clear();
  (*pInputVec).push_back(proot);

  //循环打印
  while(PrintBinaryTreeLevel(pInputVec));

  delete pInputVec;
  pInputVec = NULL;
}
/*
void PrintVec(vector<BinaryTreeNode*> InputVec)
{
  vector<BinaryTreeNode*>::iterator it = InputVec.begin();
  while(it!=InputVec.end())
  {
    cout<<((*it)->m_value)<<" ";
    it++;
  }
  cout<<endl;
}
*/
//输入一个BinaryTreeNode* proot的数组，打印出左右节点，然后再返回下一个数组。
bool PrintBinaryTreeLevel(vector<BinaryTreeNode*> (*pInputVec))
{
   int size = (*pInputVec).size();
   int i=0;
    while(i<size)
    {
      BinaryTreeNode* pPrint = (*pInputVec)[i];
      cout<<pPrint->m_value<<" ";
      if(pPrint->pLeft!=NULL) (*pInputVec).push_back(pPrint->pLeft);
      if(pPrint->pRight!=NULL) (*pInputVec).push_back(pPrint->pRight);
      i++;
    }

    (*pInputVec).erase((*pInputVec).begin(),(*pInputVec).begin()+size);

    if((*pInputVec).size()==0) return false;
    else return true;
} 

int main()
{
  // Create BinaryTree
 struct BinaryTreeNode node6 = {m_value:11,pLeft:NULL,pRight:NULL};
 struct BinaryTreeNode node5 = {9,NULL,NULL};
 struct BinaryTreeNode node4 = {7,NULL,NULL};
 struct BinaryTreeNode node3 = {5,NULL,NULL};

 struct BinaryTreeNode node2 = {10,&node5,&node6};
 struct BinaryTreeNode node1 = {6,&node3,&node4};

 struct BinaryTreeNode node0 = {8,&node1,&node2};

 PrintBinaryTree(&node0);

 return 0;

}

