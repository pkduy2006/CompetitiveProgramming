#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

typedef long long ll;

const int N = 1e6 + 5;
const int M = 1e3 + 5;
const int oo = 1e9;
const int MOD = 1e9 + 7;

int f, ans, prime[N], maxx, k, t, tong, a[N];

multiset<int> se;

main()
{
    freopen("XORSEQS.INP","r",stdin);
    freopen("XORSEQS.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;cin >> n;

    for(int i = 1; i <= n; i++)
         cin >> a[i];

    for(int i = 1; i <= n; i++)
        if(i * (n - i + 1) % 2 == 0)
            a[i] = 0;


    int ans = a[0];
    for(int i = 1; i <= n; i++)
        ans ^= a[i];

    cout << ans;
    return 0;
}


/*
3 3
4 2
10 7
1 1

3 3
4 4
5 5
6 6
*/
