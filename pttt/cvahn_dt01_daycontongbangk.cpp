#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int n, a[N], res;
long long k, sum[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("doancon.inp","r",stdin);
    freopen("doancon.out","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(sum[j] - sum[i - 1] == k)
                res++;
        }
    }

    cout << res;

    return 0;
}
