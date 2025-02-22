#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, a[N], res, b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SWAP.INP","r",stdin);
    freopen("SWAP.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        if(a[i] == i)
            continue;

        res++;
       int pos = b[i];
       swap(a[i], a[pos]);
       b[a[pos]] = pos;
    }

    cout << res;

    return 0;
}
