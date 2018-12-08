#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[100000000], int l, int m, int r){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1], R[n2];
	for(i=0;i<n1;i++){
		L[i]=arr[l+i];
	}
	for(j=0;j<n2;j++){
		R[j]=arr[m+j+1];
	}
	i=0;
	j=0;
	k=l;
	while (i<n1 && j<n2){
		if (L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
	return ;
}

void mergesort(int arr[1000000], int l, int r){
	if (l<r){
		int m=l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
	return ;
}

void Ins_Sort(int A[1000000],int n){
	int x=0;
	int y=0;
	int pos=0;
	for(x=1;x<n;x++){
		int key=A[x];
		pos=x;
		for(y=x-1;y>0;y--){
			if (A[y]>key){
			A[y+1]=A[y];
			pos=y;	
			}
		}
		A[pos]=key;
	}	
	return ;
}

int main(){
int n[4]={10,100,1000,10000};
int size=0;
int index=0;
int val=0;
clock_t t_merge;
clock_t t_ins;
int k=0;
int array1[1000000];
int array2[1000000];
double t_mer,t_in;
printf("Size\tMergeTime\tInsTme");
for(size=0;size<4;size++){
for(index=0;index<n[size];index++){
val=rand()%100;
array1[index]=val;
array2[index]=val;
}
printf("\n");

t_merge=clock();
mergesort(array1,0,n[size]-1);
t_merge=clock()-t_merge;
t_mer=(double) t_merge;


t_ins=clock();
Ins_Sort(array2,n[size]);
t_ins=clock()-t_ins;
t_in=(double) t_ins;
printf("\n%d\t%f\t%f",n[size], t_mer, t_in);
}
printf("\n");
return 0;
}
