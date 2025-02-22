#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int n, a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    cout << max(a[1] * a[2], a[n] * a[n - 1]);

    return 0;
}
