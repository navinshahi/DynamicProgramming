//Palindrome Partitioning Recursive
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
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
	if(isPalindrome(arr,i,j)==1)
	return 0;
	int mn=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int tempans=1+solve(arr,i,k)+solve(arr,k+1,j);
		if(tempans<mn)
		mn=tempans;
	}
	return mn;
}
int main()
{
	char arr[20]="nitin";
	int n=5;
	printf("Minimum Partition: %d",solve(arr,0,n-1));
	return 0;
}
