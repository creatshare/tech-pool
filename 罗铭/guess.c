#include <stdio.h>
int main(void)
{
	int guess = 1;
	printf("从1到100选一个数，我会尽力去猜出它\n");
	printf("判断用y或者n来表示正确和错误\n");
	printf("嗯~ 你选的数字是1吗？\n");
	while (getchar()!= 'y')
		printf("好的。。这样你的数字是%d?\n", ++guess);
	printf("我知道我可以猜出来！\n");

	return 0;	
}
