void ShellSort(int A[],int N)
{
    int i,j,Increment;
    int Tmp;
    for(Increment = N/2; Increment > 0 ;Increment /= 2)
    {
        for(I = Increment;i < N; i++)
        {
            Tmp = A[i];
            for(j = i;j > 0 && a[j-Increment] > Tmp; j -= Increment)
                A[j]=A[j-Increment];
            A[j] = Tmp;
        }
    }
}
