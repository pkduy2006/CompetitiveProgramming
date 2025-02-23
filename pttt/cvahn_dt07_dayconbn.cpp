#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4 + 5;
const ll oo = 1e9;
const int MOD = 1e9 + 7;

bool check;
vector<int> v;

int cnt, j, i, a[N], subsum, sumc;

main()
{
    freopen("dayconbn.inp","r",stdin);
    freopen("dayconbn.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = n; i >= 1; i--)
        if(sum % i == 0){
            subsum =  sum / i;
            int sumc = 0;
            int cnt = 0;
        for(int j = 1; j <= n; j++){
            sumc += a[j];
            if(sumc == subsum){
                sumc = 0;
                cnt++;
            }
        }
        if(cnt == i){
            cout << i;
            return 0;
        }
    }
    return 0;
}
