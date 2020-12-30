#include <stdio.h>

int sum(int a,int b)
{
   return a+b*2;
}
int main() {
   // printf() displays the string inside quotation
   printf("%d",sum(10,5));
}