#include <bits/stdc++.h>
using namespace std;

const int N = 31;
int n, a[N][N], res, ans;
bool mark[N][N], mark_col[N];

void ss(int idx_row)
{
    if(idx_row > n)
    {
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(mark[i][j])
                    ans += a[i][j];
            }
        }
        res = max(res, ans);

        return;
    }

    for(int j = 1; j <= n; j++)
    {
        if(!mark_col[j])
        {
            mark_col[j] = true;
            mark[idx_row][j] = true;
            ss(idx_row + 1);
            mark_col[j] = false;
            mark[idx_row][j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Chonso.inp","r",stdin);
    freopen("Chonso.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    ss(1);

    cout << res;

    return 0;
}
