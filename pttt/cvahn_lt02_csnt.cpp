#include <bits/stdc++.h>
#define int long long
using namespace std;
bool mark[10000046];
vector<int> Prime;
const int INF = 1e7 + 9;
void Build()
{
    mark[1] = false;
    for(int i = 2; i <= INF; i++)
        mark[i] = true;
    for(int i = 2; i * i <= INF; i++)
    {
        if(mark[i] == true)
        {
            for(int j = i * i; j <= INF; j+=i)
                mark[j] = false;
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l, r;
    cin >> l >> r;
    Build();
    for(int i = l; i <= r; i++)
    {
        if(mark[i] == true)
            Prime.push_back(i);
    }
    cout << Prime.size() << '\n';
    for(int i = 0; i < Prime.size(); i++)
        cout << Prime[i] << ' ';
    return 0;
}
