#include <stdio.h>

void swap(int *a, int *b){															//function for swapping array elements 
	int temp=*a;
	*a=*b;
	*b=temp;
}


int partition(int arr[20], int l, int r){
	int pivot=arr[l];																//Partitioning the array, essentially finding the right place for 
	int i=l;																		//the pivot element. Returns the final position of pivot.
	int j;
	for(j=l+1;j<r;j++){
		if (arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[l],&arr[i]);
	return i; 
}

void quicksort(int arr[20], int l, int r){
	if(l>=r){
		return;}
	else{
		int pos=partition(arr,l,r);													//Recursively sorting the subarrays to the left and right of pivot.
		quicksort(arr,l,pos);
		quicksort(arr,pos+1,r);
	}
}


int main(){
	int length, array[20],i;
	printf("Enter length of array:");
	scanf("%d",&length);
	printf("Enter array:");
	for(i=0;i<length;i++){
		scanf("%d",&array[i]);
	}
	quicksort(array,0,length);
	for(i=0;i<10;i++){
		printf(" %d ",array[i]);
	}
	return 0;
}
