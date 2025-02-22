#include <bits/stdc++.h>
#define ll long long
#define task "numjoin"

using namespace std;

int n,i;
vector <string> A;

bool comp(string l, string r)
{
    ll x = stoll(l+r);
    ll y = stoll(r+l);
    return (x > y);
}

int main()
{
    freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    cin >> n;
    A.resize(n);
    for (i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end(),comp);
    for (i = 0; i < n; i++){
        cout << A[i];
    }
    return 0;
}
