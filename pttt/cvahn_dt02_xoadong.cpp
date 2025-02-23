#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
char a[N][N];
int r, c, res;
vector<string> string_col;

bool check(int deleted)
{
    set<string> checker;

    for(int i = 0; i < string_col.size(); i++)
    {
        string tmp = "";
        for(int j = deleted; j < string_col[i].size(); j++)
            tmp += string_col[i][j];
        
        if(checker.count(tmp))
            return false;
        else
            checker.insert(tmp);
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("DELR.inp","r",stdin);
    freopen("DELR.out","w",stdout);

    cin >> r >> c;
    for(int i = 1; i <= r; i++)
    {
        string x;
        cin >> x;
        for(int j = 1; j <= c; j++)
            a[i][j] = x[j - 1];
    }

    for(int j = 1; j <= c; j++)
    {
        string tmp = "";
        for(int i = 1; i <= r; i++)
            tmp += a[i][j];

        string_col.push_back(tmp);
    }

    int left_value = 1, right_value = r - 1;
    while (left_value <= right_value)
    {
        int mid = (left_value + right_value) / 2;

        if(check(mid))
            left_value = mid + 1;
        else
            right_value = mid - 1;
    }
    

    cout << right_value;

    return 0;
}
