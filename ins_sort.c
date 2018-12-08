#include <stdio.h>
int main(){

int A[10];
int n=0;
int i=0;
printf("Enter length:");				
scanf("%d",&n);													
for (i=0;i<n;i++){
	scanf("%d",&A[i]);
}

printf("Initial array is: ");
for (i=0;i<n;i++){
	printf("%d ",A[i]);}
printf("\n");
int pos=0;
int Ins_Sort(int A[n]){
	int x=0;
	int y=0;
	for(x=1;x<10;x++){
		int key=A[x];
		pos=x;
		for(y=x-1;y>0;y--){
			if (A[y]>key){
			A[y+1]=A[y];
			pos=y;	
			}
		}
		A[pos]=key;
	
	for (i=0;i<n;i++){
		printf("%d ",A[i]);}
	printf("\n");}
	
	return 0;
}
Ins_Sort(A);
printf("Final array is: ");
for (i=0;i<n;i++){
	printf("%d ",A[i]);}
printf("\n");


return 0;
}

	
