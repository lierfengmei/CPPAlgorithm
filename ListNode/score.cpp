#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string name;
	string score;
	Student *next;
};
void showLinkData(Student *head);
void DestroyLinkData(Student *head);
Student *CreateData(Student *head);
Student *InsertData(Student *head,int k);
Student * modifyLinkData(Student *head,const unsigned int k);

int main()
{
	Student *head =NULL;
	
	head = CreateData(head);
	
	showLinkData(head);
//	InsertData(head,2);
//	showLinkData(head);
	modifyLinkData(head,2);
	showLinkData(head);
	DestroyLinkData(head);
}
Student *CreateData(Student *head)
{
	int i=1;
	int n;
	cout<<"Please input the student amount:";
	cin>>n;
	string name;
	string score;

	Student *p = NULL;
    //建立链表
	for(;i<=n;i++)
	{
		Student *node = new Student;
		cout<<"请输入第 "<<i<<" 个同学的姓名:";
		cin>>node->name;
		cout<<"请输入第 "<<i<<" 个同学的成绩:";
		cin>>node->score;
		node->next = NULL;

		if(head==NULL)
		{
			head = node;
			p = node;
		}
		else
		{
			p->next = node;
			p = node;
		}
		if(i==n)
		  p->next = NULL;
	}
	return head;
}


Student *InsertData(Student *head,int k)
{
	Student *node = new Student;
	cout<<"请输入第"<<k<<"位同学的姓名:";
	cin>>node->name;
	cout<<"请输入第"<<k<<"位同学的成绩:";
	cin>>node->score;

	Student *p;
	p = head;

	int i=1;
	while(i<k-1)
	{
		p = p->next;
		i++;
	}
	Student *temp = p->next;
	p->next = node;
	node->next = temp;
	return node;
}




void showLinkData( Student *head)
{
	//输出链表
	cout<<"链表已经建立"<<endl;
	cout<<"==============链表数据如下所示================"<<endl;

	Student *p = head;
	while(p!=NULL)
	{
		cout<<"name: "<<p->name<<" score: "<<p->score<<endl;
		p = p->next;
	}
}

void DestroyLinkData(Student *head)
{
	Student *p = head;
	Student *temp;
	while(p!=NULL)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
}

Student * modifyLinkData(Student *head,const unsigned int k)
{
	Student *p=NULL;
	p = head;

	for(int i=1;i<k;i++)
	{
		p = p->next;
	}
	cout<<"Student name: "<<p->name<<endl;
	cout<<"Student score: "<<p->score<<endl;
	cout<<"Modifying........"<<endl;

	Student *node = new Student;
	cout<<"Please input the Student name:";
	cin>>node->name;
	cout<<"Please input the Student score:";
	cin>>node->score;

	node->next = p->next;
	p->next = node;

	cout<<"Modifying DONE!"<<endl;
	return node;

}

Student *DeleteLinkData(Student *head,const unsigned int k)
{
	Student *p = NULL;
	p = head;

	if(k==1)
	{
		head = head->next;
		delete p;
		p = NULL;
		return head;
	}

	for(int i=1;i<k-1;i++)
	{
		 p = p->next;
	}
	Student *temp = p->next;
	if(temp->next!=NULL)
	{
	p->next = temp->next;
	delete temp;
	temp = NULL;
	}
	else
	{
		p->next = NULL;
		delete temp;
		temp = NULL;
	}
	return head;
}
