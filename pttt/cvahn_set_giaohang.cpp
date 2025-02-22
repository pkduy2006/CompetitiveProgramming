#include <bits/stdc++.h>
#define int long long
using namespace std;
set<int> s;
bool check(int y)
{
    string z = to_string(y);
    for(int i = 0; i < z.size(); i++)
    {
        if(s.count(z[i]) == 0)
            return false;
    }
    return true;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int res = n;
    for(int i = 1; i <= m; i++)
    {
        char x;
        cin >> x;
        s.insert(x);
    }
    while(true)
    {
        if(check(res))
        {
            cout << res;
            return 0;
        }
        res+=n;
    }
    cout << res;
    return 0;
}
