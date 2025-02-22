#include <bits/stdc++.h>
using namespace std;

long long res, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("GPUZZLE.INP","r",stdin);
    freopen("GPUZZLE.OUT","w",stdout);

    cin >> n;
    
    for(long long i = 1; i <= n; i++)
        res += (n - i) * i;
    res+= n;

    cout << res;
    return 0;
}
