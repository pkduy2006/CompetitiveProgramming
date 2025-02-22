#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int n, x, ans = 0, a[N];

void Read()
{
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
}

void Solve()
{
    for(int i = 1; i <= n; i++)
    {
        int l = 1, r = n;

        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(a[mid] + a[i] <= x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        if(r != i && r != 0)
            ans = max(ans, a[i] + a[r]);
    }

    cout << ans;
}

main()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
