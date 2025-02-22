#include <bits/stdc++.h>
using namespace std;

const int nm = 1e5+1;
int n,p,s,b1;
string a,b,c,c1,c2;
map <string,int> ma,mb;

int main () {
    cin >> n >> p >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ma[a] = 0;
    }
    for (int i = 1; i <= p; i++) {
        cin >> b >> b1;
        mb[b] = b1;
    }
    for (int i = 1; i <= s; i++) {
        cin >> c >> c1 >> c2;
        if (ma.find(c) != ma.end() && c2 == "AC") ma[c] += mb[c1];
    }
    for (auto it = ma.begin(); it != ma.end(); it++)
        cout << (*it).first << ' ' << (*it).second << endl;
    return 0;
}
