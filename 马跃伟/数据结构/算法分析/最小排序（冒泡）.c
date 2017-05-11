#include <stdio.h>
#define numb 20
int main()
{
	int num[numb],i,j,t;
	for (i = 0; i < numb; ++i)
		num[i] = rand(); 
	for ( i = 0; i <numb-1; ++i)
	{

	  for (j= 0; j< numb-1-i; ++j)
		{
			if(num[j]<num[j+1])
			{	t=num[j];
				num[j]=num[j+1];
				num[j+1]=t;
	    	}
     	}
    }
     for ( i = 0; i < numb; ++i)
     {
     	printf("%d\n",num[i]);/* code */
     }
    
return 0;
}
