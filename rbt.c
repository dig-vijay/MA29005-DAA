#include <stdio.h>
#include <stdlib.h>

//red-0, black-1

struct node{
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
	int color;
};

struct node * newnode(int data, struct node *p){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=p;
	temp->color=0;
	return temp;
}

void inorder(struct node* root);

struct node * left_rotate(struct node *root, struct node *elem){
	struct node *y=elem->right;
	elem->right=y->left;
	if(y->left!=NULL){
		y->left->parent=elem;
	}
	y->parent=elem->parent;
	if (elem->parent==NULL){
		root=y;
	}
	else if(elem==elem->parent->left){
		elem->parent->left=y;
	}
	else{
		elem->parent->right=y;
	}
	y->left=elem;
	elem->parent=y;
	return root;
}

struct node * right_rotate(struct node *root, struct node *elem){
	struct node *y=elem->left;
	elem->left=y->right;
	if(y->right!=NULL){
		y->right->parent=elem;
	}
	y->parent=elem->parent;
	if (elem->parent==NULL){
		root=y;
	}
	else if(elem==elem->parent->right){
		elem->parent->right=y;
	}
	else{
		elem->parent->left=y;
	}
	y->right=elem;
	elem->parent=y;
	return root;
}

struct node *insert(struct node *root, int data, struct node *p, struct node **mah_node){
	struct node *curr = root, *prev = NULL;
	*mah_node = newnode(data, NULL);

	while(curr != NULL){
		prev = curr;

		if(data < curr->data)curr = curr->left;
		else curr = curr->right;
	}

	(*mah_node)->parent = prev;

	if(prev == NULL){
		return *mah_node;
	}


	if(data < prev->data)prev->left = *mah_node;
	else prev->right = *mah_node;

	return root;
}

struct node * rb_insert(struct node *root, struct node *elem)
{
//	printf("hi \n");
	struct node *y=NULL;
//	printf("elem->data = %d, element->parent = %d\n", elem->data, elem->parent->data);
//	printf("root->data = %d, root->color = %d\n", root->data, root->color);
	while((elem->data!=root->data) && (elem->parent->color==0) ){
		printf("element->parent->color = %d, element->parent->data = %d\n", elem->parent->color, elem->parent->data);
		printf("entered while loop at node->data = %d\n", elem->data);
		if(elem->parent==elem->parent->parent->left){

			printf("entered if\n");
			y=( (elem->parent)->parent)->right;
			if(y != NULL && y->color==0){
				elem->parent->color=1;
				elem->color=1;
				elem->parent->parent->color=0;
				elem=elem->parent->parent;
			
			}
			else{
				if(elem==elem->parent->right){
					elem=elem->parent;
					root=left_rotate(root,elem);
				}
				elem->parent->color=1;
				elem->parent->parent->color=0;
				printf("yo bitch 1. \n");
				inorder(root);printf("\n");
				root=right_rotate(root,elem->parent->parent);
			}
		}
		else{
			y=elem->parent->parent->left;
			if(y->color==0){
				printf("yo bitch 2. \n");
				inorder(root);printf("\n");
				elem->parent->color=1;
				elem->color=1;
				inorder(root); printf("\n");
				elem->parent->parent->color=0;
				elem=elem->parent->parent;
			
			}
			else{
				if(elem==elem->parent->left){
					elem=elem->parent;
					root=right_rotate(root,elem);
				}
				elem->parent->color=1;
				elem->parent->parent->color=0;
				root=left_rotate(root,elem->parent->parent);
			}	
		}
	}
	root->color=1; 
	return root;	
}


void inorder(struct node* root){
	if (root!=NULL){
		inorder(root->left);
		printf(" %d-%d ",root->data,root->color);
		inorder(root->right);
	}
}

int rbt_sort(int arr[], int n){
	int i=0;
	struct node *root=NULL;
	for(i=0;i<n;i++){
		struct node *mah_node = NULL;
		root = insert(root, arr[i], NULL, &mah_node);
		root=rb_insert(root,mah_node);
		inorder(root);
		printf("\n");
	}
	printf("0-red; 1-black\n");
	printf("Sorted elements:");
	inorder(root);
	printf("\n");
}


int main(){
	int n,i;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);	
	}
	rbt_sort(arr,n);
	
	return 0;
}
