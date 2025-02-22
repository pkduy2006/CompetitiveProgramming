#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) fixed << setprecision(n)

const int mxn = 1e5+5;

map <int,bool> mm;
int n,a[mxn];

void prep()
{
    int cur = 1;
    mm[cur] = 1;
    int k = 2;
    while (true){
        cur += k;
        if (cur > (int)1e8) break;
        mm[cur] = 1;
        k++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("maxiseq.inp","r",stdin); 
    freopen("maxiseq.out","w",stdout);
    prep();
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    int ans = 0;
    int len = 0;
    for (int i=1; i<=n; i++){
        if (!mm[a[i]]){
            len = 0;
            continue;
        }
        if (a[i] < a[i-1]){
            len = 1;
        }
        else{
            len++;
        }
        ans = max(ans, len);
    }
    cout << ans;
    return 0;
}
