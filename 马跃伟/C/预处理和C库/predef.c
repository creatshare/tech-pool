#include <stdio.h>
void why_me();
int main()
{
	printf("The file is %s.\n",_ _FILE_ _);
	printf("The date is %s.\n"_ _DATE_ _);
	printf("The time is %s.\n",_ _TIME_ _);
	printf("The version is %ld.\n",_ _STDC_VERSION_ _);
	printf("The is line %d.\n",_ _LINE_ _);
	printf("The function is %s\n",_ _func_ _);
	why_me();

	return 0;
}
void why_me()
{
	printf("This function is %s\n",_ _func_ _);
	printf("This is line %d.\n",_ _LINE_ _);
}