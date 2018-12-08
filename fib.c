#include <stdio.h>
void matmul(int x[2][2], int y[2][2])
{
  int a =  x[0][0]*y[0][0] + x[0][1]*y[1][0];
  int b =  x[0][0]*y[0][1] + x[0][1]*y[1][1];
  int c =  x[1][0]*y[0][0] + x[1][1]*y[1][0];
  int d =  x[1][0]*y[0][1] + x[1][1]*y[1][1];
 
  x[0][0] = a;
  x[0][1] = b;
  x[1][0] = c;
  x[1][1] = d;
}
 

void power(int x[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  int y[2][2];
  y[0][0] = 1;
  y[0][1] = 1;
  y[1][0] = 1;
  y[1][1] = 0;
 
  power(x, n/2);
  matmul(x, x);
 
  if (n%2 != 0)
     matmul(x, y);
} 

int fib(int n)
{
  int y[2][2];
  y[0][0] = 1;
  y[0][1] = 1;
  y[1][0] = 1;
  y[1][1] = 0;
  if (n == 0)
    return 0;
  power(y, n-1);
  return y[0][0];
}
 

 

 
int main()
{
  int n = 0;
  printf("Enter i:");
  scanf("%d",&n);
  printf("ith fibonacci number is:");
  printf("%d\n", fib(n));
  return 0;
  }