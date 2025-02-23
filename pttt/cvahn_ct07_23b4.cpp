#include <bits/stdc++.h>
using namespace std;

const int N = 4e2 + 16;
string s1, s2, s3, res;
int f[N][N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Xauchung3.inp","r",stdin);
    freopen("Xauchung3.out","w",stdout);

    cin >> s1 >> s2 >> s3;

    s1 = ' ' + s1;
    s2 = ' ' + s2;
    s3 = ' ' + s3;
    for(int i = 1; i < s1.size(); i++)
    {
        for(int j = 1; j < s2.size(); j++)
        {
            for(int k = 1; k < s3.size(); k++)
            {
                if(s1[i] == s2[j] && s2[j] == s3[k])
                    f[i][j][k] = f[i - 1][j - 1][k - 1] + 1;
                else
                    f[i][j][k] = max({f[i - 1][j][k], f[i][j - 1][k], f[i][j][k - 1]});
            }
        }
    }

    cout << f[s1.size() - 1][s2.size() - 1][s3.size() - 1] << '\n';
    return 0;
}
