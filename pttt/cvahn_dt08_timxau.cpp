#include <bits/stdc++.h>
using namespace std;

int k,i,j,ls;
string s,t;
set<string> x;

int main() {
    freopen("timxau.INP", "r", stdin);
    freopen("timxau.OUT", "w", stdout);
    cin >> k;
    cin >> s;
    ls = s.length();
    s = s + s;

    for (i=0; i<ls; i++) {
        t = "";
        for (j=i; j<i+ls; j++)
            t = t + s[j];
        x.insert(t);
    }

    if (k > x.size()) cout << -1;
    i = 0;
    for (auto itr=x.begin(); itr!=x.end(); itr++) {
        if (i == k-1) {
            cout << *itr;
            return 0;
        }
        i++;
    }
}
