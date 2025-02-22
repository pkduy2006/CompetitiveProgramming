#include <bits/stdc++.h>
#define int long long

using namespace std;

string add(string a, string b)
{
    int len = max(a.length(), b.length());
    while (a.length() < len) a = "0" + a;
    while (b.length() < len) b= "0" + b;
    string res = "";
    int rem = 0;
    for (int i= len - 1; i >= 0; i--)
    {
        int n1 = a[i] - '0';
        int n2 = b[i] - '0';
        int s = n1 + n2 + rem;

        char res_tmp = s % 10 + '0';
        res = res_tmp + res;
        rem = s / 10;
    }
    if (rem != 0)
        return char(rem + '0') + res;
    return res;
}

string luythua(string x, int n, int d)
{
    if (n == 0) return "1";
    else if (n == 1) return x;
    string res = x;
    for (int i=2; i<=n; i++)
    {
        string res_tmp = res;
        for (int j = 2; j <= d; j++)
        {
            res = add(res, res_tmp);
        }
    }
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    string lt2 = luythua("2", n, 2);
    string lt3 = luythua("3", m, 3);
    string S = add(lt2, lt3);
    cout<<S[0];

    return 0;
}
