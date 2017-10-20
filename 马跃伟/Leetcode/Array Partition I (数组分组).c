int arrayPairSum(int* nums, int numsSize) {
    int sum=0;
    int i,t,p;
    for (i =1; i < numsSize; ++i)  //ÅÅĞò 
    {
        t=nums[i];
        p=i-1;
        while(p>=0 && t<nums[p])
        {
            nums[p+1]=nums[p];
            p--;
        }
        nums[p+1]=t;
    }
    for(i=0;i<numsSize;i=i+2)     //ÀÛ¼Ó 
        sum += nums[i];
    return sum;
}

