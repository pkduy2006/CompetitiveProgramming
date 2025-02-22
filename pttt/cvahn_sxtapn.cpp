// vegnim
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) fixed << setprecision(n)
#define task "tapn"

int n,m;
queue <pair<ll,int> > q;
vector <ll> ans;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    //freopen("inp.txt","r",stdin);
    cin >> n >> m;
    q.push(mp(1, 0));
    while (!q.empty()){
        ll val = q.front().fi; int h = q.front().se;
        q.pop();
        if (h == n){
            ans.pb(val);
            continue;
        }
        q.push(mp(2*val+1, h+1)); q.push(mp(3*val+1, h+1));
    }
    sort(ans.begin(), ans.end());
    cout << ans[m-1];
    return 0;
}
