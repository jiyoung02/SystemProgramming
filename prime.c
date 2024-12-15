int isPrime(int a)
{
	int i = 2;
	for (i; i < a; i++)
		if ((a % i) == 0) break;
	return (i == a)? 1 : 0;
}


