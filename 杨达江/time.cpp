#include<stdio.h>
  
void First(int a)  
{  
    if(a==1) printf("   ");  
    if(a==2) printf(" _ ");  
    if(a==3) printf(" _ ");  
    if(a==4) printf("   ");  
    if(a==5) printf(" _ ");  
    if(a==6) printf(" _ ");  
    if(a==7) printf(" _ ");  
    if(a==8) printf(" _ ");  
    if(a==9) printf(" _ ");  
    if(a==0) printf(" _ ");  
  
}  
  
void Second(int a)  
{  
    if(a==1) printf("  |");  
    if(a==2) printf(" _|");  
    if(a==3) printf(" _|");  
    if(a==4) printf("|_|");  
    if(a==5) printf("|_ ");  
    if(a==6) printf("|_ ");  
    if(a==7) printf("  |");  
    if(a==8) printf("|_|");  
    if(a==9) printf("|_|");  
    if(a==0) printf("| |");  
}  
  
void Third(int a)  
{  
    if(a==1) printf("  |");  
    if(a==2) printf("|_ ");  
    if(a==3) printf(" _|");  
    if(a==4) printf("  |");  
    if(a==5) printf(" _|");  
    if(a==6) printf("|_|");  
    if(a==7) printf("  |");  
    if(a==8) printf("|_|");  
    if(a==9) printf(" _|");  
    if(a==0) printf("|_|");  
}  
  
void Print(int a,int b,int c,int d,int e,int f,int g,int h)  
{  
    First(a);  
    First(b);  
    First(c);  
    First(d);  
    printf("\n");
    Second(a);  
    Second(b);  
    Second(c);  
    Second(d);  
    printf("\n");  
    Third(a);  
    Third(b);  
    Third(c);  
    Third(d);  
    printf("\n");
    First(e);  
    First(f);  
    First(g);  
    First(h);  
    printf("\n");
    Second(e);  
    Second(f);  
    Second(g);  
    Second(h);  
    printf("\n");  
    Third(e);  
    Third(f);  
    Third(g);  
    Third(h);  
    printf("\n");
    return;
}  
int main()  
{  
    int a,b,c,d,e,f,g,h;
	while(scanf("%d %d %d %d\n%d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h)!=EOF)
	{
	    Print(a,b,c,d,e,f,g,h);
	  } 
    return 0;  
}
