#include <bits/stdc++.h> 
using namespace std;

const int N = 1e3 + 11;
int a[N], b[N], c[N], n, res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];

    sort(c + 1, c + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int l = upper_bound(c + 1, c + 1 + n, abs(a[i] - b[j])) - c;
            int r = lower_bound(c + 1, c + 1 + n, a[i] + b[j]) - c - 1;

            if(l <= r)
                res += r - l + 1;
        }
    }

    cout << res;

    return 0;
}
