#include<stdio.h>
int t[50][50];
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
	if(t[n][m]!=-1)
	return t[n][m];
	else
	{
		if(X[n-1]==Y[m-1])
		return t[n][m]=1+LCS(X,Y,n-1,m-1);
		else
		return t[n][m]=max(LCS(X,Y,n,m-1),LCS(X,Y,n-1,m));
	}
}
int main()
{
	char X[50]="abcdgh";
	char Y[50]="abedfhq";
	int n=6,m=7;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		t[i][j]=-1;
	printf("Result : %d\n",LCS(X,Y,n,m));
	return 0;
}
