#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 25;
int b[N], n, m;
vector<int> res;
pair<int, int> a[N];

bool check()
{
    int pos = 1;

    for(int i = 1; i <= m; i++)
    {
        bool review = false;
        for(int j = pos; j <= n; j++)
        {
            if(b[i] == a[j].first)
            {
                res.push_back(a[j].second);
                pos = j + 1;
                review = true;
                break;
            }
        }

        if(!review)
            return false;
    }

    return true;
}

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> b[i];
}

void Solve()
{
    if(!check())
        cout << 0;
    else
    {
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << ' ';
    }
}

main()
{
    freopen("daycon.inp","r",stdin);
    freopen("daycon.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
