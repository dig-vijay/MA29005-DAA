#include <stdio.h>

int max1(int arr[], int n){
	int i=0;
	int max=0;	
	for(i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];		
		}
	}
	return max;
}

int min1(int arr[], int n){
	int i=0;
	int min=0;	
	for(i=0;i<n;i++){
		if(arr[i]<min){
			min=arr[i];		
		}
	}
	return min;
}

void countsort(int arr[], int len){
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
		count[arr[j]]++;			
	}
	
	for(i=1;i<len_count;i++){
		count[i]=count[i]+count[i-1];
	}
	
	for(j=len;j>=0;j--){
		final[count[arr[j]]-1]=arr[j];
		count[arr[j]]--;			
	}
	for(i=0;i<len;i++){
		printf(" %d ",final[i]);
	}
	
}



int main(){
	
	int arr[11]={5,4,3,2,0,1,4,1,2,3,8};
	countsort(arr,11);
	printf("\n");
}
