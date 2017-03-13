/*
 * 问题描述：输入一个整数数组，判断该数组是不是某个二叉搜索树的后序遍历结果。
 * 是则返回true,否则返回false。假设输入的数组任意两个数字都不相同。*/


#include <iostream>
using namespace std;


struct BinaryTreeNode
{
	int m_value;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

bool IsLRDofTree(const int* arr,const unsigned int length)
{
//	if(NULL==arr || length==0) return false; 

	if(NULL==arr) return false;
	if(length<=1) return true;  

	//返回根结点
	int rootValue = arr[length-1];

	//拆分左右子树
	
	int leftMax = -1;
	int rightMax = -1;
	int i = 0;
	while(arr[i]<rootValue && i<=(length-2)) 
	{
		i++;
		leftMax++;
	}
	
	rightMax = leftMax + 1;
	while(arr[i]>rootValue && i<=(length-2))
	{
		i++;
		rightMax++;
	}

	if(leftMax==-1 && rightMax==(length-2)) return IsLRDofTree(arr,length-1);
	if(leftMax==(length-2) && rightMax==(length-1)) return IsLRDofTree(arr,length-1);
//	if(rightMax==(length-1) || leftMax==-1) 
	if(rightMax!=(length-2)) return false;
    return IsLRDofTree(arr,leftMax)&&IsLRDofTree(arr+leftMax+1,length-1-leftMax);

/*

	if(arr[0]>rootValue || arr[length-2]<rootValue) return IsLRDofTree(arr,length-1);//左子树或者右子树为NULL

	int i;
	int index = -1;
	for(i=0;i<length-2;i++)
	{
		
		if(arr[i]<rootValue && arr[i+1]>rootValue)
		{
			index = i;
			break;
		}
	}
	if(index != -1)
	for(i=index+1;i<length-2;i++)
	{
		if(arr[i]<rootValue) return false;
	}

	//判断左子树
	int lengthLeft = index+1;
	int lengthRight = length-index-2;

	return IsLRDofTree(arr,index+1)&&IsLRDofTree(arr+index+1,length-index-2);
*/
}


int main()
{
	/*BinaryTreeNode node6 = {11,NULL,NULL};
	BinaryTreeNode node5 = {9,NULL,NULL};
	BinaryTreeNode node4 = {7,NULL,NULL};
	BinaryTreeNode node3 = {5,NULL,NULL};

	BinaryTreeNode node2 = {10,&node5,&node6};
	BinaryTreeNode node1 = {6,&node3,&node4};

	BinaryTreeNode node0 ={8,&node1,&node2};
	*/

	int arr1[] ={5,7,6,9,11,10,8};
	cout<<"arr1 result: "<<IsLRDofTree(arr1,7)<<endl;
	int arr2[] ={12,7,5,9,8,11,10};
	cout<<"arr2 result: "<<IsLRDofTree(arr2,7)<<endl;

	return 0;

}

