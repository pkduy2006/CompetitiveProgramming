#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 11;
int a, b;
bool mark[N];
vector<int> squarePrime;

void Build()
{
    for(int i = 2; i <= sqrt((int) 1e6); i++)
    {
        if(!mark[i])
        {
            for(int j = i * i; j <= (int) 1e6; j += i)
                mark[j] = true;
        }
    }

    for(int i = 2; i <= (int) 1e6; i++)
    {
        if(!mark[i])
            squarePrime.push_back(i * i);
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("psquare.inp","r",stdin);
    freopen("psquare.out","w",stdout);

    Build();

    cin >> a >> b;

    int x = lower_bound(squarePrime.begin(), squarePrime.end(), a) - squarePrime.begin();
    int y = upper_bound(squarePrime.begin(), squarePrime.end(), b) - squarePrime.begin() - 1;

    cout << y - x + 1;

    return 0;
}
