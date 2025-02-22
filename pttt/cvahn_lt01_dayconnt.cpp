#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(int l)
{
    if(l < 2)
        return false;
    for(int i = 2; i <= sqrt(l); i++)
    {
        if(l % i == 0)
            return false;
    }
    return true;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0, total = 0, pos;
    cin >> n;
    vector<int> a(n + 1), mark(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(check(a[i]))
            mark[i] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(mark[i] == 1)
        {
            int cnt = 1;
            for(int j = i + 1; j <= n; j++)
            {
                if(mark[j] == 1)
                    cnt++;
                else
                    break;
            }
            if(res == cnt)
                total++;
            else if(res < cnt)
            {
                res = cnt;
                total = 1;
                pos = i;
            }
        }
    }
    cout << total << ' ' << res << '\n';
    for(int i = pos; i <= pos + res - 1; i++)
        cout << a[i] << ' ';
    return 0;
}
