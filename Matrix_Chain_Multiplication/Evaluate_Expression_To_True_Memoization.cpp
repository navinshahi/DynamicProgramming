//Evaluate Expression To True Boolean Parenthesization Memoization
//lT=Left True, lF=Left False, rT=Right True, rF=Right False
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<string,int>mp;
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
	//****************************
	string temp=to_string(i);
	temp.push_back(' ');
	temp.append(to_string(j));
	temp.push_back(' ');
	temp.append(to_string(isTrue));
	if(mp.find(temp)!=mp.end())
	return mp[temp];
	//****************************
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
	mp[temp]=ans;
	return ans;
}
int main()
{
	unordered_map<string,int>::iterator ltr;
	char s[50]="T^F&T";
	int n=5;
	cout<<"No. Of Ways to Evaluate Expression to True :"<<solve(s,0,n-1,1)<<'\n';
	for(ltr=mp.begin();ltr!=mp.end();++ltr){
		cout<<'\t'<<ltr->first<<'\t'<<ltr->second<<'\n';
	}
	return 0;
}
