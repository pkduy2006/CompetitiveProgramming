#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, res;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i += 2)
        res += i * i;

    cout << res;

    return 0;
}
