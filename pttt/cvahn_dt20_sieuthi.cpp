#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, k, a[N], cnt, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU2.INP","r",stdin);
    freopen("CAU2.OUT","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    for(int i = n; i >= 1; i--)
    {
        cnt++;
        if(cnt == k)
            cnt = 0;
        else
            res += a[i];
    }

    cout << res;

    return 0;
}
