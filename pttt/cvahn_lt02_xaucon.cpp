#include<bits/stdc++.h>
using namespace std;
string s,s1;
int i,j,d;
int main()
{
	cin >> s;
	for (i=0;i<=s.length()-1;i++)
	{
		s1=s[i];
		if (s.find(s1)==i)
			d++;
		for (j=i+1;j<=s.length()-1;j++)
			{
				s1+=s[j];
				if (s.find(s1)==i)
					d++;
			}
	}
	cout << d;
	return 0;
}
