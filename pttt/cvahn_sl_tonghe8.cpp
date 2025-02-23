#include <bits/stdc++.h>
using namespace std;
string x,y;

string cong(string x, string y) {
    string a = x, b = y;
    while (a.length() < b.length()) a = "0" + a;
    while (a.length() > b.length()) b = "0" + b;
    string kq = "";
    int tmp, nho = 0;
    int i = a.length() - 1;
    while (i >= 0) {
        tmp = (a[i]-48) + (b[i]-48);
        if (nho == 1) tmp++;
        nho = 0;
        if (tmp >= 8) {
            nho = 1;
            tmp = tmp - 8;
        }
        kq = kq + char(tmp + 48);
        i--;
    }
    if (nho == 1) kq = kq + "1";
    reverse(kq.begin(), kq.end());
    return kq;
}

int main () {
    freopen("tongbp.inp","r",stdin);
    freopen("tongbp.out","w",stdout);
    cin >> x >> y;
    cout << cong(x,y);
}
