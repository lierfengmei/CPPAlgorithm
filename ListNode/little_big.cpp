
union w
{
	int a;
	char b;
}c;

int checkCPU()
{
	c.a = 1;
	if(c.b==1) return little_endian;
	else return big_endian;
}


char * strcpy(char *strDest,const char * strSRC)
{
	if(strDest==NULL || NULL==strSRC)
	  return NULL;
    if(strDest == strSRC)
	  return strDest;
	
	char *temp = strDest;
	while(*strDest!='\0')
	{
		*strDest=*strSRC;
		strDest++;
		strSRC++;
	}
	return temp;
}

# ifdef __cplusplus
cout<<"C++";
#else
cout<<"C";
#endif

