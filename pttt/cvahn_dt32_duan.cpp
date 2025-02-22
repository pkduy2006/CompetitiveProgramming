#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 11;
int s, n, res = 0;
pair<int, int> a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);

    cin >> n >> s;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        if(a[i].first > s)
            break;
        else
        {
            res++;
            s += a[i].second;
        }
    }

    cout << res;

    return 0;
}
