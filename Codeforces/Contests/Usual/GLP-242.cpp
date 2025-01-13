// Hello 2025 B. Gorilla and the Exam
// https://codeforces.com/contest/2057/problem/B

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int ntests, n, k;
pair<int, int> a[N];

void solve()
{
    map<int, int> b;
    set<int> c;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        b[a[i].first]++;
    }

    for(int i = 1; i <= n; i++)
        a[i].second = b[a[i].first];
    sort(a + 1, a + 1 + n, [](const pair<int, int>& x, const pair<int, int>& y) {
        if(x.second == y.second)
            return x.first < y.first;
        return x.second < y.second;
    });
   // for(int i = 1; i <= n; i++)
      //  cout << a[i].first << ' ';
       // cout << '\n';
    for(int i = 1; i <= k; i++)
        a[i].first = a[n].first;
    for(int i = 1; i <= n; i++)
        c.insert(a[i].first);
    cout << c.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}