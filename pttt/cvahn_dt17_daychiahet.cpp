#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 4e3 + 25;
pair<int, int> a[N];
int n;

void Read()
{
    cin >> n;
}

void Solve()
{
    a[1].first = 1;
    a[1].second = 1;

    for(int i = 2; i <= 4000; i++)
    {
        a[i].first = a[i - 1].first + (i - 1);

        a[i].second = a[i - 1].second + (i - 1) * (i - 2) + 1;

        while(a[i].second % i != 0)
            a[i].second++;
    }

    int l = 1, r = 4000, idx = 0;

    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(a[mid].first > n)
            r = mid - 1;
        else
        {
            l = mid + 1;
            idx = mid;
        }
    }

    cout << a[idx].second + (n - a[idx].first) * idx;
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
