#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int n, sum[N];

void Build()
{
    for(int i = 1; i <= N; i++)
        sum[i] = sum[i - 1] + i;
}

void Read()
{
    cin >> n;
}

void Solve()
{
    int res = 0;

    for(int i = 1; i <= N; i++)
    {
        int f = n - sum[i];
        int l = 1, r = N;

        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(sum[mid] == f)
            {
                res = mid;
                break;
            }
            else if(sum[mid] > f)
                r = mid - 1;
            else
                l = mid + 1;
        }
    }

    if(res != 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

main()
{
    freopen("Sotamgiac.inp","r",stdin);
    freopen("Sotamgiac.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Build();
    int ntests;
    cin >> ntests;
    while(ntests--)
    {
        Read();

        Solve();
    }
    return 0;
}
