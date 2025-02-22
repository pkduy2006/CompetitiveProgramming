#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string m, n;
    int res = 0;
    cin >> m >> n;

    while(m.size() < n.size())
        m = '0' + m;
    while(n.size() < m.size())
        n = '0' + n;

    for(int i = 0; i < m.size(); i++)
        res += abs((m[i] - '0') - (n[i] - '0'));

    cout << res;
    return 0;
}
