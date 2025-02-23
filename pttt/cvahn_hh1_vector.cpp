#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) setprecision(n) << fixed

const ll mxn = 1e4+1;

ll n,a[mxn],b[mxn],res;
pii sum[mxn];

ll calc(ll x, ll y)
{
    return x*x + y*y;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("vecto.inp","r",stdin); freopen("vecto.out","w",stdout);
    cin >> n;
    for (ll i=1; i<=n; i++){
        cin >> a[i] >> b[i];
    }
    sum[1] = {a[1], b[1]};
    for (ll i=2; i<=n; i++){
        sum[i] = {a[i], b[i]};
        //cout << i<<":\n";
        for (ll j=1; j<i; j++){
            if (calc(a[i] + sum[j].fi, b[i] + sum[j].se) > calc(sum[i].fi, sum[i].se)){
                sum[i] = {a[i] + sum[j].fi, b[i] + sum[j].se};
                //cout << j << ' ';
            }
        }
        //cout << calc(sum[i].fi, sum[i].se)<<'\n';
    }
    res = 0;
    for (ll i=1; i<=n; i++){
        res = max(res, calc(sum[i].fi, sum[i].se));
    }
    cout << res;
    return 0;
}
