#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 16;
int n, a[N], res;
map<int, int> value;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TONGBANGKHONG.inp","r",stdin);
    freopen("TONGBANGKHONG.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        value[a[i]]++;

    for(int i = 1; i <= n; i++)
    {     
        if(a[i] < 0)
            res += value[abs(a[i])];
    }
    res += value[0] * (value[0] - 1) / 2;
    
    cout << res;

    return 0;
}
