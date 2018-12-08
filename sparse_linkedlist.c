#include <stdio.h>
#include <stdlib.h>
struct elem{
	int i;
	int j;
	int data;
	struct elem *next;
};
int search(struct elem *A,int order,int i,int j)
{	
	int k;
	struct elem *s;
	s=A;
	for(k=0;k<order;k++)
	{
		if(s->i==i && s->j==j) return s->data;
		s=s->next;
	}
	return 0;
}
int main()
{
	int i=0,j=0,k=0,l=0,n=0,a=0,b=0,n1=0,n2=0,r1=0,c1=0,d1=0;
	struct elem *temp3,*temp2,*temp1,*A=NULL,*B=NULL,*C=NULL;
	struct elem *p,*q,*r;
	printf("Enter the order of the matrices:");
	scanf("%d",&n);	
	printf("Enter the no. of non-zero elements in the matrix 1:");
	scanf("%d",&a);
	printf("Enter the no. of non-zero elements in the matrix 2:");
	scanf("%d",&b);
	printf("Enter the non-zero elements of matrix 1\n");
	for(i=0;i<a;i++){
		p=(struct elem*)malloc(sizeof(struct elem));
		printf("Enter the row,column and value of the element:");
		scanf("%d%d%d",&r1,&c1,&d1);
		p->i = r1;
		p->j = c1;
		p->data = d1;
		if(A==NULL) A=p;
		else temp1->next=p;
		temp1=p;
	}
	printf("Enter the non-zero elements of matrix 2\n");
	for(i=0;i<b;i++){
		q=(struct elem*)malloc(sizeof(struct elem));
		printf("Enter the i,jumn and elem of the element:");
		scanf("%d%d%d",&r1,&c1,&d1);
		q->i = r1;
		q->j = c1;
		q->data = d1;
		if(B==NULL) B=q;
		else temp2->next=q;
		temp2=q;
	}
	p=A;
	q=B;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			r=(struct elem*)malloc(sizeof(struct elem));	
			r->i=i;
			r->j=j;
			r->data=0;
			p=A;
			n1=0;
			for(k=0;k<a;k++)
			{
				if(p->data!=0) n1++;
			}
			q=B;
			for(k=0;k<b;k++)
			{
				if(q->data!=0) n2++;
			}
			if(n1!=0 && n2!=0)
			{
				for(l=0;l<n;l++)
				{				
					r->data = r->data + (search(A,a,i,l))*(search(B,b,l,j));
				}
			}
			r->next=NULL;
			if(C==NULL) C=r;
			else temp3->next=r;
			temp3=r;
		}
	}
	r=C;
	printf("i j value\n");
	for(i=0;i<n*n;i++)
	{
		if(r->data!=0){
			printf("%d %d %d\n",r->i,r->j,r->data);
		}
			r=r->next;
	}
	return 0;
}






























