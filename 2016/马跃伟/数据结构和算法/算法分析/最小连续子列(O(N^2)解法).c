//算法适用于数组元素不全为负数的类型
int MaxsubSequenceSum (const int A[],int N) //N为数组A的长度
{
	int Thissum,Maxsum;
	int i,j;
	Maxsum=0;
	for (i = 0; i < N; i++)
	{
		Thissum=0;
		for ( j = i; j < N; j++)
		{
			Thissum += A[j];
			if(Thissum > Maxsum)
				Maxsum=Thissum;
		}
	}
	return Maxsum;
}