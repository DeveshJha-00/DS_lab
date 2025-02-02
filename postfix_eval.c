#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define max 30

struct Stack{
    double st[max];
    int tos;
};
typedef struct Stack s1;

int isFull(s1 s){
    return (s.tos == (max-1));
}
int isEmpty(s1 s) {
    return (s.tos==-1);
}
void push(s1 *s, int ele){
    if (isFull(*s)) printf("Stack overflow!\n");
    else s->st[++s->tos] = ele;
}
double pop(s1 *s){
    if (isEmpty(*s)) return 99999;
    return s->st[s->tos--];
}

double operation(double op1, char symb, double op2){
    switch(symb){
        case '+' : return op1+op2;
        case '-' : return op1-op2;
        case '*' : return op1*op2;
        case '/' :if (op2==0){
				printf("Invalid\n");
				exit(0);
        }
        return op1/op2;
        case '$' :
        case '^' : return (pow(op1,op2));
        default : exit(0);
    }
}

double postfix_eval(char postfix[]){
    s1 s;
    s.tos=-1;
    for (int i=0; i<strlen(postfix); i++){
        char symb = postfix[i];
        if (isdigit(symb)) push(&s, symb-'0');
        else{
            double op2 = pop(&s);
            double op1=pop(&s);
            double res = operation(op1,symb,op2);
            push(&s, res);
        }
    }
    return pop(&s);
}

void main(){
    char postfix[max];
    printf("Enter postfix exp - ");
    scanf("%s", postfix);
    printf("Evaluated ans is - %lf\n", postfix_eval(postfix));
}

// compile --> cc prog.c -lm

