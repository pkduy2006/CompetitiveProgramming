#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e4 + 1;

vector<int> Prime;
bool mark[N];

void Build(int t)
{
    mark[0] = false;
    mark[1] = false;
    for(int i = 2; i <= t; i++)
        mark[i] = true;

    for(int i = 2; i <= t; i++)
    {
        if(mark[i] == true)
        {
            for(int j = i * i; j <= t; j+=i)
                mark[j] = false;
        }
    }

    for(int i = 1; i <= t; i++)
    {
        if(mark[i] == true)
            Prime.push_back(i);
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, res = 0;
    cin >> n;
    Build(n);

    for(int i = 0; i < Prime.size() - 1; i++)
    {
        for(int j = i + 1; j < Prime.size(); j++)
        {
            if(Prime[i] * Prime[j] <= n)
                res = max(res, Prime[i] * Prime[j]);
        }
    }

    cout << res;

    return 0;
}
