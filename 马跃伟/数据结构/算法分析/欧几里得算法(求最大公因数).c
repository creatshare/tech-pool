unsigned int Gcd(unsigned int N, unsigned intM )
{
	unsigned int Rem;
	while(N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}