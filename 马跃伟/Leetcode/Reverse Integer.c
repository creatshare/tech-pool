int reverse(int x) {
    int a=0;
    while(x != 0)
    {
        a = a * 10+(x % 10);
        x /= 10;
    }
    return a;
}
