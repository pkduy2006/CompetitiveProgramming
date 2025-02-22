#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3 + 25, F = 1e5 + 25;
int m, n, k, a[N][N], mark[F];
bool check[F];
vector<int> ans;

void Read()
{
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            mark[a[i][j]]++;
        }
    }
}

void Solve()
{
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(mark[a[i][j]] != 0 && !check[a[i][j]])
            {
                ans.push_back(mark[a[i][j]]);
                check[a[i][j]] = true;
            }
        }
    }

    int res = 0;

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    for(int i = 0; i < min(k, (int)ans.size()); i++)
        res += ans[i];

    cout << res;
}

main()
{
    freopen("FROG.inp","r",stdin);
    freopen("FROG.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
