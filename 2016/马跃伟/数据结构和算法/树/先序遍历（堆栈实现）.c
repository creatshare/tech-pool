void InOrderTraversal (BinTree BT)
{
	BinTree T BT;
	stack S = CreatStack(MaxSize); //创建并初始化堆栈S
	while(T || !IsEmpty(s)){
		while(T){	//一直向左并将沿途结点压入堆栈
			Push(S,T);
			T = T->next;
		}
		if(!IsEmpty(S)){
			T = Pop(S);		//结点弹出堆栈
			printf("%5d\n",T->Data );	//访问打印结点
			T = T->Right;	//转向左子树
		}
	}
}