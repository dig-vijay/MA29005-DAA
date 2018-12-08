#include <stdio.h>
#include <stdlib.h>
struct elem{
	int val;
	struct elem *next;
};


int hash(int n,int m, struct elem *table, int arr[]){
	int i=0;
	int value=0;
	for(i=0;i<n;i++){
		value=arr[i]%m;
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
	
	int i=0;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter divisor:");
	scanf("%d",&m);
	struct elem *table=(struct elem*)malloc(sizeof(struct elem)*m);
	
	for(i=0;i<m;i++){
		(table+i)->val=-1;
	}
	hash(n,m,table,arr);
	for(i=0;i<m;i++){
		struct elem *point=(table+i);
		while(point!=NULL){
	
			printf("%d\t",point->val);
			point=point->next;	
		}
		printf("\n");
	}
	return 0;
}
