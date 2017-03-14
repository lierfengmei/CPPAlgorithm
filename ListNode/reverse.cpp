


Node * ReverseList(Node* head)
{
	if(head==NULL || head->next==NULL)//0 node or 1 node
	  return head;

	Node *p1 = head;
	Node *p2 = p1->next;
	if(p2->next=NULL)//2 nodes
	{
		p2->next = p1;
		p1->next = NULL;
		head = p2;
		return p2;
	}                 
	//>=3 nodes
	Node *p3 = p2->next;
	p1->next = NULL;
	
	while(p3->next!=NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}
	p2->next = p1;
	p3->next = p2;
	head = p3;
	return head;

}
