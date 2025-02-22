#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n, res=0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        double ans=1;
        for(int j=1; j<=i; j++)
            ans/=j;
        res+=ans;
    }
    cout << fixed << setprecision(10) << res;
    return 0;
}
