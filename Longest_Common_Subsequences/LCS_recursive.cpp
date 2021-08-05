#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int LCS(char X[],char Y[],int n,int m)
{
	if(n==0 || m==0)
	return 0;
	else
	{
		if(X[n-1]==Y[m-1])
		return 1+LCS(X,Y,n-1,m-1);
		else
		return max(LCS(X,Y,n,m-1),LCS(X,Y,n-1,m));
	}
}
int main()
{
	char X[50]="abcdgh";
	char Y[50]="abedfhq";
	int n=6,m=7;
	printf("Result : %d",LCS(X,Y,n,m));
	return 0;
}
