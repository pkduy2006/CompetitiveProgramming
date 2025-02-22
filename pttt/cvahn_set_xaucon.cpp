#include<bits/stdc++.h>
using namespace std;
set<string> a;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for(int i = 1; i <= s.length(); i++)
	{
	    for(int j = 0; j <= s.length() - i; j++)
			a.insert(s.substr(j, i));
	}
	cout << a.size();
	return 0;
}
