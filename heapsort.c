#include <stdio.h>
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int arr[10], int n,int i){
	int max=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && arr[left]>arr[max]){
		max=left;
	}
	if(right<n && arr[right]>arr[max]){
		max=right;
	}
	if (max!=i){
		swap(&arr[max],&arr[i]);
		heapify(arr,n,max);
	}	
}

void heapsort(int arr[10], int n){
	int i;
	for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(i=n-1;i>=0;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

int main(){
	int arr[100],n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	heapsort(arr,n);
	for(i=0;i<n;i++){
		printf(" %d ",arr[i]);
	}
	printf("\n");
}
