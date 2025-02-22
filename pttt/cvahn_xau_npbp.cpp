#include<bits/stdc++.h>
using namespace std;
string s,x,y;
int i;
int main()
{
	getline(cin,s);
	while(s.length()%3>0) s='0'+s;
	while(s!="")
	{
		x=s.substr(0.,3);
		s.erase(0,3);
		if(x=="000") y=y+'0';
		if(x=="001") y=y+'1';
		if(x=="010") y=y+'2';
		if(x=="011") y=y+'3';
		if(x=="100") y=y+'4';
		if(x=="101") y=y+'5';
		if(x=="110") y=y+'6';
		if(x=="111") y=y+'7';
	}
	while(y[0]=='0') y.erase(0,1);
	cout<<y;
	return 0;
}
