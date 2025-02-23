#include <bits/stdc++.h>
using namespace std;

const int N = 16 * 2;
int n, a[N];
long double res;
bool mark[N];

void ss(int idx)
{
    if(idx > n)
    {
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            if(mark[i])
                sum += a[i];
        }

       if(res < sin(sum))
            res = sin(sum);

        return;
    }

    mark[idx] = true;
    ss(idx + 1);
    mark[idx] = false;
    ss(idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("sinmax.inp","r",stdin);
    freopen("sinmax.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    ss(1);

    cout << fixed << setprecision(7) << res;

    return 0;
}
