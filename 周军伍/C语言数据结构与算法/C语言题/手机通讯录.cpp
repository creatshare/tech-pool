#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100


struct date		//进货日期 
{
	int year;
	int month;
	int day;
};

struct other2	//保质期 
{
	int day;
};

struct Other1		//家电 
{
	char GCompany[10];
	char GTel[12];
};

struct Goods		//共同类别 
{
	int GNumber;		//商品号 
	struct date GGet;		//商品进货日期 
	int GPrice;		//商品价格 
	int GQuantity;	//商品数量 
	char GCategory[10];	//商品类别
	union
	{
		struct Other1 Elec; 
		struct other2 Food;
	}Go;
};

struct Goods Good[N]; 

int Good_i=0;

int Menu();

void Get()		//录入商品信息 
{	
	printf("请输入商品信息：\n");
	
	printf("请输入商品编号：");
	scanf("%d", &Good[Good_i].GNumber);
	
	printf("请输入购进日期：");
	scanf("%d %d %d", &Good[Good_i].GGet.year, &Good[Good_i].GGet.month, &Good[Good_i].GGet.day);
	
	printf("请输入商品价格：");
	scanf("%d", &Good[Good_i].GPrice);
	
	printf("请输入商品数量：");
	scanf("%d", &Good[Good_i].GQuantity);
	
	printf("请输入商品种类：");
	scanf("%s", Good[Good_i].GCategory);
	
	if(strcmp(Good[Good_i].GCategory, "家电")==0){
		printf("请输入单位：");
		scanf("%s", Good[Good_i].Go.Elec.GCompany);
		
		printf("请输入电话：");
		scanf("%s", Good[Good_i].Go.Elec.GTel);
	}
	
	if(strcmp(Good[Good_i].GCategory, "食品")==0){
		printf("请输入保质期：");
		scanf("%d", &Good[Good_i].Go.Food.day);
	}
	
	Good_i++;
	printf("\n"); 
	Menu();
}

void Print()		//打印商品信息 
{	
	int i;
	for(i=0; i<Good_i; i++){
		printf("商品编号：%d\n", Good[i].GNumber);
		printf("购进日期：%d %d %d\n", Good[i].GGet.year, Good[i].GGet.month, Good[i].GGet.day);
		printf("商品价格：%d 元\n", Good[i].GPrice);
		printf("商品数量：%d 个(台)\n", Good[i].GQuantity);
		printf("商品种类：%s\n", Good[i].GCategory);
		if(strcmp(Good[i].GCategory, "家电")==0){
			printf("保修单位：%s\n", Good[i].Go.Elec.GCompany);
			printf("保修电话：%s\n", Good[i].Go.Elec.GTel);
		}
		if(strcmp(Good[i].GCategory, "食品")==0){
			printf("保质期：%d\n", Good[i].Go.Food.day);
		}
		printf("\n");
	}
	Menu();
}

int Menu()		//功能选择 
{
	loop:printf("请输入功能：");
	int n;
	scanf("%d", &n);
	switch(n){
		case 1:Get();break;
		case 2:Print();break;
		case 3:exit(0); 
		default:goto loop;		//输入其他则重新输入 
	}
}

int main()		//主函数 
{	
	printf("输入1添加商品，输入2输出商品,输入3则退出\n");
	Menu();
} 