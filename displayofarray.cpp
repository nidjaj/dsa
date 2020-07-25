#include<stdio.h>
#include<conio.h>
void display(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",(a+i));
}
int main()
{
	int a[]={12,23,34,78,45,90,36},n;
	n=sizeof(a)/sizeof(a[0]);
	display(a,n);
}
