#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, m, a[N], b[N], cnt = 1, val, res;
map<int, int> mp;
set<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dempt.inp","r",stdin);
    freopen("dempt.out","w",stdout);

    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    sort(b + 1, b + 1 + n);

    val = b[1];
    for(int i = 2; i <= n; i++)
    {
        if(val == b[i])
            cnt++;
        else
        {
            mp[val] = cnt;
            val = b[i];
            cnt = 1;
        }
    }

    for(auto it = s.begin(); it != s.end(); it++)
        res += mp[(*it)];

    cout << res;

    return 0;
}
