#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e13 + 25, N = 1e5 + 25;
int n, a[N], b[N], res = INF;

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
}

void Solve()
{
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);

    int i = 1, j = n;
    while(i <= n && j >= 1)
    {
        res = min(res, abs(a[i] + b[j]));
        if(a[i] + b[j] < 0)
            i++;
        else
            j--;
    }

    cout << res;
}

main()
{
    freopen("seqgame.inp","r",stdin);
    freopen("seqgame.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
