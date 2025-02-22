#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 25;
int n, h, a[N];

void Read()
{
    cin >> n >> h;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
}

void Solve()
{
    int res = 1, pos = 1;

    for(int i = 1; i <= n; i++)
    {
        if(a[i] - a[pos] > h)
        {
            res++;
            pos = i;
        }
    }

    cout << res;
}

main()
{
    freopen("Chianhom.inp","r",stdin);
    freopen("Chianhom.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
