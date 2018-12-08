#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


void countsort(char **arr, int len,int index){
	int count[2]={0,0};
	char *final[100];
	int i=0;		
	
	for(i=0;i<len;i++){
		count[arr[i][index]-'0']++;			
	}
	
	for(i=1;i<2;i++){
		count[i]=count[i]+count[i-1];
	}
	
	for(i=len-1;i>=0;i--){
		final[count[arr[i][index]-'0']-1]=arr[i];
		count[arr[i][index]-'0']--;			
	}
	for(i=0;i<len;i++){
		arr[i]=final[i];
	}
	
}





void convert(char **arr,int len){
	int i,j,max_len;
	char temp;
	max_len=strlen(arr[0]);
	for(i=0;i<len;i++){
		if(strlen(arr[i])>max_len){
			max_len=strlen(arr[i]);
		}
	}
	for(i=0;i<len;i++){
		char *str=strdup(arr[i]);
		reverse(str);
		while(strlen(str)<max_len){
			append(str);
		}
		arr[i]=str;
		printf("%s\n",arr[i]);
		
	}
	for(i=0;i<max_len;i++){
		countsort(arr,len,i);
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
	int i=0;
	char *arr[100];
	size_t malloc_size = 100;

	for (i = 0; i < len; i++) {
	    arr[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
	    printf("Enter number: ");
	    scanf("%99s", arr[i]); /* Use %99s to avoid overflow */
	                            /* No need to include & address, since word[i] is already a char* pointer */
	} 
	convert(arr,len);
	printarr(arr,len);
}
