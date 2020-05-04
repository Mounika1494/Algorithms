#include<stdio.h>

int Multiply(int m,int n);

int findnoofdigits(int k)
{
int no_of_digits = 1;
while(k)
{
k = k>>4;
no_of_digits++;
}
printf("no_of_digits:%d\n",no_of_digits);
return(no_of_digits);
}
	
int power(int m,int n)
{
while(n-1)
{
m = m*m;
n--;
}
return m;
}

void karatsuba(int a,int b,int c,int d,int n)
{
 printf("a:%d,b:%d,c:%d,d=%d,n=%d\n",a,b,c,d,n);
 int p1 = Multiply(a,c);
 int p2 = Multiply((a+b),(c+d));
 int p3 = Multiply(b,d);
 printf("p1:%d,p2:%d,p3:%d",p1,p2,p3);
 int result = power(10,n)*p1 + power(10,n/2)*(p2-p1-p3)+ p3;
 printf("result:%d\n",result);
}

int Multiply(int m,int n)
	{
	 int no_of_digits;
         int mask = 0xF;
  	 no_of_digits = findnoofdigits(m);
         int shift = no_of_digits/2;
         int dup_shift = shift;
         if(no_of_digits == 1)
         return (m*n);
 	 while(dup_shift-1)
 	 {
           mask = (mask<<4) | mask;
	   dup_shift--;
         }
         printf("mask:%0x\n",mask);
         printf("%d\n",m&mask);
         printf("%d\n",m>>(shift*4));
 	 
         printf("%d\n",n&mask);
         printf("%d\n",n>>(shift*4));
         //karatsuba(m&mask,m>>(shift*4),n&mask,n>>(shift*4),no_of_digits);
	}

int main(void)
{
   printf("\n ****** Karatsuba Multiplication ******\n");
   Multiply(1234,5678);
   return 0;
}
