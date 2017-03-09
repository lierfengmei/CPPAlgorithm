

void LoopMove(char *pStr,int steps)
{
	int n = strlen(pStr)-steps;
	char temp[MAX_LEN];
	
	strcpy(tmp,pStr+n);
	strcpy(tmp+steps,pStr);
	*(tmp+strlen(pStr)) = '\0';
	strcpy(pStr,temp);


	int n = strlen(pStr)-steps;
	char temp[MAX_LEN];
	strcpy(temp,pStr+n);
	strcpy(temp+steps,pStr);
	*(temp+strlen(pStr))='\0';
	strcpy(pStr,temp);
}
