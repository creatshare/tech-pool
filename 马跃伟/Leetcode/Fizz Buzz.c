char** fizzBuzz(int n, int* returnSize) {
    char **p;
    int i;
    p=(char **)malloc(n*sizeof(char *));
    for(i=0;i<n;i++)
        p[i]=(char *)malloc(10*sizeof(char));
    for(i=1;i<n+1;i++)
    {
        if(i%15==0)
              *(p+i-1)="FizzBuzz";
        else if(i%5==0)
            *(p+i-1)="Buzz";
        else  if(i%3==0)
            *(p+i-1)="Fizz";
        else
              sprintf(*(p+i-1), "%d", i);
    }
    * returnSize = n;
    return p;

}
