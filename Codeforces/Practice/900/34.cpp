// Codeforces Round 990 (Div. 2) B. Replace Character
// https://codeforces.com/problemset/problem/2047/B

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int ntests, n, res, standard;
string s, restr;

void solve() {
    cin >> n >> s;

    standard = 1;
    res = INF;
    restr = "";
    for(int i = 1; i <= n; i++)
        standard *= i;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < s.size(); j++) {
            string a = s;
            a[i] = a[j];
            map<int, char> mp;
            set<char> check;
            for(int k = 0; k < a.size(); k++) 
                mp[a[k]]++;
            int cnt = 1;
            for(char k = 'a'; k <= 'z'; k++) {
                if(check.find(k) == check.end()) {
                    for(int l = 1; l <= mp[k]; l++)
                        cnt *= l;
                    check.insert(k);
                }
            }
            //cout << a << ' ' << cnt << '\n';
            if(res > standard / cnt) {
                res = standard / cnt;
                restr = a;
            }
        }
    }
    cout << restr << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}