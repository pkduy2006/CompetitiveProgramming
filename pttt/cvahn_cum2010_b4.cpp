#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i+=2)
        res += i * i;
    cout << res;
    return 0;
}
