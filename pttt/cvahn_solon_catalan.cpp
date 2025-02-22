#include <iostream>
using namespace std;

long long n;

string trusl (string a, string b) {
    int muon = 0;
    string c;
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    for (int i = a.length()-1; i >= 0; i--) {
        if (a[i] - b[i] - muon >= 0) {
            c = (char)(a[i] - b[i] - muon + 48) + c;
            muon = 0;
        }
        else {
            c = (char)(a[i] - b[i] - muon + 58) + c;
            muon = 1;
        }
    }
    while (c[0] == '0' && c.length() > 1)
        c.erase(0, 1);
    return c;
}

string nhanslsl (string a, string b) {
    int nho;
    string c;
    for (int i = 0; i < a.length()/2; i++)
        swap(a[i], a[a.length() - 1 - i]);
    for (int i = 0; i < b.length()/2; i++)
        swap(b[i], b[b.length() - 1 - i]);    
    for (int i = 0; i < (a.length() + b.length()); i++)
        c.push_back('0');
    for (int i = 0; i < a.length(); i++) {
        nho = 0;
        for (int j = 0; j < b.length(); j++) {
            nho += (c[i+j] - 48 + (a[i] - 48) * (b[j] - 48));
            c[i+j] = (char)(nho % 10 + 48);
            nho /= 10;
        }
        c[i+b.length()] += nho;
    }
    for (int i = 0; i < c.length()/2; i++)
        swap(c[i], c[c.length() - 1 - i]);
    while (c[0] == '0' && c.length() > 1)
        c.erase(0, 1);
    return c;
}

string chiaslsn (string a, long long b) {
    string c;
    long long du = 0;
    for (int i = 0; i < (int)a.length(); i++) {
        du = du * 10 + a[i] - 48;
        c += (char)(du/b + 48);
        du %= b;
    }
    while (c[0] == '0' && (int)c.length() > 1)
        c.erase(0,1);
    return c;
}

string catalan (long long n) {
    string ans = "1";
    for (long long i = n + 2; i <= 2 * n; i++)
        ans = nhanslsl(ans, to_string(i));
    for (long long i = 2; i <= n; i++)
        ans = chiaslsn(ans,i);
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << catalan(n);
    return 0;
}
