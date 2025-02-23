#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int n, a[N], l[N], r[N], res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("wavio.inp","r",stdin);
    freopen("wavio.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    l[1] = r[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        l[i] = 1;
        for(int j = 1; j <= i; j++)
        {
            if(a[i] > a[j])
                l[i] = max(l[i], l[j] + 1);
        }
    }

    for(int i = n - 1; i >= 1; i--)
    {
        r[i] = 1;
        for(int j = n; j >= i; j--)
        {
            if(a[i] > a[j])
                r[i] = max(r[i], r[j] + 1); 
        }
    }

    for(int i = 1; i <= n; i++)
        res = max(res, min(r[i], l[i]));
    
    cout << res * 2 - 1;

    return 0;
}
