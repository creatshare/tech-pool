#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum weekday{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

struct date
{
	int year;
	int month;
	int day;
}Date;

int JudgeLeap(int JYear)
{
	return (JYear%4==0 && JYear%100!=0) || JYear%400==0;
}

int Month(int month, int year)
{
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			if(JudgeLeap(year)){
				return 29;
			}	
			else{
				return 28;
			}		
	}
}

int DaySum()
{
	int i;
	int k;
	int sum=0;
	for(i=1980; i<Date.year; i++){ 
		if(JudgeLeap(i)){
			sum += 366;
		}
		else{
			sum += 365;
		}
	}
	for(k=1; k<Date.month; k++){
		sum +=  Month(k, Date.year);
	}
		
	sum += Date.day;
	return sum;
}

int Print()
{
	int sum;
	sum=DaySum();
	int d;
	d=sum%7;
	switch(d){
		case 1:printf("星期：%d\n", Tuesday);break;
		case 2:printf("星期：%d\n", Wednesday);break;
		case 3:printf("星期：%d\n", Thursday);break;
		case 4:printf("星期：%d\n", Friday);break;
		case 5:printf("星期：%d\n", Saturday);break;
		case 6:printf("星期天\n");break;
		case 0:printf("星期：%d\n", Monday);break;
	}
}

int main()
{
	printf("请输入日期：");
	scanf("%d %d %d", &Date.year, &Date.month, &Date.day);
	Print();
}
