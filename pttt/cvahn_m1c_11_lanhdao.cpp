#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int t, a[N], n, max_value[N];

void Solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    max_value[n] = a[n];
    for(int i = n - 1; i >= 1; i--)
        max_value[i] = max(max_value[i + 1], a[i]);
    
    vector<int> res;
    for(int i = 1; i < n; i++)
    {
        if(a[i] > max_value[i + 1])
            res.push_back(a[i]);
    }
    res.push_back(a[n]);

    for(auto x : res)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("LANHDAO.inp","r",stdin);
    freopen("LANHDAO.out","w",stdout);

    cin >> t;
    while (t--)
        Solve();
    
    return 0;
}
