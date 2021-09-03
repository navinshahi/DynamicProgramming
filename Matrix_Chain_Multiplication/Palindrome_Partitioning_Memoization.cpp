//Palindrome Partitioning Memoization
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>
int static t[1001][1001];
bool isPalindrome(char arr[],int i,int j)
{
	int p=0;
	while(i<j)
	{
		if(arr[i]==arr[j]);
		else
		{
			p=1;
			break;
		}
		i++;
		j--;
	}
	if(p==0)
	return true;
	else
	return false;
}
int solve(char arr[],int i,int j)
{
	
	if(i>=j)
	return 0;
	if(t[i][j]!=-1)
	return t[i][j];
	if(isPalindrome(arr,i,j)==1)
	return 0;
	int mn=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int tempans=1+solve(arr,i,k)+solve(arr,k+1,j);
		if(tempans<mn)
		mn=tempans;
	}
	return t[i][j]=mn;
}
int main()
{
	char arr[20]="nitin";
	int n=5;
	memset(t,-1,sizeof(t));
	printf("Minimum Partition: %d",solve(arr,0,n-1));
	return 0;
}
