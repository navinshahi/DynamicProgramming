//Find Threshold floor or Critical floor with minimum number of attempts in Worst Case.
//e = Number of Eggs
//f = Number of Floors
#include<stdio.h>
#include<limits.h>
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
	if(f==0 || f==1)
	return f;
	if(e==1)
	return f;
	int mn=INT_MAX;
	for(int k=1;k<=f;k++)
	{
		int tempans=1+max(solve(e-1,k-1),solve(e,f-k));
		mn=min(mn,tempans);
	}
	return mn;
}
int main()
{
	int e=3;
	int f=5;
	printf("Minimum number of attempts : %d",solve(e,f));
	return 0;
}
