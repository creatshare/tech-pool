#define _CRT_SECURE_NO_WARNINGS		//预编译处理
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define N 15	//name
#define M 15	//phone
#define H 30	//category

void FunctionSelect();
void Menu();


//结构体声明
typedef struct node //节点定义
{
	char name[N];
	char phone[M];
	char category[H];
	struct node *next;
}Node, *LinkPerson;


LinkPerson L;	//创建通讯录头结点

int Per_i = 0;		//定义全局变量，统计人数

void CreatMailList()		//通讯录信息收录
{
	char nameTemp[N];
	char phoneTemp[M];
	char categoryTemp[H];

	LinkPerson pNew;
	LinkPerson pCur;

	pCur = L;

	while (pCur->next) {		//将游标移动至空
		pCur = pCur->next;
	}

	printf("请输入联系人信息：(当名字为 exit 时结束输入)\n");
	printf("name phone category\n");
	while (1) {
		printf("---------------------\n");
		scanf("%s", nameTemp);
		if (strcmp(nameTemp, "exit") == 0)
			break;

		scanf("%s %s", phoneTemp, categoryTemp);

		pNew = (LinkPerson)malloc(sizeof(Node));

		strcpy(pNew->name, nameTemp);
		strcpy(pNew->phone, phoneTemp);
		strcpy(pNew->category, categoryTemp);

		pCur->next = pNew;
		pCur = pNew;

		Per_i++;
	}

	pCur->next = NULL;

	return;
}

void SortByName()
{
	int lenList = Per_i;

	LinkPerson pPre;
	LinkPerson pCur;
	LinkPerson pNext;
	LinkPerson pTemp;

	int i;
	int j;

	for (i = 0; i<lenList - 1; i++) {

		pPre = L;
		pCur = L->next;   //现在的指针序列：head--p--pNext  
		pNext = pCur->next;

		for (j = 0; j<lenList - 1 - i; j++) {

			if (strcmp(pCur->name, pNext->name) > 0) {

				pPre->next = pCur->next;
				pCur->next = pNext->next;
				pNext->next = pCur;

				pTemp = pCur;
				pCur = pNext; //当上面的交换完成后，最开始的变化为head--pNext--p  
				pNext = pTemp;//那么后面的排序就会出错，这里的操作就是把指针换回来  
			}

			pPre = pPre->next;//指针往后移动  
			pCur = pCur->next;
			pNext = pNext->next;
		}
	}

}

void PrintMailList()	//打印通讯录
{
	LinkPerson pCur;
	pCur = L->next;
	int i = 0;

	printf("----------------------------------------------\n");
	printf("序号: 姓名\t\t电话\t\t类型\n");
	printf("----------------------------------------------\n");

	while (pCur) {
		printf("----------------------------------------------\n");
		printf("%4d: %-18s%-16s%s\n", ++i, pCur->name, pCur->phone, pCur->category);
		pCur = pCur->next;
	}
	printf("----------------------------------------------\n");

	return;
}

void QueryByName()
{
	char nameTemp[N];
	int i = 0;

	LinkPerson pCur;
	pCur = L->next;

	printf("请输入你要查找的联系：");
	scanf("%s", nameTemp);
	while (pCur) {
		if (strcmp(nameTemp, pCur->name) == 0) {
			printf("----------------------------------------------\n");
			printf("%4d: %-18s%-16s%s\n", i + 1, pCur->name, pCur->phone, pCur->category);
			printf("----------------------------------------------\n");
			break;
		}
		pCur = pCur->next;
		i++;
	}

	return;
}

void DeleteByName()
{
	char nameTemp[N];

	LinkPerson pCur;
	LinkPerson pTemp;
	pCur = L;

	printf("请输入要删除的联系人：");
	scanf("%s", nameTemp);

	while (pCur->next) {
		if (strcmp(pCur->next->name, nameTemp) == 0) {
			break;
		}
		pCur = pCur->next;
	}

	pTemp = pCur->next;
	pCur->next = pCur->next->next;
	Per_i--;
	free(pTemp);

	return;
}

void UpdataByName()
{
	char nameTemp[N];

	LinkPerson pCur;
	pCur = L;

	printf("请输入你要修改的联系人：");
	scanf("%s", nameTemp);

	while (pCur) {
		if (strcmp(nameTemp, pCur->name) == 0) {
			printf("请输入电话号码：");
			scanf("%s", pCur->phone);
			printf("请输入类别：");
			scanf("%s", pCur->category);
			break;
		}
		pCur = pCur->next;
	}

	return;

}

void FunctionSelect()
{

	printf("请输入数字选择：");
	//选择功能实现

loop: int x;
	scanf("%d", &x);
	switch (x) {
	case 1:
		CreatMailList();
		FunctionSelect();
		break;

	case 2:
		SortByName();
		PrintMailList();
		FunctionSelect();
		break;

	case 3:
		QueryByName();
		FunctionSelect();
		break;

	case 4:
		CreatMailList();
		FunctionSelect();
		break;

	case 5:
		DeleteByName();
		FunctionSelect();
		break;

	case 6:
		UpdataByName();
		FunctionSelect();
		break;
	case 7:
		system("cls");
		Menu();
		break;

	case 8:
		exit(0);
		break;

	default:
		printf("请重新输入：");
		goto loop;
	}
}



void Menu()
{
	//功能选择外观样式
	printf("                         通讯录\n");
	printf("**************************************************************\n");
	printf("*   1.添加联系人                                2.显示联系人 *\n");
	printf("*   3.查询联系人                                4.增加联系人 *\n");
	printf("*   5.删除联系人                                6.修改联系人 *\n");
	printf("*   7.清屏                                      8.千万别选   *\n");
	printf("**************************************************************\n");
	FunctionSelect();
}

int main()
{

	L = (LinkPerson)malloc(sizeof(Node));
	L->next = NULL;	 //创建空链表 
					 //菜单
	Menu();

	system("pause");

	return 0;
}