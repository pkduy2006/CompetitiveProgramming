#include <bits/stdc++.h>
#define PB push_back
#define ll long long
#define task "taoso"

using namespace std;

int t,i;
vector <string> ans;

bool comp(string l, string r)
{
    return (l+r > r+l);
}

void tachnt(int n)
{
    int org,i;
    org = n;
    i = 2;
    while (n > 1 && i <= sqrt(org)){
        if (n % i == 0){
            ans.PB(to_string(i));
            n /= i;
        }
        else{
            i++;
        }
    }
    if (n > 1)
        ans.PB(to_string(n));
}

int main()
{
    freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    cin >> t;
    if (t == 1){
        ans.PB("1");
    }
    else{
        tachnt(t);
    }
    sort(ans.begin(),ans.end(),comp);
    for (i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
    return 0;
}
