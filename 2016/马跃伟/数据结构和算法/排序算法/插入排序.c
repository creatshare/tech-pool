viod insertion_sort(int *Array,int N)   //升序 
{
	int i,temp,p;
	for(i = 1; i < N ; i++)    //从第二个开始,给前面排好序的队列里面插入 
	{
		temp = a[i];			//拿出当前要插入的变量 
		p = i - 1;		
		while(p >= 0 && a[p] <temp )	//比较到头或者是找到比要插入的变量小的元素 
		{
			a[p+1] = a[p];
			p--;
		}
		a[p+1] = temp;					//插入到找的的元素都后面 
	}
}
