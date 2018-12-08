#include <stdio.h>

void swap(int *a, int *b){															
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[100], int l, int r, int pivot){
	swap(&arr[pivot],&arr[l]);	
	pivot=arr[l];																
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


int median(int arr[], int l, int r, int k_i){
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
	if(k_i==i){return k_i;}
	else if(k_i>i){median(arr,i+1,r,k_i);}
	else{median(arr,l,i,k_i);} 
}



int select(int arr[], int len){
	if(len>5){
		int i=0;
		for(i=0;i<(len/5);i++){
			median(arr,i*5,(i+1)*5,2+5*i);
		}
		for(i=0;i<(len/5);i++){
			swap(&arr[i],&arr[2+5*i]);
		}
		select(arr,len/5);
	}
	else{
		return median(arr,0,len,len/2);
	}
}

int ise(int arr[], int p, int r, int i){
	if(p==r){return arr[p];}
	int x=select(arr,r-p);
	int q=partition(arr,p,r,x);
	int k=q-p+1;
	if(i==k){return q;}
	else if(i<k){return ise(arr,p,q-1,i);}
	else{ise(arr,q+1,r,i-k);}
}


int main(){
	int array[100];
	int len=0;
	printf("Enter number of elements:");
	scanf("%d",&len);
	int i=0;
	printf("Enter values:");
	for(i=0;i<len;i++){
		scanf("%d",&array[i]);
	}
	printf("Enter i value:");
	int pos=0;
	scanf("%d",&pos);
	printf("ith smallest element is:");
	printf("%d\n",ise(array,0,len,pos+1));
}
