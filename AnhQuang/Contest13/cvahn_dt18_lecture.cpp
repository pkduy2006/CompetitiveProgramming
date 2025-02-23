#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n;
long long res;
pair<int, int> a[N];

int sui_lec(int start_time)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if(a[mid].first < start_time)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("LECTURE.inp","r",stdin);
    freopen("LECTURE.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a + 1, a + 1 + n);

    for(int i = 1; i <= n; i++)
    {
        int idx = sui_lec(a[i].second);
        res += (n - idx + 1);
    }
    
    cout << res;

    return 0;
}
