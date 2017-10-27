void Quicksort(int A[], int left, int right)
{
	int pivot,i,j;
	pivot = Median3(A[],left,right);
	i=left;
	j=right-1;
	while(i<=j)
	{
		while(A[++i] <= pivot){;}
		while(A[--j] >= pivot){;}
		Swap(&A[i],&A[j]);
	}
	Swap(&A[i],&A[right-1]);
	Quicksort(A,Left,i-1);
	Quicksort(A,i+1,Right);
}

int Median3(int A[],int left, int right)
{
	int Center = (left + right)/2;
	if(A[left] > A[Center])
		Swap(&A[left],&A[Center]);
	if(A[Center] > A[right])
		Swap(&A[Center],&A[right]);
	if(A[left] > A[Center])
		Swap(&A[left],&A[Center]);
	 /* 此时A[Left] <= A[Center] <= A[Right] */
	Swap(&A[Center],&A[right-1]);	
	//因为A[Right]一定比Centert大到时候就少考虑一个元素哈哈哈.
	return A[Right-1];
}

void Swap(int *A, int *B)
{
	int tem;
	tem = *A;
	*A = *B;
	*B = tem;
}