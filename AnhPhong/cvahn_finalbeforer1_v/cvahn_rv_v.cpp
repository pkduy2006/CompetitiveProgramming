#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16;
int n, a[N], start = 0, stop;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RV.inp","r",stdin);
    freopen("RV.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        if(a[i] != i)
        {
            start = i;
            break;
        }
    }

    for(int i = start + 1; i <= n; i++)
    {
        if(a[i] == start)
            stop = i;
    }

    if(stop == 0 && start == 0)
    {
        for(int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';

        return 0;
    }

    for(int i = 1; i <= start - 1; i++)
        cout << a[i] << ' ';
    for(int i = stop; i >= start; i--)
        cout << a[i] << ' ';
    for(int i = stop + 1; i <= n; i++)
        cout << a[i] << ' ';

    return 0;
}
