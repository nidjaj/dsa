#include<stdio.h>
int gcd(int n1,int n2)
{
	if(n1==n2)
	  return n1;
	if(n1>n2)
	  return gcd(n1-n2,n2);
	else
	  return gcd(n1,n2-n1);
	  
}
int main()
{
	int n1,n2,result;
    printf("enter two number");
	scanf("%d\t%d\n",&n1,&n2);
	result=gcd(n1,n2);
	printf("%d",result);
	return 0;
	
}
