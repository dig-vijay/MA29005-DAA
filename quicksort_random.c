#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;																
	*b=temp;
}

int maxf(int arr[20],int l,int r){
	int ind,max;
	max=arr[l];
	for(ind=l;ind<r;ind++){
		if (arr[ind]>max){
			max=arr[ind];}
	}
	return max;
}

int minf(int arr[20],int l,int r){
	int ind,min;
	min=arr[r-1];
	for(ind=l;ind<r;ind++){
		if (arr[ind]<min){
			min=arr[ind];}
	}
	return min;
}

int secondmaxf(int arr[20], int l, int r){
	int ind,max,max_ind;
	max=maxf(arr,l,r);
	int arr1[20];
	for(ind=l;ind<r;ind++){
		arr1[ind]=arr[ind];
		if (arr[ind]==max){max_ind=ind;}
	}
	swap(&arr[r-1],&arr[max_ind]);
	max=arr[l];
	for(ind=l;ind<r-1;ind++){
		if (arr[ind]>max){max=arr[ind];}	
	}
	return max;
}

int secondminf(int arr[20], int l, int r){
	int ind,min,min_ind;
	min=minf(arr,l,r);
	int arr1[20];
	for(ind=l;ind<r;ind++){
		arr1[ind]=arr[ind];
		if (arr[ind]==min){min_ind=ind;}
	}
	swap(&arr[r-1],&arr[min_ind]);
	min=arr[r-2];
	for(ind=l;ind<r-1;ind++){
		if (arr[ind]>min){min=arr[ind];}	
	}
	return min;
}


int partition(int arr[20], int l, int r){
	int max,min,max2,min2;
	max=maxf(arr,l,r);
	min=minf(arr,l,r);
	max2=secondmaxf(arr,l,r);
	min2=secondminf(arr,l,r);
	int pivot_index=l+rand()%(r-l);
	if (r-l>4){
		while (arr[pivot_index]==max || arr[pivot_index]==min || arr[pivot_index]==min2 || arr[pivot_index]==max2){
			pivot_index=l+rand()%(r-l);
		}
	}													
	swap(&arr[pivot_index],&arr[l]);									
	int pivot=arr[l];
	int i=l;
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
		int pos=partition(arr,l,r);										
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
