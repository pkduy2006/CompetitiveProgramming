#include <iostream>
using namespace std;
const int nm = 1e4 + 1;
string a, b, c, t[nm], du;
long long sl;
bool ss(string a, string b)
{
    while (a.length() < b.length())
        a = '0' + a;
    while (a.length() > b.length())
        b = '0' + b;
    if (a >= b)
        return true;
    else
        return false;
}
string congsl(string a, string b) {
    string c = "";
    int nho = 0;
    while (a.length() < b.length())
        a = '0' + a;
    while (a.length() > b.length())
        b = '0' + b;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        nho = nho + a[i] + b[i] - 96;
        c = (char) (nho % 10 + 48) + c;
        nho = nho / 10;
    }
    c = (char) (nho % 10 + 48) + c;
    while (c[0] == '0' && c.length() > 1) c.erase(0, 1);
    return c;
}
string trusl(string a, string b)
{
    long long i, muon = 0;
    string c = "";
    while (a.length() < b.length())
        a = '0' + a;
    while (a.length() > b.length())
        b = '0' + b;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (a[i] - b[i] - muon >= 0)
        {
            c = (char) (a[i] - b[i] - muon + 48) + c;
            muon = 0;
        }
        else
        {
            c = (char) (a[i] + 10 - b[i] - muon + 48) + c;
            muon = 1;
        }
    }
    while (c[0] == '0' && c.length() > 1) c.erase(0, 1);
    return c;
}
string chiaslsl(string a, string b)
{
    string c = "";
    long long i;
    t[0] = '0';
    for (int i = 1; i <= 10; i++)
        t[i] = congsl(t[i - 1], b);
    for (int i = 0; i < a.length(); i++) {
        du += a[i];
        sl = 0;
        while (ss(du, t[sl]) == true)
            sl++;
        c = c + (char)(sl - 1 + 48);
        du = trusl(du, t[sl - 1]);
    }
    while (c[0] == '0' && c.length() > 1)
        c.erase(0, 1);
    return c;
}
int main()
{
    freopen("TONGHIEU.inp","r",stdin);
    freopen("TONGHIEU.out","w",stdout);
    cin >> a >> b;
    string sss = "";
    sss.push_back('2');
    cout << chiaslsl(congsl(a,b), sss) << endl << chiaslsl(trusl(a,b), sss) ;
    return 0;
}
