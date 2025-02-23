#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
const long double e = 1e-10;
int n, res;
long double a[N];

int binary_ss(long double val, int l)
{
    int r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid] - val < e)
            l = mid + 1;
        else
            r = mid - 1;
    }
    
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("chiadeu.inp","r",stdin);
    freopen("chiadeu.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
    //for(int i = 1; i <= n; i++)
    //    cout << a[i] << ' ';
    //cout << '\n';

    for(int i = 1; i <= n - 2; i++)
    {
        for(int j = i + 1; j <= n - 1; j++)
        {
            long double dif = a[j] - a[i];
            //cout << dif << ' ';

            int idx = binary_ss(a[j] + dif, j + 1);

            if(abs(a[idx] - a[j] - dif) < e)
            {
                //cout << i << ' ' << j << ' ' << idx << '\n';
                res++;
            }
        }
    }

    cout << res;

    return 0;
}
