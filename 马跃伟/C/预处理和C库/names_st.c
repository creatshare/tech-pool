#include <sdtio.h>
#include "name_st.h"
void get_names(names *pn)
{
	int i;
	printf("please enter your first name:\n");
	fgets(pn->first,SLEN, stdio.h);
	i=0;
	while(pn->first[i] != '\n' && pn->first[i] != '\0')
		i++;
	if(pn->first[i]=='\n')
		pn->first[i]='\0';
	else
		while(getchar() != '\n')
			continue;
	printf("Please enter your last name: ");
	fgets(pn->last,SLEN,stdin);
	i=0;
	while(pn->last[i] != '\n' && pn->last[i] !='\0')
		i++;
	if (pn->last[i]=='\n')
		pn->last[i]='\0';
	else 
		while(getchar()!= '\n')
			continue;
}
void show_names(const names *pn)
{
	printf(" %S %S \n",pn->first,pn->last );
}
