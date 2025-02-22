#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 16;
const long long INF = 1e17 + 11;
int n;
long long s, m, res = INF, a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RSSEQ.inp","r",stdin);
    freopen("RSSEQ.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        s += a[i];
        res = min(res, s - m);
        m = max(m, s);
    }

    cout << s - 2 * res;

    return 0;
}
