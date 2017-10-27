long int pow(int X, unsigned int N)
{
	if(N == 0)
		return 1;
	else if(N == 1)
		return X;
	else if(IsEven(N))
		return pow(X * X,N / 2);
	else
		return pow(X * X,(N-1)/2) * X;

}