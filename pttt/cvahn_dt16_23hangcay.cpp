#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, pos[N], res;
pair<int, int> h[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("trees.inp","r",stdin);
    freopen("trees.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> h[i].first;
        h[i].second = i;
    }

    sort(h + 1, h + 1 + n);

    pos[1] = h[1].second;
    for(int i = 2; i <= n; i++)
        pos[i] = min(pos[i - 1], h[i].second);

    for(int i = 1; i <= n; i++)
        res = max(res, h[i].second - pos[i]);

    if(res)
        cout << res;
    else
        cout << -1;

    return 0;
}
