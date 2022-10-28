
int checkString(char str[], char sub[]){
	char *p1, *p2, *p3;
	int i=0,j=0,flag=0;

	p1 = str;
	p2 = sub;

	for(i = 0; i < strlen(str); i++)
	{
		if(*p1 == *p2)
		{
			p3 = p1;
			for(j = 0;j < strlen(sub);j++)
			{
				if(*p3 == *p2)
				{
				p3++;p2++;
				} 
				else
				break;
			}
			p2 = sub;
			if(j == strlen(sub))
			{
				flag = 1;
				return 1;
			}
		}
		p1++; 
	}
	if(flag==0)
	{
		return 0;
	}
}

