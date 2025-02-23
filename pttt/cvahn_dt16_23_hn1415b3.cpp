#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
int n, a[N], res;

bool check(int x)
{
    if(x < 2)
        return true;
    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0)
            return true;
    }

    return false;
}

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
        if((check(a[i]) && a[i] > 4) || a[i] == 1)
            res++;
    }

    cout << res;

    return 0;
}
