#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, average=0, res=0;
    cin >> n;
    vector<int> f(n+1);
    f[1]=1;
    f[2]=1;
    for(int i=3; i<=n; i++)
    {
        f[i]=f[i-1]+f[i-2];
        average+=f[i];
    }
    for(int i=1; i<=n; i++)
    {
        cout << f[i] << ' ';
        if(f[i]>average/n)
            res++;
    }
    cout << '\n';
    cout << res;
    return 0;
}
