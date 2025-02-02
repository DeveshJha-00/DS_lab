#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *link;
};
typedef struct Node node;

node *insertRear(node *root, int ele){
	node *newNode =  (node *) malloc(sizeof(node));
	newNode->data = ele;
	newNode->link = NULL;
	if (root == NULL) return newNode;
	node *temp = root;
	while (temp->link != NULL) temp = temp->link;
	temp->link = newNode;
	return root;
}

node *deleteFront(node *root){
	if (root == NULL){
		printf("Empty list\n");
		return root;
	}
	if (root->link == NULL){
		printf("Popped %d\n", root->data);
		free(root);
		return NULL;
	}
	node *temp = root->link;
	printf("Popped %d\t",root->data);
	free(root);
	return temp;
}

void display(node *root){
	if (root == NULL){
		printf("Stack empty!\n");
		return ;
	}
	printf("stack elements are - \n");
	while (root != NULL){
		printf("%d\t", root->data);
		root = root->link;
	}
	printf("\n");
}

void main(){
	int choice, ele;
	node *root = NULL;
	while (1){
		printf("\nEnter choice - 1.Push\t2.Pop\t3.Display : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("Enter ele to be pushed - ");
				scanf("%d", &ele);
				root = insertRear(root,ele);
				break;
			case 2:
				root = deleteFront(root);
				break;
			case 3:
				display(root);
				break;
			default : 
				printf("Exiting prog\n");
				exit(0);
		}
	}
}
