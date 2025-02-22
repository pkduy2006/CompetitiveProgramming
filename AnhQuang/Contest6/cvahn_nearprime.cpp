#include <bits/stdc++.h>
using namespace std;

long long n, ansMin, ansMax;

bool check(long long t)
{
    if(t < 2)
        return false;
    for(long long i = 2; i * i <= t; i++)
    {
        if(t % i == 0)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("NEARPRIME.inp","r",stdin);
    freopen("NEARPRIME.out","w",stdout);

    cin >> n;

    if(check(n))
    {
        cout << n;

        return 0;
    }

    long long ansMax = n, ansMin = n;
    while(true)
    {
        if(ansMin > 1)
            ansMin--;
        ansMax++;

        if(check(ansMin))
        {
            cout << ansMin;

            return 0;
        }

        if(check(ansMax))
        {
            cout << ansMax;

            return 0;
        }
    }

    return 0;
}
