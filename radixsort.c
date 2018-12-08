#include <stdio.h>

int max1(int arr[], int n){
	int i=0;
	int arr1[n];	
	int max=0;
	for(i=0;i<n;i++){
		arr1[i]=arr[i]%10;
	}	
	for(i=0;i<n;i++){
		if(arr1[i]>max){
			max=arr1[i];		
		}
	}
	return max;
}
int max2(int arr1[], int n){
	int i=0;	
	int max=0;	
	for(i=0;i<n;i++){
		if(arr1[i]>max){
			max=arr1[i];		
		}
	}
	return max;
}
int min1(int arr[], int n){
	int i=0;
	int arr1[n];
	int min=arr[0];	
	for(i=0;i<n;i++){
		arr1[i]=arr[i]%10;
	}
	for(i=0;i<n;i++){
		if(arr1[i]<min){
			min=arr1[i];		
		}
	}
	return min;
}

void countsort(int arr[], int len,int exp){
	int min=min1(arr,len);
	int max=max1(arr,len);
	int len_count=max-min+1;
	int count[len_count];
	int final[len];
	int i=0;	
	int j=0;	
	for(i=0;i<len_count;i++){
		count[i]=0;
	}
	for(j=0;j<len;j++){
		count[(arr[j]/exp)%10]++;			
	}
	
	for(i=1;i<len_count;i++){
		count[i]=count[i]+count[i-1];
	}
	
	for(j=len-1;j>=0;j--){
		final[count[(arr[j]/exp)%10]-1]=arr[j];
		count[(arr[j]/exp)%10]--;			
	}
	for(i=0;i<len;i++){
		arr[i]=final[i];
	}
	
}

void radixsort(int arr[], int len){
	int max=max2(arr,len);
	int exp,i;
	for(exp=1;max/exp>0;exp*=10){
		countsort(arr,len,exp);
		
	}
	for(i=0;i<5;i++){
		printf(" %d ",arr[i]);
	}
	printf("\n");
}


int main(){
	int len=0;
	printf("Enter length of array");
	scanf("%d",&len);
	int i;
	int arr[len];
	printf("Enter array elements");
	for(i=0;i<len;i++){
		scanf("%d",&arr[i]);
	}
	
	radixsort(arr,len);
	
}
