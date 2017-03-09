#define MIN(A,B) ((A)<=(B)?(A):(B))


Node *Merge(Node* head1,Node* head2)
{
	Node* head = NULL;
	Node *p = NULL;
	Node *p1 = NULL;
	Node *p2 = NULL;
	if(NULL==head1)
	  return head2;
	if(NULL==head2)
	  return head1;

	//获得头节点
	if(head1->data < head2->data)
	{
		head = head1;
		p1 = head1->next;
		p2 = head2;
	}
	else
	{
		head = head2;
		p1 = head1;
		p2 = head2->next;
	}
	p = head;
	
	while(p1!=NULL && p1!=NULL)
	{
		if(p1->data < p2->data)
		{
			p->next = p1;
			p = p1;
			p1 = p1->next;
		}
		else
		{
			p->next = p2;
			p = p2;
			p2 = p2->next;
		}
	}

	if(p1==NULL)
	{
		p->next = p2;
		return head;
	}
	else
	{
		p->next=p1;
		return head;
	}
}

const float EPSION = 0.00001;
if((x>=-EPSION)&&(x<=EPSION))
