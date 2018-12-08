#include <stdio.h>
struct student
{
 char name;
 int roll_no;
 float cgpa;

};
struct student a[100];

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int arr[10], int n,int i){
	int max=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && arr[left]>arr[max]){
		max=left;
	}
	if(right<n && arr[right]>arr[max]){
		max=right;
	}
	if (max!=i){
		swap(&arr[max],&arr[i]);
		heapify(arr,n,max);
	}	
}


int main()
{
 int n,j,i,k;
 printf("Enter no. of students : ");
 scanf("%d",&n);
 for(j=0;j<n;j++)
{

 printf("Enter Name :");
 scanf("%d",&k);
 scanf("%c",&a[j].name);
 printf("Enter roll :");
 scanf("%d",&a[j].roll_no);
 printf("Enter CGPA :");
 scanf("%f",&a[j].cgpa);
}

 int A[n];
 for(j=0;j<n;j++)
 A[j]=a[j].cgpa;
 for(i=n/2;i>=0;i--)
{
 heapify(A,n,i);
}
 for(j=0;j<n;j++)
 {
  if(a[j].cgpa==A[0])
  printf("Name:%c\nRoll no.:%d\nCGPA:%f\n",a[j].name,a[j].roll_no,a[j].cgpa);

 }

}
