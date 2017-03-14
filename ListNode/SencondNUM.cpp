
int find_sec_max(int data[],int count)
{
	int max = 0;
	int second = 0;

	if(count<=1) 
	{
		cout<<"Input count error! count should be >=2."<<endl;
		exit(1);
	}

	max = (data[0]>data[1]?data[0]:data[1]);
	second = (data[0]>data[1]?data[1]:data[0]);

	for(int i=2;i<count;i++)
	{
		if(data[i]>second && data[i]<=max) second = data[i];
		if(data[i]>max) 
		{
			second = max;
			max = data[i];
		}
	}
	return second;
}
