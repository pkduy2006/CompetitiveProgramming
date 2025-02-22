#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 25;
int n, k, a[N];

void Read()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    sort(a + 1, a + 1 + n);

    int pos = n, res = 0;

    for(int i = n; i >= 1; i--)
    {
        if(i > pos - k + 1)
            res += a[i];
        else
            pos = i - 1;
    }

    cout << res;
}

main()
{
    freopen("Sieuthi.inp","r",stdin);
    freopen("Sieuthi.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
