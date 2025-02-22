#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int n, a[N], u, cnt[N * 10], res = 1;

void extract(int x)
{
    for(int i = 2; i <= 97; i++)
    {
        if(x % i == 0)
        {
            int tmp = 0;
            while (x % i == 0)
            {
                x /= i;
                tmp++;
            }
        cnt[i] = max(cnt[i], tmp);
        }
    }
}

int power(int x, int y)
{
    if(y == 0)
        return 1;
    
    int tmp = power(x, y / 2);

    if(y % 2 == 0)
        return tmp * tmp;
    return tmp * tmp * x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("UCBCD.inp","r",stdin);
    freopen("UCBCD.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    u = a[1];
    for(int i = 2; i <= n; i++)
        u = __gcd(u, a[i]);
    for(int i = 1; i <= n; i++)
        extract(a[i]);
    for(int i = 2; i <= 97; i++)
        res *= power(i, cnt[i]);

    cout << u << '\n' << res;
    
    return 0;
}
