#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 11;
int n, a[N], maxa;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Thichay.inp","r",stdin);
    freopen("Thichay.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
    for(int i = n; i >= 1; i--)
        maxa = max(maxa, a[i] + n - i + 1);

    for(int i = 1; i <= n; i++)
    {
        if(maxa <= a[i] + n)
        {
            cout << n - i + 1;

            return 0;
        }
    }

    return 0;
}
