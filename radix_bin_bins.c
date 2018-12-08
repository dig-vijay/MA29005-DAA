#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int power(int base, int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

int value(char *s,int start, int end,int bin){
	int i,j;
	int sum=0;
	int x=end-1;
	for(j=end-1;j>=start;j--){
		sum+=(s[j]-'0')*power(2,j-x);
	}
	return sum;
}

void append(char* s)
{
        int len = strlen(s);
        s[len] = '0';
        s[len+1] = '\0';
}


void reverse(char *s) {
    int i, j;
    char temp;

    for (i=0,j = (strlen(s)-1); i < j; i++, j--) {
        temp = *(s+i);     
        *(s+i) = *(s+j);   
        *(s+j) = temp;     
    }
}


void countsort(char **arr, int len,int index,int bin){
	int count[power(2,bin)];
	char *final[100];
	int i=0;		
	for(i=0;i<power(2,bin);i++){
		count[i]=0;			
	}
	for(i=0;i<len;i++){
		count[value(arr[i],index*bin,(index+1)*bin,bin)]++;			
	}
	
	for(i=1;i<power(2,bin);i++){
		count[i]=count[i]+count[i-1];
	}
	
	for(i=len-1;i>=0;i--){
		final[count[value(arr[i],index*bin,(index+1)*bin,bin)]-1]=arr[i];
		count[value(arr[i],index*bin,(index+1)*bin,bin)]--;	

	}
	printf("\n");
	for(i=0;i<len;i++){
		arr[i]=final[i];
	}
	
}





void convert(char **arr,int len, int bin){
	int i,j,max_len;
	char temp;
	max_len=strlen(arr[0]);
	for(i=0;i<len;i++){
		if(strlen(arr[i])>max_len){
			max_len=strlen(arr[i]);
		}
	}
	max_len+=(bin-max_len%bin);
	for(i=0;i<len;i++){
		char *str=strdup(arr[i]);
		reverse(str);
		while(strlen(str)<max_len){
			append(str);
		}
		arr[i]=str;
		
	}
	for(i=0;i<(max_len/bin);i++){
		countsort(arr,len,i,bin);
	}
	for(i=0;i<len;i++){
		char *str=strdup(arr[i]);
		reverse(str);
		arr[i]=str;
	}
}

void printarr(char **arr, int len){
	int i,j,flag;
	printf("The sorted array is as follows:\n");
	for(i=0;i<len;i++){
		flag=0;
		for(j=0;j<strlen(arr[i]);j++){
			if(flag==1){
				printf("%c",arr[i][j]);
			} 
			else if(arr[i][j]=='1'){
				flag=1;
				printf("%c",arr[i][j]);
			}
		}
		printf("\n");
	}
}
int main(){
	printf("Enter number of values:");
	int len=0;
	scanf("%d",&len);
	int bin=0;
	printf("Enter number of bins:");
	scanf("%d",&bin);
	int i=0;
	char *arr[10];
	size_t malloc_size = 100;

	for (i = 0; i < len; i++) {
	    arr[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
	    printf("Enter number: ");
	    scanf("%99s", arr[i]); /* Use %99s to avoid overflow */
	                            /* No need to include & address, since word[i] is already a char* pointer */
	}
	convert(arr,len,bin);
	printarr(arr,len);
}
