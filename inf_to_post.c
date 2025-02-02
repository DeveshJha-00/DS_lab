#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 30

struct Stack{
    char st[max];
    int tos;
};
typedef struct Stack s1;

int isFull(s1 s){
    return (s.tos == (max-1));
}
int isEmpty(s1 s) {
    return (s.tos==-1);
}
void push(s1 *s, char ele){
    if (isFull(*s)) printf("Stack overflow!\n");
    else s->st[++s->tos] = ele;
}
char pop(s1 *s){
    if (isEmpty(*s)) return '\0';
    return s->st[s->tos--];
}
int inp_prec(char symb){
    switch(symb){
        case '+': 
        case '-' : return 1;
        case '*' : 
        case '/' : return 3;
        case '^' : 
        case '$' : return 6;
        case '(' : return 9;
        case ')' : return 0;
    }
}
int stack_prec(char symb){
    switch(symb){
        case '+': 
        case '-' : return 2;
        case '*' : 
        case '/' : return 4;
        case '^' : 
        case '$' : return 5;
        case '(' : return 0;
        case '#' : return -1;
    }
}

void inf_to_post(char infix[], char postfix[]){
    s1 s;
    s.tos=-1;
    push(&s, '#');
    int i,j=0;
    for (i=0; i<strlen(infix); i++){
        char symb=infix[i];
        if (isalpha(symb)) postfix[j++]=symb;
        else{
            while (inp_prec(symb) < stack_prec(s.st[s.tos])) postfix[j++]=pop(&s);
            if (inp_prec(symb) != stack_prec(s.st[s.tos])) push(&s, symb);
            else pop(&s);
        }
    }
    while (s.st[s.tos] != '#') postfix[j++] = pop(&s);
    postfix[j]='\0';
}

int main()
{
    char infix[max], postfix[max];
    printf("Enter exp - ");
    scanf("%s", infix);
    inf_to_post(infix,postfix);
    printf("Postfix : %s\n", postfix);
    return 0;
}
