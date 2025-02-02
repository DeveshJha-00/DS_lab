#include <stdio.h>

int fib(int n){
	if (n==0) return 0;
	if (n==1) return 1;
	return (fib(n-1) + fib(n-2));
}

void main(){
	int limit;
	printf("Enter the no. of terms needed in the fibonacci series - ");
	scanf("%d", &limit);
	for (int i=0; i<limit; i++){
		printf("%d\t", fib(i));
	}
	printf("\n");
}
