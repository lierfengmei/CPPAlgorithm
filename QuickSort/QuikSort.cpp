

int Partition(int data[],int length,int start,int end)
{
	if(data==NULL||length<=0||start<0||end<start||end>=length) 
	  throw new std::exception("Invalid Parameter!");




}

int randomInRange(int start,int end)
{
	srand(time(NULL));
	return start+rand()%(end-start+1);
}

void QuickSort(int data[],int length,int start,int end)
{
	if(start==end) return;

	int index = Partition(data,length,start,end);
	if(index>start)
	  QuickSort(data,length,start,index-1);
	if(index<end)
	  QuickSort(data,length,index+1,end);
}
