#include <stdio.h>
int r1,r2,r3;
void iter_matmul(int A1[r1][r2], int A2[r2][r3], int R[r1][r3], int a, int b, int c){
int i=0;
int j=0;
int k=0;
for(i=0;i<a;i++){
	for(k=0;k<b;k++){
		R[i][k]=0;
		for(j=0;j<c;j++){
			R[i][k]+=A1[i][j]*A2[j][k];
		}
	}	
}
return ;
}




int main(){

printf("Enter # of rows in first matrix:");
scanf("%d",&r1);
printf("Enter # of columns in first matrix:");
scanf("%d",&r2);
printf("Enter # of columns in second matrix:");
scanf("%d",&r3);
int A[r1][r2];
int B[r2][r3];
int C[r1][r3];
int i,j;
printf("Enter elements of matrix 1\n");
for(i=0;i<r1;i++){
	for(j=0;j<r2;j++){
		scanf("%d",&A[i][j]);
	}
}
printf("Enter elements of matrix 2\n");
for(i=0;i<r2;i++){
	for(j=0;j<r3;j++){
		scanf("%d",&B[i][j]);
	}
}
iter_matmul(A,B,C,r1,r2,r3);
printf("Output is:\n");
for(i=0;i<r1;i++){
	for(j=0;j<r3;j++){
		printf(" %d ",C[i][j]);
	}
	printf("\n");
}
return 0;
}
