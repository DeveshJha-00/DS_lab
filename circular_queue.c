#include <stdio.h>
#include <stdlib.h>
#define max 5

struct Queue{
    char items[max];
    int front, rear;
};
typedef struct Queue Q;

int isFull(Q q){
    return ((q.rear+1)%max == q.front);
}
int isEmpty(Q q){
    return (q.rear==-1 && q.front==-1);
}
void enQueue(Q *q, char ele){
    if (isFull(*q)) {
        printf("Full queue\n");
        return;
    }
    if (isEmpty(*q)){
        q->front=0;
        q->rear++;
        q->items[q->rear] = ele;
        return;
    }
    q->rear = (q->rear+1)%max;
    q->items[q->rear] = ele;
}
char deQueue(Q *q){
    if (isEmpty(*q)){
        printf("Empty queue\n");
        return '\0';
    }
    if (q->rear == q->front){
        char ele = q->items[q->front];
        q->front=-1;
        q->rear=-1;
        return ele;
    }
    char ele = q->items[q->front];
    q->front = (q->front+1)%max;
    return ele;
}
void display(Q *q){
    if (isEmpty(*q)){
        printf("Empty queue\n");
        return;
    }
    for (int i=q->front; i<=q->rear; i++) printf("%c\t", q->items[i]);
    printf("\n");
}

void main(){
    Q q1;
    q1.front=-1;
    q1.rear=-1;
    int choice;
    char ch;
    while(1){
        printf("\nEnter choice - 1.enQueue\t2.deQueue\t3.Display : ");
        scanf("%d", &choice);
        switch(choice){
            case 1 : 
                printf("Enter ele - ");
                scanf(" %c",&ch);
                enQueue(&q1, ch);
                break;
            case 2 :
                ch = deQueue(&q1);
                if (ch == '\0') printf("Empty queue\n");
                else printf("Deleted %c\n", ch);
                break;
            case 3 : 
                display(&q1);
                break;
            default : 
                printf("\nExiting prog");
                exit(0);
        }
    }
}





