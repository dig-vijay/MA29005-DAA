#include <stdio.h>
#include <stdlib.h>

struct elem{
int i;
int j;
int val;
};


void print(struct elem *array);
void read(struct elem *b);
void multiply(struct elem *array1,struct elem *array2,struct elem *array3);
void transpose(struct elem *b1,struct elem *b2);
void main()
{
    struct elem *array1 =(struct elem*) malloc(sizeof(struct elem)*20);
    struct elem *array2 =(struct elem*) malloc(sizeof(struct elem)*20);
    struct elem *array3 =(struct elem*) malloc(sizeof(struct elem)*20);
    read(array1);

    read(array2);
    multiply(array1,array2,array3);
    printf("1st Array:\n");
    print(array1);
    printf("2nd Array:\n");
    print(array2);
    printf("Result Array:\n");
    print(array3);
}
void multiply(struct elem *array1,struct elem *array2,struct elem *array3)
{        
    struct elem *array22 =(struct elem*) malloc(sizeof(struct elem)*20);
    int i,j,k,row,col;
    int i1,sum,t1,t2;
    t1=array1->val;t2=array2->val;
    transpose(array2,array22);
    k=1;       
    i=1;
    while(i<=t1)
    {
        i1=i;
        j=1;
        while(j<=t2)
        {
            row=(array1+i)->i;
            col=(array22+j)->i;
            sum=0;

        while(i<=t1 && j<=t2 && row==(array1+i)->i && col==(array22+j)->i)
        {
            if((array1+i)->j==(array22+j)->j)
                {
                sum=sum+((array1+i)->val)*((array22+j)->val);
                i++;j++;
                }
            else
                if(((array1+i)->j)<((array22+j)->j))
                    i++;
                else
                    j++;
        }
        if(sum!=0)
        {
            (array3+k)->i=row;
            (array3+k)->j=col;
            (array3+k)->val=sum;
            k++;
        }
        if(j<=t2)
            i=i1;
        while(col==((array22+j)->i) && j<=t2)
            j++;
    }
    while(row==((array1+i)->i) && i<=t1)
        i++;
    }
    (array3)->i=(array1)->i;
    (array3)->j=(array22)->i;;
    array3->val=k-1;
}
void print(struct elem *array)
{
    int i,n;
    n=array->val;
    printf("i\tj\tvalue\n");  
    printf("\n");
    for(i=1;i<=n;i++)
        printf("%d\t%d\t%d\n",(array+i)->i,(array+i)->j,(array+i)->val);
}
void read(struct elem *b)
{
    int i,t;
    printf("\nEnter size of the matrix:");
    scanf("%d%d",&(b->i),&(b->j));
    printf("\nEnter no. of non-zero elements:");
    scanf("%d",&t);

    b->val=t;

    for(i=1;i<=t;i++)
    {
        printf("\n Enter the next triple(row,column,value) :");
        scanf("%d%d%d",&((b+i)->i),&((b+i)->j),&((b+i)->val));
    }
}
void transpose(struct elem *b1,struct elem *b2)
{
    int m,n,t,i,col,h;
    int total[20],index[20];
    m=b1->i;n=b1->j;t=b1->val;
    b2->i=n;b2->j=m;b2->val=t;
    for(i=0;i<n;i++)
        total[i]=0;
    for(i=1;i<=t;i++)
    {
        col=((b1+i)->j);
        total[col]++;
    }
    index[0]=1;
    for(i=1;i<n;i++)
        index[i]=index[i-1]+total[i-1];

    for(i=1;i<=t;i++)
    {
        col=(b1+i)->j;
        h=index[col];
        index[col]++;
        (b2+h)->i=(b1+i)->j;
        (b2+h)->j=(b1+i)->i;
        (b2+h)->val=(b1+i)->val;
    }
} 