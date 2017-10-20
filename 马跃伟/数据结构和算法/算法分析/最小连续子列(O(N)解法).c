//算法适用于数组元素不全为负数的类型
int MaxsubSequenceSum (const int A[],int N) //N为数组A的长度
{
	int Thissum,Maxsum;
	int i;
	Thissum=Maxsum=0;
	for(i=0; i<N ; i++)
	{
		Thissum += A[i];
		if (Thissum >Maxsum)
			Maxsum=Thissum;
		else if(Thissum < 0)
			Thissum=0;
	}
	return Maxsum;
}