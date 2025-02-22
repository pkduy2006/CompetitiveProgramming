#include <bits/stdc++.h>
#define int long long
using namespace std;
string f[61];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> f[1] >> f[2];
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    cout << f[n];
    return 0;
}
