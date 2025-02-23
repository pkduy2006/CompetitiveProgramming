#include <iostream>
#include <cmath>
using namespace std;

const int N = 201;
int m, n, a[N][N];
string dp[N][N];

bool StringCmp (string a, string b) {
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    if (a > b) return true;
    else return false;
}

string MAX (string a, string b) {
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    if (a > b) return a;
    else return b;
}

string BigNumBigNumMultiplication (string a, string b) {
    int val;
    string ans;
    for (int i = 0; i < (int) a.length () / 2; i++)
        swap (a[i], a[(int) a.length () - 1 - i]);
    for (int i = 0; i < (int) b.length() / 2; i++)
        swap(b[i], b[(int) b.length () - 1 - i]);    
    for (int i = 0; i < (int) (a.length () + b.length ()); i++)
        ans.push_back ('0');
    for (int i = 0; i < (int) a.length (); i++) {
        val = 0;
        for (int j = 0; j < (int) b.length (); j++) {
            val += (ans[i+j] - 48 + (a[i] - 48) * (b[j] - 48));
            ans[i+j] = (char) (val % 10 + 48);
            val /= 10;
        }
        ans[i + (int) b.length ()] += val;
    }
    for (int i = 0; i < (int) ans.length () / 2; i++)
        swap(ans[i], ans[(int) ans.length () - 1 - i]);
    while (ans[0] == '0' && (int) ans.length () > 1)
        ans.erase (0,1);
    return ans;
}

void BigNumSmallNumDivision (string a, long long b, string &ans, int &val) {
    for (int i = 0; i < (int) a.length (); i++) {
        val = val * 10 + a[i] - 48;
        ans += (char) (val/b + 48);
        val %= b;
    }
    while (ans[0] == '0' && (int) ans.length () > 1)
        ans.erase (0,1);
}

string BinToDec (long long num) {
    long long res = 0;
    int times = 1;
    while (num > 0) {
        res += (num % 10) * times;
        times *= 2;
        num /= 10;
    }
    return to_string (res);
}

string DecToBin (string num) {
    string res = "";
    while (StringCmp (num, "0")) {
        string ans = "";
        int val = 0;
        BigNumSmallNumDivision (num, 2, ans, val);
        res = to_string (val) + res;
        num = ans;
    }
    return res;
}

void PreCal () {
    for (int i = 1; i <= n; i++)
        dp[1][i] = BinToDec (a[1][i]);
    for (int i = 2; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = BigNumBigNumMultiplication (MAX (MAX (dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]), BinToDec (a[i][j]));
}

int main () {
    freopen ("Bai4.inp", "r", stdin);
    freopen ("Bai4.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    PreCal ();
    int pos = 1;
    for (int i = 2; i <= n; i++)
        if (StringCmp (dp[m][i], dp[m][pos])) pos = i;
    cout << DecToBin (dp[m][pos]);
    return 0;
}
