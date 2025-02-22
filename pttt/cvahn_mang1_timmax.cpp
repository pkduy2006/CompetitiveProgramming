#include <bits/stdc++.h>
using namespace std;
int a[10115];
int main()
{
    int n, res=0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        res=max(res, a[i]);
    }
    cout << res << '\n';
    for(int i=1; i<=n; i++)
    {
        if(a[i]==res)
            cout << i << ' ';
    }
    return 0;
}
