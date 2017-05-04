#include<stdio.h>
#include<stdlib.h>

typedef char ElementType;

typedef struct Node
{
	ElementType data;
	struct Node *next;
}LNode, *List;




//遍历链表 
void Print(List L)
{
	List p;
	p = L->next;
	while (p != NULL) {
		printf("%c^\n", p->data);
		p = p->next;
	}
	return;
}

//清空链表 
void Free(List L)
{
	List p;
	p = L->next;
	while( p != NULL){
		free(p);
		p=p->next;
	}
}

int main()
{
	List L;
	List pEnd, pNew;
	ElementType data0;
	L = (List)malloc(sizeof(LNode));
	int flag = 1;
	pNew = pEnd = L;
	while (flag) {
		scanf("%c", &data0);
		if (data0 != '0') {
			pNew = (List)malloc(sizeof(LNode));
			pNew->data = data0;

			pEnd->next = pNew;
			pEnd = pNew;
		}
		else {
			pEnd->next = NULL;
			break;
		}
	}


	Print(L);
	
	//清空链表 
	Free(L);
	system("pause");
	return 0;
}