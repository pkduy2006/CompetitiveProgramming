#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;
int n, a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai2.inp","r",stdin);
    freopen("Bai2.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    cout << max(a[1] * a[2] * a[n], a[n] * a[n - 1] * a[n - 2]);

    return 0;
}
