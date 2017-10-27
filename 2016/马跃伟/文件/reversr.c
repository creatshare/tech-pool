#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\0329'
#define SLEN 50
int main(void)
{
	char file[SLEN];
	char ch;
	FILE *fp;
	long count ,last;

	puts("Enter the name of the file to processed: ");
	gets(file);
	if ((fp = fopen(file, "rb")) == NULL)
	{
		printf("reverse can't open %s\n",file );
		exit(1);
	}
	fseek(fp,0L,SEEK_END);
	last = ftell (fp);
	for (count = 1L; count <= last; count++)
	{
		fseek(fp,-count,SEEK_END);
		ch= getc(fp);
		//针对DOS，在UNIX下也可以
		if (ch != CNTL_Z && ch != '\r')
			putchar(ch);
		if (ch == '\r')
			putchar('\n');
		else 
			putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	return 0;
}
