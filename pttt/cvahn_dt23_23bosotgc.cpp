#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16, M = 1e7 + 16;
int n, a[N], cnt[M];
long long res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    sort(a + 1, a + 1 + n);

    for(int i = 1; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int d = a[j] - a[i];
            int x = a[j] + d;
            
            if(x < a[i] + a[j])
                res += cnt[x];
        }
    }

    cout << res;

    return 0;
}
