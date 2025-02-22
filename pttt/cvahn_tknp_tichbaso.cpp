#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 1e6 + 7;
int tich, kq, t, n, l, r, m;
bool b[N];
vector<int> a;

bool kt(int vt)
{
    tich = 1;
    for(int i = vt; i <= vt + 2; i++)
    {
        tich *= a[i];
        if(tich > n) return 0;
    }
    return 1;
}

void sangnt()
{
    for(int i =2; i <= sqrt(N); i++)
        if(b[i] == 0)
        for(int j = 2; i * j <= N; j++)
        b[i*j] = 1;
    a.pb(0);
    for(int i = 2; i <= N; i++)
        if(b[i] == 0) a.pb(i);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sangnt();
    cin >> t;
    for(int k = 1; k <= t; k++)
    {
        cin >> n;
        l = 1; r = a.size() - 1;
        kq = -1;
        while(l <= r)
        {
            m = (l + r)/2;
            if(kt(m)) {l = m + 1; kq = tich;}
            else r = m - 1;
        }
        cout << kq << '\n';
    }
    return 0;
}
