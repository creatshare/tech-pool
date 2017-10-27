void LevelOrderTraversal(BinTree BT)
{
	Queue Q; BinTree T;
	if(!BT)	return; 	//如果是空树直接返回
	Q = CreatQueue(MaxSize); //创建并初始化队列
	AddQ(Q,BT);
	while( !IsEmpty(Q) ){
		T = DeleteQ(Q);
		printf("%d\n",T->Data );
		if(T->Left) AddQ(Q,T->Left);
		if(T->Right) AddQ(Q,T->Right);
	}
}