#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100072], b[100073];
set<int> a1;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a1.insert(a[i]);
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    for(int i = 1; i <= m; i++)
    {
        auto it = a1.find(b[i]);
        if(it != a1.end())
            res++;
    }
    cout << res;
    return 0;
}
