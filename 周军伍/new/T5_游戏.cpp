#define _CRT_SECURE_NO_WARNINGS		//预编译处理
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node		// 定义节点
{
	int num;	//编号
	int pwd;	//密码
	struct node *next;
}Node, *LinkList;


void CreatList(LinkList &L, int n)	// 创建链表
{
	int data;
	LinkList LNew, pCur;

	pCur = L;

	int i;
	srand((unsigned)time(NULL));


	for (i = 0; i < n; i++) {
		LNew = (LinkList)malloc(sizeof(Node));
		LNew->num = i + 1;
		LNew->pwd = (rand() % 5 + 1);

		pCur->next = LNew;
		pCur = LNew;
	}

	pCur->next = L->next;

	return;
}

void Print(LinkList L)	// 打印链表
{
	if (L->next == NULL) {		//判断空链表
		printf("此链表为空！\n");
		return;
	}

	LinkList pCur;
	pCur = L->next;

	while (1) {
		printf("%-4d%-4d\n", pCur->num, pCur->pwd);
		pCur = pCur->next;
		if (pCur == L->next)
			break;
	}
	return;
}

void Game(LinkList &L, int n)
{
	int count_All;	//计数器，用于标记当前的个数
	int count_Every;	//单次循环计数器

	LinkList pPre;
	LinkList FreeTemp;

	count_All = 0;	
	count_Every = 1;

	int flagPwd;	
	srand((unsigned)time(NULL));	/* 设置初始密码为随机值（1~n） */
	flagPwd = rand()%n+1;
	
	pPre = L;
	
	printf("初始密码为：flagPwd=%d\n", flagPwd);

	while (1) {
		if (flagPwd == count_Every) {

			printf("%d ", pPre->next->num);		//打印 出局者 的序号

			printf("%d\n", pPre->next->pwd);	// 打印 出局者 的 pwd

			flagPwd = pPre->next->pwd;		//重置密码 pwd 为 出局者密码

			FreeTemp = pPre->next;		// 记录出局者 待后续释放空间

			pPre->next = pPre->next->next;		//删除节点（出局者）

			free(FreeTemp);		//释放出局者 

			count_All++;	//计数 删除节点的个数

			count_Every = 0;	// 删除节点之后，计数为置为 0
		}
		else {

			pPre = pPre->next;	//游标后移
		}

		count_Every++;	//当前计数加 +1 

		if (count_All == n) {
			L->next = NULL;
			break;
		}

		fflush(stdin);	//清除缓存
	}
}


int main()		//主函数
{
	LinkList L;	// 

	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;		//头结点指针域为空，防止为合并之后为空的输出异常

	int n;	//游戏人数
	printf("请输入游戏人数:");
	scanf("%d", &n);

	CreatList(L, n);	//初始化游戏
	printf("游戏初始化结果：\n");
	Print(L);			//打印初始化结果

	printf("游戏结果：\n");	//游戏处理
	Game(L, n);

	//printf("结果：\n");
	//Print(L);

	system("pause");

	return 0;
}

