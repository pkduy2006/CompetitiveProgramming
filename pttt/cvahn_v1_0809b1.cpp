#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 16;
int n, m;
string res_1 = "1", res_2 = "1";
int A[N], B[N], res[N];

string multiply(string s1, string s2)
{
    fill(res, res + N, 0);
    int d1 = 0, d2 = 0;
    for (int i = s1.size() - 1; i >= 0; --i) A[++d1] = s1[i] - '0';
    for (int i = s2.size() - 1; i >= 0; --i) B[++d2] = s2[i] - '0';
    // Reserve two string and add digits into two arrays
    // Multiply from the back of two big-number
    for (int i = 1; i <= d1; ++i)
	{
        for (int j = 1; j <= d2; ++j)
        {
            int temp = (A[i] * B[j]);
            res[i + j - 1] += temp; // Multiply two digits and add to position [i + j - 1] in res;
            res[i + j] += (res[i + j - 1] / 10); // Accumulate the carry digit to the next position
            res[i + j - 1] %= 10; // Keep the last digit in this position
        }
    }
    int length = (res[d1 + d2]) ? d1 + d2: d1 + d2 - 1; // Get the real length of res
    string answer = "";
    for (int i = length; i >= 1; --i)
        answer += res[i] + '0';

    return answer;
}

string Sum(string a, string b)
{
    vector<int> result;
    while(a.size() < b.size())
        a = '0' + a;
    while(b.size() < a.size())
        b = '0' + b;
    int carry = 0, sum = 0;

    for(int i = a.size() - 1; i >= 0; i--)
    {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result.push_back(sum % 10);
        //cout << a[i] << ' ' << ' ' << b[i] << ' ' << sum << '\n';
    }

    reverse(result.begin(), result.end());
    if(carry > 0)
        result.insert(result.begin(), 1ll);
    string answer = "";
    for(int i = 0; i < result.size(); i++)
        answer += result[i] + '0';

    return answer;

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("lt.in","r",stdin);
    freopen("lt.ou","w",stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        res_1 = multiply(res_1, "2");
    for(int i = 1; i <= m; i++)
        res_2 = multiply(res_2, "3");
   // cout << res_1 << ' ' << res_2 << '\n';
    string tmp = Sum(res_1, res_2);
    cout << tmp.front();

    return 0;
}
