#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[106][107], maxSum = 0, Sum = 0, n;
bool check[108];

void Solve(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(!check[j])
        {
            check[j] = true;
            Sum += a[i][j];
            if(i == n)
                maxSum = max(Sum, maxSum);
            else
                Solve(i + 1);
            check[j] = false;
            Sum -= a[i][j];
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    Solve(1);

    cout << maxSum;
    return 0;
}
