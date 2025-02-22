#include <iostream>
using namespace std;

const int nm = 1e6+1;
bool check;
int i, m, k;
string n, f[nm], ans[nm]; 

bool cmp (string a, string b) {
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    if (a >= b) return true;
    else return false;
}

string BigNumAdd (string a, string b) {
    int val = 0;
    string ans;
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    for (int i = (int)a.length()-1; i >= 0; i--) {
        val += (a[i] + b[i] - 96);
        ans = (char)(val % 10 + 48) + ans;
        val /= 10;
    }
    ans = (char)(val + 48) + ans;
    while (ans[0] == '0' && (int)ans.length() > 1)
        ans.erase(0,1);
    return ans;
}

string BigNumSub (string a, string b) {
    int val, rem = 0;
    string ans;
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    if (a < b) {
        swap(a,b);
        check = 1;
    }
    for (int i = (int)a.length()-1; i >= 0; i--) {
        val = a[i] - b[i] - rem;
        if (val >= 0) {
            ans = (char)(val + 48) + ans;
            rem = 0;
        }
        else {
            ans = (char)(val + 58) + ans;
            rem = 1;
        }
    }
    while (ans[0] == '0' && (int)ans.length() > 1)
        ans.erase(0,1);
    if (check) ans = "-" + ans;
    return ans;
}

int main () {
    cin >> n;
    f[1] = "1", f[2] = "1";
    i = 2;
    do {
        i++;
        f[i] = BigNumAdd(f[i-1],f[i-2]);
    }
    while (cmp(n,f[i]));
    while (cmp(f[i],n)) i--;
    m = i, k = 0;
    while (n != "0") {
        if (cmp(n,f[m])) {
            n = BigNumSub(n,f[m]);
            ans[++k] = f[m];
        }
        m--;
    }
    for (i = k; i > 0; i--)
        cout << ans[i] << ' ';
    return 0;
}
