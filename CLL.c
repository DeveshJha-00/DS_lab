#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *link;
};
typedef struct Node node;

node *getNode(int ele){
	node *ptr = (node *)malloc(sizeof(node));
	ptr->data=ele;
	ptr->link=ptr;
	return ptr;
}
node *insertFront(node *last, int ele){
	node *newNode = getNode(ele);
	if (last == NULL)  return newNode;

	newNode->link = last->link;
	last->link = newNode;
	return last;
}
node *deleteFront(node *last){
	if (last == NULL){
		printf("Empty list");
		return last;
	}
	if (last->link == last){
		printf("Deleted %d\n", last->data);
		free(last);
		return NULL;
	}
	node *front = last->link;
	last->link = front->link;
	printf("Deleted %d\n", front->data);
	free(front);
	return last;
}

node *insertRear(node *last, int ele){
	node *newNode = getNode(ele);
	if (last == NULL) return newNode;
	
	newNode->link = last->link;
	last->link = newNode;
	last = newNode;
	return last;
}
node *deleteRear(node *last){
	if (last == NULL){
		printf("Empty list");
		return last;
	}
	if (last->link == last){
		printf("Deleted %d\n", last->data);
		free(last);
		return NULL;
	}
	node *front = last->link;
	while (front->link != last) front = front->link; //front will stop at 2nd-last ele
	front->link = last->link; //link 2nd-last ele to first ele
	printf("Deleted %d\n", last->data); //delete last ele
	free(last);
	last = front; //make 2nd last as new last ele
	return last;
}
void display(node *last){
	if (last == NULL){
		printf("Empty list");
		return;
	}
	node *front = last->link;
	do{
		printf("%d\t", front->data);
		front= front->link;
	}while(front != last->link);
	
	printf("\n");
}

int search(node *last, int ele){
	if (last == NULL){
		printf("Empty list");
		return -2;
	}
	int ctr=0;
	node *front = last->link;
	
	do{
		ctr++;
		if (front->data == ele) return ctr;
		front = front->link;
	}while (front != last->link);
	
	return -1;
}

void main(){
	node *last = NULL;
	int choice, ele;
	while (1){
		printf("\nEnter choice - 1.Insert Front\t2.Delete Front\t3.Insert Rear\t4.DeleteRear\t5.Display\t6.Search : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter ele - ");
				scanf("%d", &ele);
				last = insertFront(last,ele);
				break;
			case 2:
				last = deleteFront(last);
				break;
			case 3 :
				printf("Enter ele - ");
				scanf("%d",&ele);
				last = insertRear(last,ele);
				break;
			case 4 : 
				last = deleteRear(last);
				break;
			case 5 : 
				display(last);
				break;
			case 6 : 
				printf("Enter ele to be searched - ");
				scanf("%d",&ele);
				int ans = search(last,ele);
				if (ans == -2) printf("Empty list\n");
				else if (ans == -1) printf("%d not in list\n", ele);
				else printf("%d at %d position\n", ele, ans);
				break;
			default : 
				printf("Exiting from prog\n");
				exit(0);
		}
	}
}
