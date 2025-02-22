#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 11;
int n, b, a[N], c[N], res = 0;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);

    cin >> n >> b;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = a[i];
    }

    sort(c + 1, c + 1 + n);

    for(int i = 1; i <= n; i++)
    {
        int posLeft = lower_bound(c + 1, c + 1 + n, b - a[i]) - c;
        int posRight = upper_bound(c + 1, c + 1 + n, b - a[i]) - c - 1; 

        if(c[posLeft] == c[posRight] && c[posLeft] + a[i] == b)
        {   
            res += posRight - posLeft + 1;

            if(c[posLeft] == a[i])
                res--;
        }
    }

    cout << res / 2;

    return 0;
}
