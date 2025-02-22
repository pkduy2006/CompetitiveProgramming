#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int mark[10], INF = 1e17 + 25;

bool check(int t)
{
    while(t > 0)
    {
        if(!mark[t % 10])
            return false;

        t /= 10;
    }

    return true;
}

void Read()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        mark[x] = true;
    }
}

void Solve()
{
    int res = n;
    while(n <= INF)
    {
        if(check(res))
        {
            cout << res;
            return;
        }

        res+=n;
    }

    cout << 0;
    return;
}

main()
{
    freopen("boi.inp","r", stdin);
    freopen("boi.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
