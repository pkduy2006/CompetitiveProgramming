#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 16;
const long long MOD = 1e9 + 7;
int n;
long long factorial[N], inverseFactorial[N];

long long power(long long x, long y)
{
    if(y == 0)
        return 1;
    
    long long tmp = power(x, y / 2);

    if(y % 2 == 0) 
        return (tmp * tmp) % MOD;
    return (((tmp * tmp) % MOD) * x) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BRS.INP","r",stdin);
    freopen("BRS.OUT","w",stdout);

    cin >> n; 

    if(n % 2 == 1)
    {
        cout << 0;

        return 0;
    }
    
    factorial[1] = 1;
    for(int i = 2; i <= (int)1e6; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
    inverseFactorial[(int) 1e6] = power(factorial[(int) 1e6], MOD - 2);
    for(int i = (int)1e6 - 1; i >= 1; i--)
        inverseFactorial[i] = (inverseFactorial[i + 1] * (i + 1)) % MOD;

    cout << (((factorial[n] * inverseFactorial[n / 2]) % MOD) * inverseFactorial[n / 2 + 1]) % MOD;

    return 0;
}
