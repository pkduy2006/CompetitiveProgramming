#include <bits/stdc++.h>

using namespace std;

const int nm = 20000;

int n,i,A[nm],ans;

int main()
{
    freopen("noixich.inp","r",stdin); freopen("noixich.out","w",stdout);
    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> A[i];
    }
    sort(A+1,A+1+n);
    ans = 1;
    i = 1;
    while (i <= n && ans+i < n){
        if (A[i] == 1){
            i++;
            ans++;
        }
        else{
            A[i]--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
