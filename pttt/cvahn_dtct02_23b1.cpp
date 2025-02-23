#include<bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
#define pii pair<int, int>

using namespace std;
const int N = 2e2 + 7;
const int oo = 1e18 + 10;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int a[N][N], timer = 1;
bool vis[N][N];

bool check(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (a[x + dx[i]][y + dy[i]] == 0 or (a[x + dx[i]][y + dy[i]] < timer and a[x + dx[i]][y + dy[i]] != 1))
		{
			cnt++;
		}
	}
	if (cnt >= 2)
	{
		return 1;
	}
	return 0;
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	if (check(x, y))
	{
		a[x][y] = timer;
	}
	for (int i = 0; i < 4; ++i)
	{
		int X = x + dx[i];
		int Y = y + dy[i];
		if (a[X][Y] == 1 and !vis[X][Y])
		{
			dfs(X, Y);
		}
	}
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("CHEESE.INP", "r", stdin);
	freopen("CHEESE.OUT", "w", stdout);

	int m, n; cin >> m >> n;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}
	int dem = 0;
	while (1)
	{
		dem++;
		timer++;
		bool done = 1;
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (!vis[i][j] and a[i][j] == 1)
				{
					dfs(i, j);
					done = 0;
				}
			}
		}
		/*for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}*/
		if (done == 1)
		{
			break;
		}
	}
	cout << timer - 2 << '\n';

	return 0;
}
