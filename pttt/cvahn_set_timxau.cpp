#include<bits/stdc++.h>
using namespace std;
set <string> a;
int i,k,l,d;
string s,x;
int main()
{
	cin>>k>>x;
	l=x.length();
	x=x+x;
	for(i=0;i<l;i++)
	{
		s=x.substr(i,l);
		a.insert(s);
	}
	if(a.size()<k) cout<<-1;
	else
	{
		d=0;
		for(auto i=a.begin();i!=a.end();i++)
		{
			d++;
			if(d==k) {
				cout<<*i;break;
			}
		}
	}
	return 0;
}
