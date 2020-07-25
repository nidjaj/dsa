#include<stdio.h>
#include<conio.h>
void input(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	scanf("%d\t",&a[i]);
	
}
void display(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",(a+i));
}
int main()
{
	int a[20],n;
	printf("enter the number of element");
	scanf("%d\t",&n);
	printf("enter element");
	input(a,n);
}
