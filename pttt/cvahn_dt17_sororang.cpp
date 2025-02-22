#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e7 + 25;
int a, b, res = 0;
bool mark[N];

int digit(int t)
{
    int ans = 0;
    while(t > 0)
    {
        int d = t % 10;
        ans += d * d;
        t /= 10;
    }

    return ans;
}

bool check(int m)
{
    set<int> c;

    while(true)
    {
        if(digit(m) == 1)
            return true;

        if(c.count(m) == 1 || !mark[m])
        {
            for(auto it = c.begin(); it != c.end(); it++)
                mark[*it] = false;

            return false;
        }

        c.insert(m);
        m = digit(m);
    }

    return false;
}

void Read()
{
    cin >> a >> b;
}

void Solve()
{
    fill(mark + 1, mark + N, true);
    for(int i = a; i <= b; i++)
    {
        if(!mark[i])
            continue;

        if(check(i))
            res++;
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
