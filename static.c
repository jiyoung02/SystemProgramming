#include<stdio.h>
#include"fibo.h"
#include"prime.h"

int main(){
	int a;
	printf("\n<static linking test>\n\n");
	printf("input positive num : ");
	scanf("%d",&a);
	
	// test prime
	int p = isPrime(a);
	if (p) printf("%d is a primenumber, p is %d\n",a,p);
	else printf("%d is not a primenumber, p is %d\n",a,p);

	// test fibo
	printf(" %dth fibo num : %d\n",a, getFibo(a));
	printFibo(a);
	int* arr = getFiboList(a);
	printf("FiboList : ");
	for(int i = 0; i<a; i++)
		printf("%d ",arr[i]);
	printf("\n\n");
	return 0;
}

