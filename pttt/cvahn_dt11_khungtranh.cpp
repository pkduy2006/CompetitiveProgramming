#include<bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
#define pii pair<int, int>

using namespace std;
const int N = 1e6 + 7;
const int oo = 1e18 + 10;
const int MOD = 1e9 + 7;
int a[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("BAI2.INP", "r", stdin);
	freopen("BAI2.OUT", "w", stdout);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int x; cin >> x;
		a[x]++;
	}
	int res = 0;
	for (int i = 1; i <= N; ++i)
	{
		res += (a[i] / 2);
	}
	cout << res / 2;

	return 0;
}
