#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[110][111], row[112], sum = 0, MaxSum = 0, cnt, n, k;
bool mark[113];

void Solve(int t)
{
    for(int i = row[t - 1] + 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!mark[j])
            {
                row[t] = i;
                mark[j] = true;
                sum += a[i][j];

                if(t == k)
                {
                    if(sum > MaxSum)
                    {
                        MaxSum = sum;
                        cnt = 1;
                    }
                    else if(MaxSum == sum)
                        cnt++;
                }
                else
                    Solve(t + 1);
                sum -= a[i][j];
                mark[j] = false;
                row[i] = 0;
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    Solve(1);

    cout << MaxSum << ' ' << cnt;
    return 0;
}
