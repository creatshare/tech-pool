#include<stdio.h>

int Gcd(int x, int y)
{
	int Rem;
	while(y>0){
		Rem=x%y;
		x=y;
		y=Rem;
	}
	return x;
}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n", Gcd(x, y));
}