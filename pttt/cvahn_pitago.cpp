#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e8 + 1;
int n, res = 0;
bool mark[N];
vector<int> a;

void Read()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        mark[x * x] = true;
    }
}

void Solve()
{
    sort(a.begin(), a.end());

    for(int i = 0; i < n - 2; i++)
    {
        for(int j = i + 1; j < n - 1; j++)
        {
            if(a[i] * a[i] + a[j] * a[j] > N)
               continue;

            if(!mark[a[i] * a[i] + a[j] * a[j]])
                continue;

            res++;
        }
    }

    cout << res;
}

main()
{
    freopen("pitago.inp","r",stdin);
    freopen("pitago.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
