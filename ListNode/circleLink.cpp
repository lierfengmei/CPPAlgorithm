
struct node
{
	char val;
	node *next;
};

bool check(const node* head)
{
	if(head==NULL) return false;

	node *low = head;
	node *fast = head->next;

    while(fast!=NULL && fast->next!=NULL)
	{
		low = low->next;
		fast = fast->next->next;
		if(low==fast)
		  return true;
	}
	return false;
}


#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	long l;
	char *str= "12345";
	l=atol(str);
	printf("string=%s long integer = %ld",str,l);
	return 0;
}
