//链表结点声明
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

void reserve(Node *head)
{
	Node *pNow = head;	//逆制前链表的第一个结点
	head = NULL;  //逆制链表的头结点
	Node *pTem = NULL； //正在逆制的结点
	while(pNow != NULL)
	{
		pTem = pNow;		//未转置链表的第一个结点为正在转置的结点
		pNow = pNow->next;	//移动到下一轮的结点
		pTem->next = head;	//将当前结点插入到新链表的头结点前面
		head = pTem;		//把头结点向前移动到新插入的结点
	}
}