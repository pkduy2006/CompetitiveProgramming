#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1;
const int MaxNum = 1e18 + 2;

int a[N], b[N], n;

bool into(int i, int j)
{
    return (1 <= i && i <= n && 1 <= j && j <= n);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);

    int i = 1, j = n, res = MaxNum;

    while(into(i, j))
    {
        res = min(res, abs(a[i] + b[j]));
        if(a[i] + b[j] == 0)
            break;
        else if(a[i] + b[j] > 0)
            j--;
        else
            i++;
    }

    cout << res;
    return 0;
}
