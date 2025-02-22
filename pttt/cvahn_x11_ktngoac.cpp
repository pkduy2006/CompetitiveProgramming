#include <bits/stdc++.h>
using namespace std;

int dem;
bool ok,okok;
string s;

int main () {
    freopen ("KTNGOAC.inp", "r", stdin);
    freopen ("KTNGOAC.out", "w", stdout);
    while (cin >> s) {
        ok = 1, okok = 1, dem = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                ok = 0;
                cout << "KHONGHOPLE";
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < (int)s.length(); i++) {
                if (s[i] == '(') dem++;
                else dem--;
                if (dem < 0) {
                    okok = 0;
                    cout << "KHONGDUNG";
                    break;
                }   
            }
            if (okok) {
                if (dem == 0) cout << "DUNG";
                else cout << "KHONGDUNG";
            }
        }
        cout << endl;
    }
    return 0;
}
