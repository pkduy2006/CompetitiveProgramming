#include <bits/stdc++.h>
#define int long long  
using namespace std;

const int N = 39;
int n, x, t[N];

namespace sub1
{
    int res = 0;

    void BF(int idx, int sum)
    {
        if(idx > n)
        {
            res += (sum == x);

            return;
        }

        BF(idx + 1, sum);
        BF(idx + 1, sum + t[idx]);
    }

    void solve()
    {
        BF(1, 0);

        cout << res;
    }   
}

namespace sub2
{
    map<int, int> mp;
    int res = 0;

    void recurLeft(int idx, int sum)
    {
        if(idx > n / 2)
        {   
            ++mp[sum];
            
            return;
        }

        recurLeft(idx + 1, sum);
        recurLeft(idx + 1, sum + t[idx]);
    }

    void recurRight(int idx, int sum)
    {
        if(idx > n)
        {   
            res += mp[x - sum];

            return;
        }

        recurRight(idx + 1, sum);
        recurRight(idx + 1, sum + t[idx]);
    }

    void solve()
    {
        recurLeft(1, 0);
        recurRight(n / 2 + 1, 0);

        cout << res;
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SSS.inp","r",stdin);
    freopen("SSS.out","w",stdout);

    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> t[i];

    if(n <= 20)
        sub1::solve();
    else
        sub2::solve();

    return 0;
}
