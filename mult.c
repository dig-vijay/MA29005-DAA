#include <stdio.h>
#include <stdlib.h>
struct elem{
	int val;
	struct elem *next;
};
int j=0;
int prod=1;
int mult(int order){
	for(j=0;j<order;j++){
		prod*=2;
	}
}
int A=rand()%mult(32);

int hash(int n,int r, struct elem *table, int arr[]){
	int i=0;
	int value=0;
	for(i=0;i<n;i++){
		value=(arr[i]*A)%mult(32)/mult(w-r);
		struct elem *point=(table+value);
		if (point->val==-1){
			point->val=arr[i];
			point->next=NULL;	
		}
		else{
			struct elem *newnode=(struct elem*)malloc(sizeof(struct elem));
			struct elem *temp=point->next;
			point->next=newnode;
			newnode->next=temp;
			
			newnode->val=arr[i];
			
		}	
	}
}

int main(){
	int n=0;
	int m=0;
	int r=0;
	int i=0;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter shift:");
	scanf("%d",&r);
	struct elem *table=(struct elem*)malloc(sizeof(struct elem)*11);
	int i=0;
	for(i=0;i<m;i++){
		(table+i)->val=-1;
	}
	hash(n,r,table,arr);
	struct elem *point=(table+1);
	
	while(point!=NULL){
	
		printf("%d\n",point->val);
		point=point->next;	
	}
	return 0;
}
