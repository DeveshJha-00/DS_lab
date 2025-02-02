#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct Stack{
	int st[MAX];
	int tos;
};
typedef struct Stack s1;

int isFull(s1 s){
	if (s.tos == (MAX-1)) return 1;
	return 0;
}
void push(s1 *s, int ele){
	if (isFull(*s)){
		printf("Stack overflow!\n");
		return;
	}
	s->tos++;
	s->st[s->tos] = ele;
}

int isEmpty(s1 s){
	if (s.tos == -1) return 1;
	return 0;
}
int pop(s1 *s){
	if (isEmpty(*s)){
		printf("Stack underflow!\n");
		return 999999;
	}
	int ele = s->st[s->tos];
	s->tos--;
	return ele;
}

void display(s1 s){
	if (isEmpty(s)){
		printf("Stack is empty!\n");
		return;
	}
	for (int i=0; i<=s.tos; i++) printf("%d\t", s.st[i]);
	printf("\n");
}

int isPalin(char str[]){
	s1 s;
	s.tos=-1;
	int length = strlen(str);
	int i;
	for (i=0; i<length/2; i++) push(&s, str[i]-'0');
	if (length%2 != 0) i++;
	while (str[i] != '\0'){
		if ( (str[i]-'0') != pop(&s)) return 0;
		i++;
	}
	return 1;
}

void main(){
	int ele, choice;
	s1 stack;
	stack.tos=-1;
	while (1){
		printf("\nEnter choice - 1.Push\t2.Pop\t3.Display\t4.Check Palindrome\t5.Exit : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
			printf("Enter ele - ");
			scanf("%d",&ele);
			push(&stack, ele);
			break;
			case 2:
			ele = pop(&stack);
			if (ele==99999) printf("Empty stack\n");
			else printf("Popped ele is %d\n", ele);
			break;
			case 3 : 
			display(stack);
			break;
			case 4:
			char str[MAX];
			printf("Enter the string u need to check - ");
			scanf("%s", str);
			if (isPalin(str)) printf("Its a palindrome!\n");
			else printf("Not a palindrome!\n");
			break;
			default : 
			printf("Exiting program\n");
			exit(0);
		}
	}
}























