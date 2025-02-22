#include <iostream>
using namespace std;

bool check;
string t, h, bnum, snum;

string BigNumAddition (string a, string b) {
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

string BigNumSubtraction (string a, string b) {
    int val,rem = 0;
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

string BigNumSmallNumDivision (string a, long long b) {
    int val = 0;
    string ans;
    for (int i = 0; i < (int)a.length(); i++) {
        val = val * 10 + a[i] - 48;
        ans += (char)(val/b + 48);
        val %= b;
    }
    while (ans[0] == '0' && (int)ans.length() > 1)
        ans.erase(0,1);
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t >> h;
    bnum = BigNumSmallNumDivision(BigNumAddition(t,h),2);
    snum = BigNumSubtraction(bnum,h);
    cout << bnum << endl << snum;
    return 0;
}
