#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 25;
int a[N], n, sum = 0, res = 0;
vector<int> gc;

bool check(int m)
{
    int total = 0;

    for(int i = 1; i <= n; i++)
    {
        total += a[i];

        if(total == m)
            total = 0;
    }

    if(total != m && total != 0)
        return false;

    return true;
}

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
}

void Solve()
{
    for(int i = 1; i <= sqrt(abs(sum)); i++)
    {
        if(sum % i == 0)
        {
            gc.push_back(i);
            gc.push_back(-i);

            if(i * i != sum)
            {
                gc.push_back(sum / i);
                gc.push_back(- sum / i);
            }
        }
    }

    sort(gc.begin(), gc.end());

    for(int i = 0; i < gc.size(); i++)
    {
        if(check(gc[i]) && sum / gc[i] > 0)
            res = max(res, sum / gc[i]);
    }

    if(sum == 0)
    {
        int cnt = a[1], idx = 2, ans = 0;

        while(idx <= n)
        {
            cnt += a[idx];

            if(cnt == 0)
            {
                cnt = a[idx + 1];
                idx++;
                ans++;
            }

            idx++;
        }

        if(cnt == 0)
            res = max(res, ans);

    }

    cout << res;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
