#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *left, *right;
};

struct node *newnode(int item){
	struct node *temp= (struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}

void max_heapify(struct node *node,int n, int largest){
	struct node *l=node->left;
	struct node *r=node->right;
	if(l<=n && l->key>node->key){

	}
}