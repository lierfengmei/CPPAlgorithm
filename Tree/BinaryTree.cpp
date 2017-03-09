#include <iostream>
#include <stdio.h>
using namespace std;

//重建二叉树
//题目：输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的
//前序遍历和中序遍历的结果都不含重复的数字。
//例如，前序遍历结果{1,2,4,7,3,5,6,8}
//中序遍历结果{4,7,2,1,5,3,8,6}
//请重建二叉树并输出它的头结点。
//二叉树的定义如下：

struct BinaryTreeNode
{
  int   m_nValue;
  BinaryTreeNode* m_pLeft;
  BinaryTreeNode* m_pRight;
};


//需要注意的点：1 arr1==NULL arr2==NULL    2 length>=0 
//arr1中的值和arr2中的值不一样
//迭代算法
BinaryTreeNode* RebuildBinaryTree(const int arr1[],const int arr2[],const int length)
{
  if(length<0) 
  {
    fprintf(stderr,"length should >=0.");
    return NULL;
  }
  if(length==0) return NULL;
  if(arr1==NULL || arr2==NULL)
  {
    fprintf(stderr,"arr1 and arr2 should not be NULL.");
    return NULL;
  }
  
  BinaryTreeNode* root = new BinaryTreeNode;
  root->m_nValue = arr1[0];
  if(length==1) 
  {
    root->m_pLeft=NULL;
    root->m_pRight=NULL;
    return root;
  }
  else if(length==2)
  {
    if(arr1[0]==arr2[0]) 
    {
      root->m_pLeft = NULL;
      BinaryTreeNode* pLeaf = new BinaryTreeNode;
      pLeaf->m_nValue = arr1[1];
      pLeaf->m_pLeft = NULL;
      pLeaf->m_pRight = NULL;
      root->m_pRight = pLeaf;
    }
    else
    {
      root->m_pRight = NULL;
      BinaryTreeNode* pLeaf = new BinaryTreeNode;
      pLeaf->m_nValue = arr1[1];
      pLeaf->m_pLeft = NULL;
      pLeaf->m_pRight = NULL;
      root->m_pLeft = pLeaf;
    }
  }
  //把arr2 分成左子树和右子树
  int length_right = 0;
  root->m_pLeft = RebuildBinaryTree(arr1+1,arr2,length_left);//左子树
  root->m_pRight = RebuildBinaryTree(arr1+length_left+1,arr2+length_left,length_right);//右子树
  
  return root;
}


int main()
{
  int arr1[]={1,2,4,7,3,5,6,8};
  int arr2[]={4,7,2,1,5,3,8,6};
  int length = 8;

  BinaryTreeNode *node = NULL;
  node = RebuildBinaryTree(arr1,arr2,length);
  return 0;
}
