#include <stdio.h>
int main(){

int A[10];
int len=0;
int i=0;
printf("Enter length:");
scanf("%d",&len);
for (i=0;i<len;i++){
	scanf("%d",&A[i]);
}

printf("Initial array is: ");
for (i=0;i<len;i++){
	printf("%d ",A[i]);}
printf("\n\n");
int pos=0;
int binary(int a[], int x, int l, int r)
{
    if (r <= l){
        if(x>a[l]){
            return l+1;
        }
        else{return l;}
        
    }
 
    int mid = (l + r)/2;
 
    if(x == a[mid])
        return mid+1;
 
    if(x > a[mid])
        return binary(a, x, mid+1, r);
    return binary(a, x, l, mid-1);
}
 
void insertionSort(int a[], int n)
{
    int loc, j, selected;
 
    if (n==0){return;}
    else{
    	insertionSort(a,n-1);
        j = n - 1;
        selected = a[n];
 
        loc = binary(a, selected, 0, j);
 
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
    for (i=0;i<len;i++){
	printf("%d ",a[i]);}
	printf("\n");
    
}

insertionSort(A,len);
printf("\nFinal array:\n");
for (i=0;i<len;i++){
	printf("%d ",A[i]);}
	printf("\n");
printf("\n");
return 0;
}

	
