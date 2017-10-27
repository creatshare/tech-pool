void insertionSort(int A[],int N)
{
    int j,P;
    int Tmp;
    for(P = 1;P < N; P++)
    {
        Tmp = A[P];
        for(j = P;j > 0 && a[j-1] > Tmp; j--)
            A[j]=A[j-1];
        A[j] = Tmp;
    }
}
