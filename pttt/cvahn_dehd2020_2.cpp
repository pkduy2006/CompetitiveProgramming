#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
const int INF = 1e9 + 7;
int n, a[N], cnt, res = INF;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 0)
            cnt++;
        else
        {
            if(cnt >= 2)
                res = min(res, cnt);
            cnt = 0;
        }
    }
    if(cnt >= 2)
        res = min(res, cnt);

    cout << res;

    return 0;
}
