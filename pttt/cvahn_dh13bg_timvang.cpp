#include <bits/stdc++.h>

#define TASK "gold"

using namespace std;

main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen(TASK".inp","r",stdin); freopen(TASK".out","w",stdout);
    int n;
    long long ans = 1;
    cin>>n;
    for(int i=1;i<=n;i++) {
        ans = ans * i;
        while (ans%10==0) {
            ans = ans / 10;
        }
        ans = ans % int(1e5);
    }
    cout << ans%10;
    return 0;
}
