#include <bits/stdc++.h>
#define int long long
using namespace std;
set<int> res;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        res.insert(x);
    }

    cout << res.size();
    return 0;
}
