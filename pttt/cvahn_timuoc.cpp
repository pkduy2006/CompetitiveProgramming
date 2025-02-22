#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;

void Read()
{
    cin >> n >> k;
}

void Solve()
{
    int res = 0;

    for(int i = 1; i <= n; i++)
    {
        int t = i;
        while(t % k == 0)
        {
            res++;
            t /= k;
        }
    }

    cout << res << '\n';
}

main()
{
    freopen("Timuoc.inp","r",stdin);
    freopen("Timuoc.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ntests;
    cin >> ntests;
    while(ntests--)
    {
        Read();

        Solve();
    }

    return 0;
}
