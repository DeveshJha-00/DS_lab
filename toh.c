#include <stdio.h>

void toh(int n, char src, char helper, char dest){
	if (n==0) return;
	toh(n-1, src, dest, helper);
	printf("Disc %d transferred from %c to %c\n",n ,src, dest);
	toh(n-1, helper, src, dest);
}

void main(){
	int n;
	printf("Enter no. of discs - ");
	scanf("%d", &n);
	toh(n,'A', 'B','C');
}
