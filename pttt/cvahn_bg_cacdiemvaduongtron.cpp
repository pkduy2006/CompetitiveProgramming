#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> res;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int centerX, centerY, r, n;
    cin >> centerX >> centerY >> r;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= r * r)
            res.push_back(i);
    }
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    return 0;
}
