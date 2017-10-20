#include "list.h"
int Length(List PtrL) //求表长
{
    List p =PtrL;
    int j = 0;
    while(p){
        p = p->Next;
        j++;
    }
    return j;
}

List FindKth(int K,List PtrL) //找出第K个元素的位置
{
    List p = PtrL;
    int i = 1;
    while(p != NULL && i < K){
        p = p->Next;
        i++;
    }
    if (i == K) return p;   //第二个条件跳出循环,找到了
    else return NULL;       //找完了,没找到,
}

List Find(ElementType a ,List PtrL) //找到第一次值为a的链表的位置
{
    List  p = PtrL;
    while(p != NULL && p->Data!=a )
        p = p->Next;
    return p;
}

List Insert(ElementType X, int i,List PtrL) //在第i个位置插入一个值为X的节点.
{
    List p,s;
    if (i == 1)                                              //插入在表头
    {
        s = (List)malloc(sizeof(struct LNode));             //申请空间,写入数据
        s ->Data = X;
        s ->Next = NULL;
        return s;                                               //返后新的头指针
    }
    p = FindKth(i-1,PtrL);
    if (p == NULL)
    { printf("参数错误.");
        return NULL;
    } else{
        s = (List)malloc(sizeof(struct LNode));             //申请空间,写入数据
        s ->Data = X;
        s ->Next = p ->Next;                                  //新节点插入在第i-1个结点的后面
        p ->Next = s;
        return PtrL;
    }
}

List Delete(int i,List PtrL)   //删除第i个结点
{
    List  p,s;
    if( i == 1){                                //如果删除的是头结点
        s =PtrL ;
        if(PtrL != NULL) PtrL = PtrL->Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i-1,PtrL);                      //找要删除的的结点的前一个结点的位置为p
    if (p == NULL) {
        printf("找不到第%d个结点", i - 1);
        return NULL;
    }else if(p->Next == NULL) {
        printf("找不到第%d个结点", i - 1);
        return NULL;
    }else{                                    //s指向要删除的结点
        s = p->Next;                          //去除要删除的结点
        p->Next = s->Next;
        free(s);                              //释放要删除结点所占的内存空间
        return PtrL;
    }
}

List Chage(ElementType X,int i,List PtrL)  //修改第i个位置的的值为X
{
    List p;
    p = FindKth(i,PtrL);
    if(p == NULL) {
        printf("找不到%d个结点.", i);
        return NULL;
    }
    else{
        p->Data = X;
        printf("修改成功");
        return PtrL;
    }
}

void Show(int i,List PtrL)//输出第i个位置的结点
{
    List p;
    p = FindKth(i,PtrL);
    if( p == NULL ){
        printf("找不到%d个结点.", i);
    }else{
        printf("%s",p->Data);
    }

}

void show_all(List PrtL)
{
    while (PrtL != NULL) {
        int i = 1;
        printf("留言%d :", i);
        Show(i, PrtL);
        printf("\t__________________________________________________\n");
        PrtL = PrtL->Next;
        i++;
    }}

void show_one(List PrtL) {
    int F;
    printf("请输入留言序号\n");
    scanf("%d", &F);
    printf("留言%d :", F);
    Show(F, PrtL);
    printf("\t__________________________________________________\n");
}
void wirte_one(List PrtL){
    char temp[81];
    int L;
    printf("请输入留言:");
    gets(temp);
    L = Length(PrtL);
    if (L == 1) PrtL = Insert(temp, 1, PrtL);
    else Insert(temp, L, PrtL);
}
void change_one(List PrtL){
    char temp[81];
    int C;
    printf("请输入要修改留言的序号\n");
    scanf("%d", &C);
    printf("请输入修改后的留言\n");
    gets(temp);
    Chage(temp, C, PrtL);
}
void delete_one(List PrtL){
    int D;
    printf("请输入要删除的留言序号\n");
    scanf("%d", &D);
    Delete(D, PrtL);
}
