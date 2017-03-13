
#include <iostream>
using namespace std;

void PrintLine(int* arr,int row_begin,int row_end,int jumpStep);
void PrintRectArray(int* arr,int cols,int m,int n);
void PrintOutline(int* arr,int cols,int m,int n);

void PrintLine(int* arr,int row_begin,int row_end,int jumpStep)
{
	for(int i=row_begin;i<=row_end;i++)
	  cout<<arr[i*jumpStep]<<" ";
//	cout<<endl;
}

void PrintRectArray(int* arr,int cols,int m,int n)
{
	if(arr==NULL || m<=0 || n<=0) return;

	if(m==1) 
	{
		PrintLine(arr,0,n-1,1);
		return;
	}

	if(n==1)
	{
		PrintLine(arr,0,m-1,cols);
		return;
	}

	PrintOutline(arr,cols,m,n);
	PrintRectArray(arr+cols+1,cols,m-2,n-2);
}

void PrintOutline(int* arr,int cols,int m,int n)
{
	PrintLine(arr,0,n-2,1);//上
	PrintLine(arr+n-1,0,m-2,cols);//右
	PrintLine(arr+n-1+(m-1)*cols,0,n-2,-1);//下
	PrintLine(arr+(m-1)*cols,0,m-2,-cols);//左
}

int main()
{
	int matrix[][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
	PrintRectArray(&matrix[0][0],3,4,3);
	cout<<endl;

	int matrix2[][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	PrintRectArray(&matrix2[0][0],4,4,4);
	cout<<endl;

	int matrix3[][1] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	PrintRectArray(&matrix3[0][0],1,16,1);
	cout<<endl;

	int matrix4[][16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	PrintRectArray(&matrix4[0][0],16,1,16);
	cout<<endl;


	return 0;
}




