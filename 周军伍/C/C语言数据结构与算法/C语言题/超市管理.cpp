//手机通讯录

#include<stdio.h>
#include<string.h>
#include<cstdlib>
#define N 200

int per_i=0;
void Sort();
void Get();
void Show();
void Check();
void Add();
void Add();
void Menu();
void fun();

struct Person		//联系人基本信息定义
{
	char name[12];
	char telephone[12];
	char category[8];	//联系人类别：例如家人，同事，朋友
}Per[N];



void Sort()
{
	struct Person temp;
	for(int j=0; j<per_i-1; j++)
		for(int k=0; k<per_i-j-1; k++)
			if(strcmp(Per[k].name,Per[k+1].name)>0){
				temp=Per[k];
				Per[k]=Per[k+1];
				Per[k+1]=temp;
			}
}

void Get()		//录入基本信息     //并按照字典顺序排序
{
	//键入提示语
	int n;
	printf("请输入要录入的联系人个数："); 
	scanf("%d", &n);
	int i;
	for(i=0; i<n; i++){
		Add();
	}
	Show();
	fun();
}

void Show()		//输出每一个联系人基本信息
{	
	if(per_i==0)
		printf("通讯录中没有联系人额！\n");
	else{
		//对其按字典排序
		Sort();
		printf("这是全部联系人名单\n");
		for(int k=0; k<per_i; k++)		//输出
			printf("%d.%s：%s\t%s\n",k+1,Per[k].name,Per[k].telephone,Per[k].category);
	}	
	fun();
}

void Check()		//查询联系人
{
	//查询
	char name_temp[12];
	printf("请输入姓名：");
	getchar();
	gets(name_temp);
	int flag=0;
	for(int j=0; j<per_i; j++){
		if(strcmp(name_temp,Per[j].name)==0){
			flag=1;
			printf("%d.%s：%s\t%s\n",j+1,Per[j].name,Per[j].telephone,Per[j].category);
		}
	}
	if(flag==0)
			printf("亲，查不到此人哦\n");
	fun();
}

void Add()		//添加联系人电话 
{
	//键入基本信息
	scanf("%s", Per[per_i].name);
	scanf("%s", Per[per_i].telephone);
	scanf("%s", Per[per_i].category);
	per_i++;
}

void Delete()		//删除联系人
{
	//删除提示
	char name_temp[12];
	printf("请输入你要删除的联系人：");
	getchar();
	gets(name_temp);
	for(int j=0; j<per_i; j++){
		if(strcmp(name_temp,Per[j].name)==0){
			if(j==per_i-1){
				per_i--;
			}
			else{
				per_i--;
				for(int k=j; k<per_i; k++){
					Per[k]=Per[k+1];
				}
			}
		}
	}
	fun();		
}

void fun()
{
	printf("请输入数字选择：");
	//选择功能实现
	loop: int x;
	scanf("%d", &x);
	switch(x){
			case 1:Get();break;
			case 2:Show();break;
			case 3:Check();break;
			case 4:Add();break;
			case 5:Delete();break;
			case 6: exit(0);break;
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
	printf("*   1.批量添加联系人                           2.显示联系人  *\n");
	printf("*   3.查询联系人                               4.增加联系人  *\n");
	printf("*   5.删除联系人                               6.千万别选    *\n");
	printf("**************************************************************\n");
	fun();
}
	

int main()
{
	//菜单
	Menu();
}
