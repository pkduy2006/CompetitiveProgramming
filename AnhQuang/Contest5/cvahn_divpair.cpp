#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e6 + 11;
int n, a[N], m;
long long res;
map<int, int> remain;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DIVPAIR.inp","r",stdin);
    freopen("DIVPAIR.out","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {   
        cin >> a[i];

        res += remain[(m - a[i] % m) % m];
        remain[a[i] % m]++;
    }

    cout << res;

    return 0;
}
