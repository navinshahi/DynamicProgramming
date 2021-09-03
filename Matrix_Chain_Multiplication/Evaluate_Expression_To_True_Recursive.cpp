//Evaluate Expression To True Boolean Parenthesization Recursive
//lT=Left True, lF=Left False, rT=Right True, rF=Right False
#include<stdio.h>
int solve(char s[],int i,int j,int isTrue)
{
	if(i>j)
	return false;
	if(i==j)
	{
		if(isTrue==1)
		return s[i]=='T';
		else
		return s[i]=='F';
	}
	int ans=0;
	for(int k=i+1;k<=j-1;k+=2)
	{
		int lT=solve(s,i,k-1,1);
		int lF=solve(s,i,k-1,0);
		int rT=solve(s,k+1,j,1);
		int rF=solve(s,k+1,j,0);
		if(s[k]=='&')
		{
			if(isTrue==1)
			ans=ans+lT*rT;
			else
			ans=ans+lF*rT+lT*rF+lF*rF;
		}
		else if(s[k]=='|')
		{
			if(isTrue==1)
			ans=ans+lT*rT+lT*rF+lF*rT;
			else
			ans=ans+lF*rF;
		}
		else if(s[k]=='^')
		{
			if(isTrue==1)
			ans=ans+lF*rT+lT*rF;
			else
			ans=ans+lT*rT+lF*rF;
		}
	}
	return ans;
}
int main()
{
	char s[50]="T^F&T";
	int n=5;
	printf("No. Of Ways to Evaluate Expression to True : %d",solve(s,0,n-1,1));
	return 0;
}
