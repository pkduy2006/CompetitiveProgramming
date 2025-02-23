#include <bits/stdc++.h>
using  namespace std;

bool check;
int n, i;
string val, gcd, lcm;
vector <string> v;

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
string BigNumBigNumMul (string a, string b) {
    int val, check = 0;
    string ans;
    if (a[0] == '-') {
        check++;
        a.erase(0,1);
    }
    if (b[0] == '-') {
        check++;
        b.erase(0,1);
    }
    for (int i = 0; i < (int)a.length()/2; i++)
        swap(a[i],a[(int)a.length() - 1 - i]);
    for (int i = 0; i < (int)b.length()/2; i++)
        swap(b[i],b[(int)b.length() - 1 - i]);
    for (int i = 0; i < (int)(a.length() + b.length()); i++)
        ans.push_back('0');
    for (int i = 0; i < (int)a.length(); i++) {
        val = 0;
        for (int j = 0; j < (int)b.length(); j++) {
            val += (ans[i+j] - 48 + (a[i] - 48) * (b[j] - 48));
            ans[i+j] = (char)(val % 10 + 48);
            val /= 10;
        }
        ans[i+(int)b.length()] += val;
    }
    for (int i = 0; i < (int)ans.length()/2; i++)
        swap(ans[i],ans[(int)ans.length() - 1 - i]);
    while (ans[0] == '0' && (int)ans.length() > 1)
        ans.erase(0,1);
    if (check % 2 != 0) ans = '-' + ans;
        return ans;
}
string BigNumBigNumDiv (string a, string b) {
    string ans, t[11];
    val.clear();
    t[0] = "0";
    for (int i = 1; i <= 10; i++)
        t[i] = BigNumAdd(t[i-1],b);
    int times;
    for (int i = 0; i < (int)a.length(); i++) {
        val += a[i];
        times = 0;
        while (cmp(val,t[times])) times++;
        ans += (char)(times - 1 + 48);
        val = BigNumSub(val,t[times-1]);
    }
    while (ans[0] == '0' && (int)ans.length() > 1)
        ans.erase(0,1);
    return ans;
}

string GCD (string a, string b) {
    BigNumBigNumDiv(a,b);
    string r = val;
    while (r != "0") {
        a = b, b = r;
        BigNumBigNumDiv(a,b);
        r = val;
    }
    return b;
}
int main()
{
    freopen("uclnsl.inp","r",stdin);
    freopen("uclnsl.out","w",stdout);
    string a,b;
    cin>>a>>b;
    cout<<GCD(a,b);
    return 0;
}
