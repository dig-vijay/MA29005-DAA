#include <stdio.h>
int j=0;
int prod=1;
int mult(int order){
	for(j=0;j<order;j++){
		prod*=2;
	}
}
int A=rand()%mult(32);
int hash(int n,int m,int r, int table[100], int arr[100]){
	int i=0;
	int value=0;
	int count=0;
	for(i=0;i<n;i++){
		int fact=(arr[i]*A)%mult(32)/mult(w-r);
		value=arr[i];
		if (table[(fact+i*(value%m))%m]==-1){
			table[(fact+i*(value%m))%m]=arr[i];	
		}
		else{
			count=1;
			while(table[(fact+i*(value+count)%m)%m]!=-1){
				count++;
			}
			table[(fact+i*(value+count)%m)%m]=arr[i];
		}
	}

}

int main(){
	int n=0;
	int m=0;
	
	int i=0;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter divisor:");
	scanf("%d",&m);
	printf("Enter shift:");
	scanf("%d",&r);
	int table[m];
	
	for(i=0;i<m;i++){
		table[i]=-1;
	}
	hash(n,m,r,table,arr);
	for(i=0;i<m;i++){
		printf("%d\n",table[i]);
	}
	return 0;
}
