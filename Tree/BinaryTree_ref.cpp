#include <iostream>
//#include <stdexcept>
#include <exception>
#include <stdexcept>
using namespace std;



struct BinaryTreeNode
{
  int m_nValue;
  BinaryTreeNode* m_pLeft;
  BinaryTreeNode* m_pRight;
};


BinaryTreeNode* ConstructCore(
    int* startPreorder, int* endPreorder,
    int* startInorder,  int* endInorder );

BinaryTreeNode* Construct(int* preorder,int* inorder,int length)
{
  if(preorder==NULL|| inorder==NULL || length<=0)
    return NULL;

  return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}


BinaryTreeNode* ConstructCore(
    int* startPreorder, int* endPreorder,
    int* startInorder,  int* endInorder )
{
  //前序遍历的第一个字是根结点的值
  BinaryTreeNode* root = new BinaryTreeNode;
  root->m_nValue = *startPreorder;
  root->m_pLeft = NULL;
  root->m_pRight = NULL;

  if(startPreorder==endPreorder) 
  {
    if(startInorder==endInorder && *startPreorder==*startInorder) return root;
    else
      throw std::exception("Invalid input.");
  } 

  //在中序遍历中找到根结点的值
  int *rootInorder = startInorder;
  while(*rootInorder!=*startPreorder && rootInorder<=endInorder)
  {
    rootInorder++;
  }
  if(rootInorder>endInorder) throw std::exception("Invalid input.");
  int leftLength = rootInorder-startInorder;

  int* leftPreorderEnd = startPreorder+leftLength+1;

  //构建左子树
   if(leftLength>0)
     root->m_pLeft = ConstructCore(startPreorder+1,startPreorder+leftLength,startInorder,rootInorder-1);
  //构建右子树 
   if(leftLength<endPreorder-startPreorder)
     root->m_pRight=ConstructCore(startPreorder+leftLength+1,endPreorder,rootInorder+1,endInorder);

   return root;
}
