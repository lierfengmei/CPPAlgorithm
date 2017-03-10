



void QuickSort(int data[],int length,int start,int end)
{
 // if(NULL==data || length<=0 || start<0 || end<=0 || end<=start || (end-start)>length)
 //   return;

  if(start==end) return;  //递归结束的条件

  int index = Partion(data,length,start,end);
  if(index>start)
    QuickSort(data,length,start,index-1);
  if(index<end)
    QuickSort(data,length,index+1,end);
}

int Partion(int data[],int length,int start,int end)
{
  //检测输入参数
  if(NULL==data || length<=0 || start<0 || end<start || (end-start)>length) 
    throw new std::exception("Invalid parameters!");

  //随机选取index
    int index = 0;
    srand(time(NULL));
    index = rand()%(end-start+1) +start;

  //进行快速排序
    Swap(&data[index],&data[end]);
    int compareData = data[index]; 
    for(int i=start;i<end;i++)
    {
      for(j=end-1;j>0;j--)
      {
        if(data[j]<)
      }
    }



    return index;
}

//交换a and b .
void Swap(int& a,int& b)
{
  int temp = a;
  a = b;
  b = temp;
}
