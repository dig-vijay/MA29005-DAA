#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int*a, int*b){															//function for swapping array elements 
	int temp=*a;
	*a=*b;
	*b=temp;
}

int maxf(int arr[20],int l,int r){
	int ind,max;
	int maxind=l;
	max=arr[l];
	for(ind = l;ind < r; ind++ ){
		if (arr[ind]>max){
			maxind=ind;}
	}
	return maxind;
}

int median(int arr[20], int l, int r, int k_i){
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
	if(k_i==i){return k_i;}
	else if(k_i>i){median(arr,i+1,r,k_i);}
	else{median(arr,l,i,k_i);} 
}

int partition(int arr[20], int l, int r){
	int pivot_index=maxf(arr,l,r);													
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

void quicksort(int arr[20], int l, int r,int flag){
	if(l>=r){
		return;
	}
	else{
		int pos=0;
		if(flag==0){
			pos=median(arr,l,r,l+(r-l)/2);
			flag=1;
		}
		else{
			pos=partition(arr,l,r);
			flag=0;
		}
	
		quicksort(arr,l,pos,flag);
		quicksort(arr,pos+1,r,flag);
		
	}
	
}

int partition1(int arr[20], int l, int r){
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

void quicksort1(int arr[20], int l, int r){
	if(l>=r){
		return;}
	else{
		int pos=partition1(arr,l,r);													//Recursively sorting the subarrays to the left and right of pivot.
		quicksort1(arr,l,pos);
		quicksort1(arr,pos+1,r);
	}
}


int main(){
	int n[4]={10,100,1000,10000};
	int k=0;
	int array1[1000000];
	int array2[1000000];
	clock_t t_alt;
	clock_t t_norm;
	int size=0;
	int index=0;
	int val=0;
	double t_al,t_n;
	printf("Size\tNormalTime\tAlternateTme");
	for(size=0;size<4;size++){
		for(index=0;index<n[size];index++){
			val=rand()%100;
			array1[index]=val;
			array2[index]=val;
		}
	printf("\n");

	t_alt=clock();
	quicksort(array1,0,n[size],0);
	t_alt=clock()-t_alt;
	t_al=(double) t_alt;


	t_norm=clock();
	quicksort1(array2,0,n[size]);
	t_norm=clock()-t_norm;
	t_n=(double) t_norm;
	printf("\n%d\t%f\t%f",n[size], t_al, t_n);
	}
	printf("\n");

	return 0;
}
