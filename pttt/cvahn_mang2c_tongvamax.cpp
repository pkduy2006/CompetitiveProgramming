#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> total, maxele;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    while(n--)
    {
        vector<int> a(m+1);
        int sum = 0;
        int ans = -1e9 - 6;
        for(int i = 1; i <= m; i++)
        {
            cin >> a[i];
            sum += a[i];
            ans = max(ans, a[i]);
        }
        maxele.push_back(ans);
        total.push_back(sum);
    }
    for(int i = 0; i < total.size(); i++)
        cout << total[i] << ' ';
    cout << '\n';
    for(int i = 0; i < maxele.size(); i++)
        cout << maxele[i] << ' ';
    
    return 0;
}
