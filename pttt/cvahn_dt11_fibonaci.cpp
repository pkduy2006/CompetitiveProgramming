#include<bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
#define pii pair<int, int>

using namespace std;
const int N = 2e5 + 7;
const int oo = 1e18 + 10;
const int MOD = 1e9 + 7;
string fb[1001];

string congsl(string a, string b)
{
	string c;
	int nho=0;
	while (a.size()<b.size()) a='0'+a;
	while (a.size()>b.size()) b='0'+b;
	for (int i = a.size()-1; i >= 0; --i)
	{
		nho+=a[i]+b[i]-96;
		c=char(nho%10+48)+c;
		nho/=10;
	}
	c=char(nho%10+48)+c;
	while (c[0]=='0' and c.size()>1) c.erase(0,1);
	return c;
}

void create()
{
	fb[1] = fb[2] = "1";
	for (int i = 3; i <= 1000; ++i)
	{
		fb[i] = congsl(fb[i - 2], fb[i - 1]);
	}
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("FIBO.INP", "r", stdin);
	freopen("FIBO.OUT", "w", stdout);

	create();
	int x;
	while (cin >> x)
	{
		cout << fb[x] << '\n';
	}

	return 0;
}
