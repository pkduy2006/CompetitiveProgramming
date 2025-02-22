#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N = 1e7 + 25, INF = 1e13;
int n, k;
bool mark[N];
vector<int> prime, mprime;

void Build()
{
    fill(mark, mark + N, true);
    for(int i = 2; i <= sqrt(N); i++)
    {
        if(mark[i])
        {
            for(int j = i * i; j <= N; j += i)
                mark[j] = false;
        }
    }

    for(int i = 2; i <= N; i++)
    {
        if(mark[i])
            prime.push_back(i);
    }

    bool check = true;
    for(int i = 0; i < prime.size() - k + 1; i++)
    {
        int cnt = 1;
        check = true;
        for(int j = i; j <= i + k - 1; j++)
        {
            if(cnt > INF)
            {
                check = false;
                break;
            }
            cnt *= prime[j];
        }

        if(check)
            mprime.push_back(cnt);
    }
}

void Read()
{
    cin >> n >> k;
    Build();
}

void Solve()
{
    int l = 0, r = mprime.size() - 1, res = -1;

    if(mprime.front() > n)
    {
        cout << -1;
        return;
    }

    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(mprime[mid] <= n)
        {
            res = mprime[mid];
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << res;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("tichnt.inp","r",stdin);
    freopen("tichnt.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
