//Find Threshold floor or Critical floor with minimum number of attempts in Worst Case.
//e = Number of Eggs
//f = Number of Floors
#include<stdio.h>
#include<limits.h>
#include<string.h>
int static t[11][51];
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int solve(int e,int f)
{
	int low,high;
	if(f==0 || f==1)
	return f;
	if(e==1)
	return f;
	if(t[e][f]!=-1)
	return t[e][f];
	int mn=INT_MAX;
	for(int k=1;k<=f;k++)
	{
		if(t[e-1][k-1]!=-1)
		low=t[e-1][k-1];
		else{
			low=solve(e-1,k-1);
			t[e-1][k-1]=low;
		}
		if(t[e][f-k]!=-1)
		high=t[e][f-k];
		else{
			high=solve(e,f-k);
			t[e][f-k]=high;
		}
		int tempans=1+max(low,high);
		mn=min(mn,tempans);
	}
	t[e][f]=mn;
	return mn;
}
int main()
{
	int e=3;
	int f=5;
	memset(t,-1,sizeof(t));
	printf("Minimum number of attempts : %d",solve(e,f));
	return 0;
}
