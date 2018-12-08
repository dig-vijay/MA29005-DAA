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
	if(left<n && arr[left]<arr[max]){
		max=left;
	}
	if(right<n && arr[right]<arr[max]){
		max=right;
	}
	if (max!=i){
		swap(&arr[max],&arr[i]);
		heapify(arr,n,max);
	}	
}

void min_2(int arr[],int n){
	if (n>2){	
	int i=0;	
	for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(i=n-1;i>=n-3;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
	printf("%d %d\n",arr[n-1],arr[n-2]);
	arr[n-2]=arr[n-1]+arr[n-2];
	min_2(arr,n-1);
	}
	if(n==2){
	int i=0;
		for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(i=n-1;i>=n-4;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
	printf("%d %d\n",arr[n-1],arr[n-3]);
	}
	else{return;}
}
int main(){
	int i=0;
	int arr[100],n;
	printf("Enter number of arrays:");
	scanf("%d",&n);
	printf("Enter sizes of arrays:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	min_2(arr,n);
}
