#include <iostream>
using namespace std;

const int nm = 1e6+1;
int i, m, cnt;
string a, b, f[nm]; 

bool cmp_equal (string a, string b) {
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    if (a == b) return true;
    else return false;
}

bool cmp_greater (string a, string b) {
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    if (a > b) return true;
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

int main () {
    cin >> a >> b;
    f[1] = "1", f[2] = "1";
    i = 2;
    do {
        i++;
        f[i] = BigNumAdd(f[i-1],f[i-2]);
    }
    while (cmp_greater(b,f[i]) || cmp_equal(b,f[i]));
    while (cmp_greater(f[i],b)) i--;
    m = i, cnt = 0;
    while (cmp_greater(f[m],a) || cmp_equal(f[m],a))
        cnt++, m--;
    cout << cnt;
    return 0;
}
