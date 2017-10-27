#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81
void append (FILE *source ,FILE *dest);

int main(void)
{
	FILE *fa,*fs;
	int files = 0;
	char file_app[SLEN];
	char file_src[SLEN];
	puts("Enter name of destination file: ");
	gets(file_app);
	if ((fa = fopen(file_app,"a")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", file_app);
		exit(2);
	}
	if (setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fputs("Can't creat output buffer\n",stderr);
		exit(3);
	}
	puts("Enter name of first source file (empty line  to quit):");
	while(gets(file_src) && file_src[0]!= '\0')
	{
		if(strcmp(file_src,file_app) == 0)
			fputs("Can't append file to itself\n",stderr);
		else if((fs=fopen(file_src,"r"))== NULL)
			fprintf(stderr,"Can't open %s \n",file_src);
		else
		{
		
				if (setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
			{
				fputs("Can't creat input buffer\n",stderr);
				continue;
			}
			append(fs,fa);
			if (ferror(fs)!= 0)
				fprintf(stderr, "Error in reading file %s\n",file_src );
			if(ferror(fa)!= 0)
				fprintf(stderr, "Error in writing file %s\n",file_app );
			fclose(fs);
			printf("File %s appended.\n",file_src );
			puts("Next file (empty line to quit):");
		}
	}
	return 0;
}
void append (FILE *source ,FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE]; //分配一次
	while((bytes = fread(temp,sizeof(char),BUFSIZE,source))>0)
		fwrite(temp,sizeof(char),bytes,dest);
}