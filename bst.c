#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node node;

node *getNode(int ele){
	node * ptr = (node *)malloc(sizeof(node));
	ptr->data=ele;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}

node *insertNode(node *root, int ele){
	node *newNode = getNode(ele);
	if (root == NULL) return newNode;
	if (root->data > ele) root->left = insertNode(root->left, ele);
	else root->right = insertNode(root->right, ele);
	return root;
}

int search(node *root, int ele){
	if (root == NULL) return -2;
	while (root != NULL){
		if (root->data == ele) return 1;
		if (root->data > ele) root = root->left;
		else root = root->right;
	}
	return -1;
}

int min(node *root){
	while (root->left != NULL) root = root->left;
	return root->data;
}
int max(node *root){
	while (root->right != NULL) root = root->right;
	return root->data;
}

void display(node *root){
	if (root == NULL) return;
	display(root->left);
	printf("%d\t", root->data);
	display(root->right);
}

void main(){
	node *root = NULL;
	int choice, ele;
	while(1){
		printf("\nEnter choice : 1.Insert marks\t2.Display marks\t3.Max marks\t4.Min marks\t5.Search : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("Enter mark - ");
				scanf("%d",&ele);
				root = insertNode(root, ele);
				break;
			case 2 : 
				printf("Marks in ascending order are : \n");
				display(root);
				break;
			case 3 : 
				ele = max(root);
				printf("Max marks is : %d\n", ele);
				break;
			case 4 : 
				ele = min(root);
				printf("Min marks is : %d\n", ele);
				break;
			case 5 : 
				printf("Enter mark to be searched - ");
				scanf("%d",&ele);
				int ans = search(root, ele);
				if (ans == -2) printf("Empty tree\n");
				else if(ans == -1) printf("Does not exist\n");
				else printf("Mark exists\n");
				break;
			default :
				printf("Exiting the prog\n");
				exit(0);
		}
	}
}








