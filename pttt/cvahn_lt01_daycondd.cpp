#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0, cnt = 0, pos;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        int total = 1;
        for(int j = i; j < n; j++)
        {
            if(a[j] * a[j + 1] < 0)
                total++;
            else
                break;
        }
        if(res == total)
            cnt++;
        else if(res < total)
        {
            res = total;
            cnt = 1;
            pos = i;
        }
    }
    cout << cnt << ' '  << res << '\n';
    for(int i = pos; i <= pos + res - 1; i++)
        cout << a[i] << ' ';
    return 0;
}
