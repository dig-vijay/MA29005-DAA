#include <stdio.h>
#include <stdlib.h>

struct elem{
int i;
int j;
int val;
struct elem *next;
};

void append(struct elem** head_ref, int row, int col, int value){
struct elem* new_elem = (struct elem*) malloc(sizeof(struct elem));
struct elem *last = *head_ref;
new_elem->i=row;
new_elem->j=col;
new_elem->val=value;
new_elem->next=NULL;
if (*head_ref==NULL){*head_ref=new_elem;return;}
while (last->next!=NULL){
last=last->next;
}
last->next=new_elem;
return;
}

struct elem1{
int i;
int j;
int val;
};

void to_ll(struct elem1 *array, struct elem** array2_t){
    int t=array->val;
    int i;
    for(i=1;i<=t;i++){
        append(array2_t,(array+i)->i,(array+i)->j,(array+i)->val);
    }
}

void to_arr(struct elem1 *array, struct elem *array2){
    int i;
    int t=array->val;
    for(i=0;i<=t;i++){
        (array+i)->i=array2->i;
        (array+i)->j=array2->j;
        (array+i)->val=array2->val;
        array2=array2->next;
    }
}

void print(struct elem *array);
void read(struct elem** head_ref);
void multiply(struct elem *array1,struct elem *array2,struct elem *array3);
void transpose(struct elem1 *b1,struct elem1 *b2);
void main()
{
    struct elem* head1=NULL;
    struct elem* head2=NULL;
    struct elem* head3=NULL;
    read(&head1);

    read(&head2);
    multiply(head1,head2,head3);
    printf("1st Array:\n");
    print(head1);
    printf("2nd Array:\n");
    print(head2);
    printf("Result Array:\n");
    print(head3);
}
void multiply(struct elem *array1,struct elem *array2,struct elem *array3)
{        
    struct elem1 *array11 =(struct elem1*) malloc(sizeof(struct elem1)*20);
    to_arr(array11,array2);    
    struct elem1 *array22 =(struct elem1*) malloc(sizeof(struct elem1)*20);
    int i,j,k,row,col;
    int i1,sum,t1,t2;
    t1=array1->val;t2=array2->val;
    transpose(array11,array22);
    struct elem* head2_t=NULL;
    to_ll(array22,&head2_t);
    k=1;       
    i=1;
    while(i<=t1)
    {
        i1=i;
        j=1;
        while(j<=t2)
        {
            row=array1->i;
            col=head2_t->i;
            sum=0;

            while(i<=t1 && j<=t2 && row==array1->i && col==head2_t->i)
            {
                if(array1->j==head2_t->j)
                    {
                    sum=sum+(array1->val)*(head2_t->val);
                    i++;j++;
                    head2_t=head2_t->next;
                    array1=array1->next;
                    }
                else
                {
                    if((array1->j)<(head2_t->j))
                    {
                        i++;
                        array1=array1->next;
                    }
                    else
                    {
                        j++;
                        head2_t=head2_t->next;
                    }               
                }
            }
            if(sum!=0)
            {
                array3->i=row;
                array3->j=col;
                array3->val=sum;
                k++;
                array3=array3->next;
            }
            if(j<=t2)
                {i=i1;}
            while(col==head2_t->i && j<=t2)
                {j++;
                head2_t=head2_t->next;}
        }
        while(row==array1->i && i<=t1)
            i++;
            array1=array1->next;
    }
    array3->i=array1->i;
    array3->j=head2_t->i;;
    array3->val=k-1;
}
void print(struct elem *array)
{
    printf(" i j val \n");
    while (array != NULL)
    {
        printf(" %d %d %d \n", array->i, array->j, array->val);
        array = array->next;
    }
    printf("\n");    
}


void read(struct elem** head_ref)
{
    int k,i,j,t,val,ti,tj;
    printf("\nEnter size of the matrix:");
    scanf("%d%d",&ti,&tj);
    printf("\nEnter no. of non-zero elements:");
    scanf("%d",&t);
    append(head_ref, ti, tj, t);
    for(k=0;k<t;k++){
        printf("\nEnter values:\n");
        scanf("%d%d%d",&i,&j,&val);
        append(head_ref,i,j,val);
    }
    

}


void transpose(struct elem1 *b1,struct elem1 *b2)
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
