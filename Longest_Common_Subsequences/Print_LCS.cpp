#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int main()
{
	char X[50]="acbcf";
	char Y[50]="abcdaf";
	char s[50];
	int i,j;
	int m=5,n=6;
	int t[m+1][n+1];
	//Base Condition
	for(int i=0;i<m+1;i++)
		for(int j=0;j<n+1;j++)
		if(i==0 || j==0)
			t[i][j]=0;
	//Main Program
	for(int i=1;i<m+1;i++)
		for(int j=1;j<n+1;j++)
		{
			if(X[i-1]==Y[j-1])
			t[i][j]=1+t[i-1][j-1];
			else
			t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++)
		{
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
	i=m;
	j=n;
	int k=0;
	while(i>0 && j>0)
	{
	if(X[i-1]==Y[j-1])
	{
		s[k]=X[i-1];
		k++;
		i--;
		j--;
		}
	else
	{
		if(t[i][j-1]>t[i-1][j])
		j--;
		else
		i--;
		}	
	}
	printf("Result : %s",strrev(s));	
	return 0;
}
