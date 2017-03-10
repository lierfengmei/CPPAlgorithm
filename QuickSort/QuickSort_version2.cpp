#include <stdio.h>
#include <iostream>

using namespace std;

void Swap(int& a,int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

int Partion(int data[],int length, int left,int right)
{
  int key = data[left];
  int j = right;
  int i = left;

  while(i!=j)
  {
    while(data[j]>=key && j>i) j--;
    while(data[i]<=key && i<j) i++;
    if(j!=i) Swap(data[i],data[j]);
  }
  if(i!=left)Swap(data[i],data[left]);
  return i;
}


void QuickSort(int data[],int length,int left,int right)
{
  if(NULL==data || length<=0 || left<0 || right<left || (right-left)>length)
  {
    cout<<"Invalid Input Parameters!"<<endl;
    return;
  }
  
  if(right==left) return;

  int index = Partion(data,length,left,right);
  
  if(index>left)
    QuickSort(data,length,left,index-1);
  if(index<right)
    QuickSort(data,length,index+1,right);
}

int main()
{
  int data[] = {5,8,1,2,6,4,3,9,0,7,7,2,2};
  int length = 0;
  int left = 0;
  int right = 12;


  cout<<"Before quick sort,the data is:"<<endl;
  for(int i=0;i<length;i++)
    cout<<data[i]<<" ";
  cout<<endl;

  QuickSort(data,length,left,right);

  cout<<"After quick sort,the data is:"<<endl;
  for(int i=0;i<length;i++)
    cout<<data[i]<<" ";
  cout<<endl;
}




