//数组类型说明

typedef int ElemenType

ElemenType a[n];

void reserve(ElemenType *a)
{
	int len = sizeof(a)/sizeof(a[0]);
	int i;
	ElemenType tem; 
	for(i = 0; i < len/2; i++)
	{
		tem = a[i];
		a[i] = a[len - i];
		a[len - i] = tem;
	}
	
}