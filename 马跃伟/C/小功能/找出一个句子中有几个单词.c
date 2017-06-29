#include <stdio.h>
int fun(char *str)
{
	int i=0;
	int count=1;
	while(*(str+i)!='\0')
	{
		if (*(str+i)==' ')
		{
			if(*(str+i+1)!=' ')
				count++;
		}
		i++;
	}
	return count;
}
