#include <bits/stdc++.h>
using namespace std;

int n, k, res;

bool check(int x)
{
    int cnt = 0;
    for(int i = 1; i <= sqrt(x); i++)
    {
        if(x % i == 0)
        {
            cnt++;
            if(x / i != i)
                cnt++;
        }
    }

    return cnt == k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU1.inp","r",stdin);
    freopen("CAU1.out","w",stdout);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        if(check(i))
            res++;
    }

    cout << res;

    return 0;
}
