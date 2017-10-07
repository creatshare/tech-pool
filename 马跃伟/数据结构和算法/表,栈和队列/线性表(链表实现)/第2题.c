//链表结点声明
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

void mv(Node* la,Node* lb,int i,int j)
{
	Node *pi,*pj=lb,*picur=la,*pIprior=la;
	int k=0;
	while(pIprior != NULL && k < i-1){    //把pIprior 放在la表第i个结点的前驱结点
        pIprior = pIprior->next;
        i++;
    }	

	while(picur->next != NULL)	//把picur放在la表的表尾
		picur =picur->next;

	while(pj != NULL && k < j){	 //把pj放在lb表的第j个结点
        pj = pj->next;
        i++;
    }	
	 	
	 pi = pIprior->next;		//pi指向la表的第i个结点
	 picur->next = pj->next;	//la表的表尾指向lb表第j个结点的下一个结点
	 pj->next = pi;				//把la表从第i个结点后都连接到lb表的第j个结点后	
	 pIprior->next = NULL;		//让la表第i-1个结点指向空
}
