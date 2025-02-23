#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5 + 16;
int n, b[N], c[N], res = INF;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seqgame.inp","r",stdin);
    freopen("seqgame.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];

    sort(c + 1, c + 1 + n);
    sort(b + 1, b + 1 + n);

    int i = 1, j = n;
    while (i <= n && j >= 1)
    {
        res = min(res, abs(b[i] + c[j]));
        if(b[i] + c[j] < 0)
            i++;
        else
            j--;
    }

    cout << res;

    return 0;
}
