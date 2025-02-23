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

int _2muN(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		int tmp = _2muN(n / 2) % MOD;
		if (n % 2 == 1)
		{
			return tmp * tmp * 2 % MOD;
		}
		return tmp * tmp % MOD;
	}
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("BIN10.INP", "r", stdin);
	freopen("BIN10.OUT", "w", stdout);

	int n; cin >> n;
	cout << (_2muN(n) - (n % MOD) - 1 + MOD) % MOD << '\n';

	return 0;
}
