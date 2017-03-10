#include <iostream>
#include <stdlib.h>

using namespace std;

int MinRotateNUm(int data[],int length)
{
  if(NULL==data || length<=0 ) 
  {
    cout<<"Input data error!"<<endl;
    exit(1);
  }
  if(length==1) return data[0];
  if(length==2) return data[0]<data[1]?data[0]:data[1];

  int index = length/2;

  if(data[index]>data[length-1]) return MinRotateNUm(data+index+1,length-index-1);
  else return MinRotateNUm(data,index+1);
}

int main()
{
 int data[] = {3,4,5,1,1,2,2,3};
  int result = MinRotateNUm(data,8); 
  cout<<"The min data is: "<<result<<endl;
}
