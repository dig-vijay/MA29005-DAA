#include <stdio.h>
int power(int a, int n){
if (n==1){
return ;}
if (n%2==0){
return power(a,n/2)*power(a,n/2);
}
else{
return power(a,(n+1)/2)*power(a,(n-1)/2);
}
}
int main(){
int a,n;
printf("Enter base:");
scanf("%d",&a);
printf("Enter exponent:");
scanf("%d",&n);
printf("The answer is:");
printf("%d\n",power(a,n));
return 0;
}
