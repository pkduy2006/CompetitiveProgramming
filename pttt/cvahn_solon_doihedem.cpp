#include <iostream>
#include <cmath>
using namespace std;

int a, b;
long long div_val;
string s, div_ans;

bool cmp (string a, string b) {
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    if (a > b) return true;
    else return false;
}

string BigNumAdd (string a, string b) {
    int val = 0;
    string ans = "";
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

string BigNumBigNumMul (string a, string b) {
    int val = 0;
    string ans = "";
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
    return ans;
}

void BigNumSmallNumDiv (string a, long long b) {
    div_val = 0, div_ans = "";
    for (int i = 0; i < (int)a.length(); i++) {
        div_val = div_val * 10 + a[i] - 48;
        div_ans += (char)(div_val/b + 48);
        div_val %= b;
    }
    while (div_ans[0] == '0' && (int)div_ans.length() > 1)
        div_ans.erase(0,1);
}

string to_Dec (string s) {
    string ans = "0", num = "1";
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        if (s[i] >= 'A' && s[i] <= 'F') 
            ans = BigNumAdd(ans, BigNumBigNumMul(to_string(s[i] - 55), num));
        else
            ans = BigNumAdd(ans, BigNumBigNumMul(to_string(s[i] - 48), num));
        num = BigNumBigNumMul(num,to_string(a));
    }
    return ans;
}

string from_Dec (string s) {
    string ans = "";
    while (cmp(s,"0")) {
        BigNumSmallNumDiv(s,b);
        if (div_val >= 10)
            ans = (char)(div_val + 55) + ans;
        else 
            ans = to_string(div_val) + ans;
        s = div_ans;
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    cin >> a >> b;
    if (s == "0") cout << 0;
    else cout << from_Dec(to_Dec(s));
    return 0;
}
