#include <bits/stdc++.h>
using namespace std;

long long n;
int cnt = 0;

long long power(long long x, int y)
{
    if(y == 0)
        return 1;

    long long tmp = power(x, y / 2);
    if(y % 2 == 0)
        return tmp * tmp;
    return tmp * tmp * x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SUMXOR.INP","r",stdin);
    freopen("SUMXOR.out","w",stdout);
    
    cin >> n;
    while (n > 0)
    {
        cnt += (n % 2 == 0);
        n /= 2;
    }
    
    cout << power(2, cnt);
    return 0;
}
