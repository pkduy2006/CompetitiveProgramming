#include <bits/stdc++.h>
using namespace std;

int n1, n2, k, res;

bool check(int x)
{
    int cnt = 1;
    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0)
        {
            cnt += i;
            if(i * i != x)
                cnt += x / i;
        }
    }

    return cnt + k == x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);

    cin >> n1 >> n2 >> k;
    
    for(int i = n1; i <= n2; i++)
    {
        if(check(i))
            res++;
    }

    cout << res;

    return 0;
}
