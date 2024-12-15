#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

void throwError(){
	fprintf(stderr, "%s\n",dlerror());
	exit(1);
}


int main(){
	int a;
	void* handle;
	int (*isPrime)(int);
	int (*getFibo)(int);
	int* (*getFiboList)(int);
	void(*printFibo)(int);
	char* error;
	
	printf("\n<runtime linking test>\n\n");
	
	handle = dlopen("./libMyMath.so",RTLD_LAZY);
	if(!handle) throwError(); 
	isPrime = dlsym(handle,"isPrime");
	if((error = dlerror()) != NULL) throwError();
	getFibo = dlsym(handle,"getFibo");
	if((error = dlerror()) != NULL) throwError();
	printFibo = dlsym(handle,"printFibo");
	if((error = dlerror()) != NULL) throwError();
	getFiboList = dlsym(handle,"getFiboList");
	if((error = dlerror()) != NULL) throwError();

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
