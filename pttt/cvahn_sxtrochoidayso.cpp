#include <bits/stdc++.h>
#define task "seqgame"

using namespace std;

int n,i,j,ans,prv,x,trend;
vector <int> B,C;

int main()
{
    freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    cin >> n;
    B.resize(n); C.resize(n);
    for (i = 0; i < n; i++){
        cin >> B[i];
    }
    for (i = 0; i < n; i++){
        cin >> C[i];
    }
    sort(B.begin(),B.end()); sort(C.begin(),C.end());
    ans = INT_MAX;
    prv = abs(B[0]+C[0]);
    for (i = 0; i < n; i++){
        trend = 0;

        for (j = 0; j < n; j++){
            x = abs(B[i]+C[j]);
            if (x == 0){
                cout << 0;
                return 0;
            }
            ans = min(ans,x);
            if (prv < x){
                trend = 1;
            }
            else if (prv > x){
                trend = -1;
            }
            else{
                trend = 0;
            }
            if ((i != 0 || j != 0) && (trend == 1)){
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
