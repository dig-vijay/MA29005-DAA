#include <stdio.h>

int hash(int n,int m, int table[100], int arr[100]){
	int i=0;
	int value=0;
	int count=0;
	for(i=0;i<n;i++){
		value=arr[i];
		if (table[value%m]==-1){
			table[value%m]=arr[i];	
		}
		else{
			count=1;
			while(table[(value+count)%m]!=-1){
				count++;
			}
			table[(value+count)%m]=arr[i];
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
	int table[m];
	
	for(i=0;i<m;i++){
		table[i]=-1;
	}
	hash(n,m,table,arr);
	for(i=0;i<m;i++){
		printf("%d\n",table[i]);
	}
	return 0;
}
