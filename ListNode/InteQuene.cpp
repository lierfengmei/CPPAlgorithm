#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void Order(vector<int>& data) //冒泡排序
{
	int count = data.size();
	int tag = false;         //设置是否需要继续冒泡的标志位
	for(int i=0;i<count;i++)
	{
		for(int j=0;i<count-i-1;j++)
		{
			if(data[j]>data[j+1])
			{
				tag = true;
				int temp = data[j+1];
				data[j+1] = data[j];
				data[j] = temp;
			}
		}
		if(!tag) break;
	}
}

void main()
{
	vector<int> data;

	//read data 
	ifstream in("c:\\read_data.txt");
	if(!in)
	{
		cout<<"read file error!"<<endl;
		exit(1);
	}
	int temp;
	while(!in.eof())
	{
		in>>temp;
		data.push_back(temp);
	}
	in.close();

	//order data
	Order(data);

	//write data
	oftream out("c:\\write_data.txt");
	if(!out)
	{
		cout<<"write file error!"<<endl;
		exit(1);
	}
	for(i=0;i<data.size();i++)
	  out<<data[i]<<" ";
	out.close();
}
