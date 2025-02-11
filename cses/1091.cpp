// Concert Tickets 
// https://cses.fi/problemset/task/1091/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, m, h[N], t[N], res[N];
multiset<int> ticket;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        ticket.insert(h[i]);
    }
    for(int i = 1; i <= m; i++)
        cin >> t[i];
    
    for(int i = 1; i <= m; i++) {
        auto it = ticket.upper_bound(t[i]);
        if(it == ticket.begin()) 
            res[i] = -1;
        else {
            it--;
            res[i] = *it;
            ticket.erase(it);
        }
    }
    for(int i = 1; i <= m; i++)
        cout << res[i] << '\n';

    return 0;
}