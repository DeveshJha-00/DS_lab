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
	ptr->link=NULL;
	return ptr;
}
node *insertFront(node *root, int ele){
	node *newNode = getNode(ele);
	if (root == NULL) return newNode;
	newNode->link = root;
	root = newNode;
	return root;
}
node *deleteFront(node *root){
	if (root == NULL){
		printf("Empty list");
		return root;
	}
	if (root->link == NULL){
		printf("Deleted %d\n", root->data);
		free(root);
		return NULL;
	}
	node *temp = root;
	root = root->link;
	printf("Deleted %d\n", temp->data);
	free(temp);
	return root;
}

node *insertRear(node *root, int ele){
	node *newNode = getNode(ele);
	if (root == NULL) return newNode;
	node *temp = root;
	while (temp->link != NULL) temp = temp->link; //temp will become last ele of the list
	temp->link=newNode;
	return root;
}
node *deleteRear(node *root){
	if (root == NULL){
		printf("Empty list");
		return root;
	}
	if (root->link == NULL){
		printf("Deleted %d\n", root->data);
		free(root);
		return NULL;
	}
	node *prev;
	node *temp = root;
	while (temp->link != NULL){
		prev = temp;
		temp = temp->link;
	}
	printf("Deleted %d\n", temp->data);
	free(temp);
	prev->link=NULL;
	return root;
}
void display(node *root){
	if (root == NULL){
		printf("Empty list");
		return;
	}
	while (root != NULL){
		printf("%d\t", root->data);
		root = root->link;
	}
	printf("\n");
}

int search(node *root, int ele){
	if (root == NULL){
		printf("Empty list");
		return -2;
	}
	int ctr=0;
	while (root != NULL){
		ctr++;
		if (root->data == ele) return ctr;
		root = root->link;
	}
	if (root == NULL) return -1;
}

void main(){
	node *root = NULL;
	int choice, ele;
	while (1){
		printf("\nEnter choice - 1.Insert Front\t2.Delete Front\t3.Insert Rear\t4.DeleteRear\t5.Display\t6.Search : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter ele - ");
				scanf("%d", &ele);
				root = insertFront(root,ele);
				break;
			case 2:
				root = deleteFront(root);
				break;
			case 3 :
				printf("Enter ele - ");
				scanf("%d",&ele);
				root = insertRear(root,ele);
				break;
			case 4 : 
				root = deleteRear(root);
				break;
			case 5 : 
				display(root);
				break;
			case 6 : 
				printf("Enter ele to be searched - ");
				scanf("%d",&ele);
				int ans = search(root,ele);
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















