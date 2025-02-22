#include <iostream>
using namespace std;

long long m, val;
string a, b, c, prod;

bool cmp (string a, string b) {
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    if (a > b) return true;
    else return false;
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

void BigNumSmallNumDiv (string a, long long b) {
    for (int i = 0; i < (int)a.length(); i++) {
        val = val * 10 + a[i] - 48;
        val %= b;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c >> m;
    prod = BigNumBigNumMul(a,b);
    if (cmp(BigNumBigNumMul(a,c),prod)) prod = BigNumBigNumMul(a,c);
    if (cmp(BigNumBigNumMul(b,c),prod)) prod = BigNumBigNumMul(b,c);
    BigNumSmallNumDiv(prod,m);
    cout << val;
    return 0;
}
