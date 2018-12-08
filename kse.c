#include <stdio.h>

void swap(int *a, int *b){															//function for swapping array elements 
	int temp=*a;
	*a=*b;
	*b=temp;
}


int kth_small_elem(int arr[20], int l, int r, int k_i){
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
	if(k_i==i){return arr[k_i];}
	else if(k_i>i){kth_small_elem(arr,i+1,r,k_i);}
	else{kth_small_elem(arr,l,i,k_i);} 
}



int main(){
	int length, array[20],i,k;
	printf("This program returns the kth smallest element in an array.\n");
	printf("Enter length of array:");
	scanf("%d",&length);
	printf("Enter array:");
	for(i=0;i<length;i++){
		scanf("%d",&array[i]);
	}
	printf("Enter k:");
	scanf("%d",&k);
	int res=kth_small_elem(array,0,length,k-1);
	printf("kth smallest element is %d\n",res); 
	return 0;
}
