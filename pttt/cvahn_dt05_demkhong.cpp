#include <bits/stdc++.h>
using namespace std;

long long n, factor2 = 2, factor5 = 5, cnt2, cnt5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("demsokhong.inp","r",stdin);
    freopen("demsokhong.out","w",stdout);

    cin >> n;
    
    while (factor2 <= n)
    {
        cnt2 += n / factor2;
        factor2 *= 2;
    }
    while (factor5 <= n)
    {
        cnt5 += n / factor5;
        factor5 *= 5;
    }
    
    cout << min(cnt2, cnt5);

    return 0;
}
