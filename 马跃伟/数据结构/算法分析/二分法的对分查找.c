//查找一个数时适用于已经排列好的数组
int BrnarySearch(const int A[],int X,int N) //X为要查找的数,N为数组的长度
{
	int Low,Mid,High;
	Low=0;
	High=N-1;
	while(Low <= High)
	{
		Mid=(Low+High)/2;
		if(A[mid] < X)
			Low=Mid;
		else if(A[Mid] > X)
			High=Mid-1;
		else 
			return Mid;
	}

	return -1;
}