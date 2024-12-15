#include<malloc.h>
#include<stdio.h>
int getFibo(int a) {
	int x = 0, y = 1, t = 1;
	while (--a) {
		t = x + y;
		x = y;
		y = t;
	}
	return t;
}

int* getFiboList(int a) {
	int x = 0, y = 1, t = 1;
    	int *arr = malloc(a);
	for(int i = 0; i< a; i++){
		arr[i] = t;
        	t = x + y;
		x = y;
		y = t;
	}
	return arr;
}

void printFibo(int a){
	int x = 0, y = 1, t = 1;
	printf("printFibo function : ");
	while (--a) {
		printf("%d ",t);
		t = x + y;
		x = y;
		y = t;
	}
	printf("%d \n",t);
}

