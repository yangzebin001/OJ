/*
 * @Date: 2019-10-12 15:41:01
 * @LastEditors: BeckoninGshy
 * @LastEditTime: 2019-10-12 17:26:48
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include<cctype>
using namespace std;
 
long long get_num(char c)
{
	if(isdigit(c)) return c-'0';
	else return c-'a'+10;
}
 
int main()
{
	string n1,n2;
	long long tag,radix;
	cin>>n1>>n2>>tag>>radix;
	
	if(radix<2) cout<<"Impossible";
	
	if(tag==2) swap(n1,n2);
	long long num1=0,num2=0;
	for(int i=0;i<n1.size();i++)
	{
		num1=num1*radix+get_num(n1[i]);
	}
	long long left=2;
	for(int i=0;i<n2.size();i++)
	{
		left=max(left,get_num(n2[i])+1);
	}
	
	long long right=num1+1;
	while(left<=right)
	{
		long long mid=(left+right)/2;
		num2=0;
		for(int i=0;i<n2.size();i++)
		{
			num2=num2*mid+get_num(n2[i]);
		}
		if(num2==num1) 
		{
			cout<<mid;
			return 0;
		}
		else if(num2>num1||num2<0)
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	
	cout<<"Impossible";
}
