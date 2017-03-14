/* 题目：二叉树中和为某一值的路径
 * 问题描述：输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 从树的根结点开始往下一直到叶结点所经历过的节点形成一条路径。
 * */
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


struct BinaryTreeNode
{
  int m_value;
  BinaryTreeNode* pLeftTree;
  BinaryTreeNode* pRightTree;
};


void FindPath(BinaryTreeNode* pRoot,int Sum);
void PrintVec(const vector<BinaryTreeNode*>& vec);
void FindPath(vector<BinaryTreeNode*> vec,BinaryTreeNode* pRoot,int Sum);

void FindPath(BinaryTreeNode* pRoot,int Sum)
{
  if(pRoot==NULL || Sum<=0) return;

  if(Sum==1)  cout<<pRoot->m_value<<endl;

  vector<BinaryTreeNode*> vec;
  vec.clear();

  FindPath(vec,pRoot,Sum);
}

void PrintVec(const vector<BinaryTreeNode*>& vec)
{
  vector<BinaryTreeNode*>::const_iterator iter = vec.begin();
    
  while(iter != vec.end())
  {
    cout<<(*iter)->m_value<<" ";
    iter++;
  }
  cout<<endl;
}

void FindPath(vector<BinaryTreeNode*> vec,BinaryTreeNode* pRoot,int Sum)
{
  if(pRoot==NULL || Sum==0) 
  {
    PrintVec(vec);
    return;
  }

  if(pRoot->m_value==Sum) 
  {
    vec.push_back(pRoot);
    PrintVec(vec);
    return;
  }

  if(pRoot->m_value>Sum) return;

  vec.push_back(pRoot);

  if(pRoot->pLeftTree!=NULL) 
    FindPath(vec,pRoot->pLeftTree,Sum-pRoot->m_value);
  if(pRoot->pRightTree!=NULL)
    FindPath(vec,pRoot->pRightTree,Sum-pRoot->m_value);
}


int main()
{
  BinaryTreeNode node3 = {4,NULL,NULL};
  BinaryTreeNode node4 = {7,NULL,NULL};
  BinaryTreeNode node1 ={5,&node3,&node4};
  BinaryTreeNode node2 = {12,NULL,NULL};
  BinaryTreeNode node0 = {10,&node1,&node2};

  int Sum = 22;
  FindPath(&node0,Sum);
  
  return 0;
}
