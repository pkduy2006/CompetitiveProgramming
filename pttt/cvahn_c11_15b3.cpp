#include <bits/stdc++.h>
using namespace std;

int n, k, res;

string convert(int x)
{
    string answer = "";
    while (x > 0)
    {
        if(x % 2 == 0)
            answer += '0';
        else 
            answer += '1';
        x /= 2;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

bool check(int x)
{
    string tmp = convert(x);
    int cnt = 0;
    
    for(int i = 0; i < tmp.size(); i++)
        cnt += (tmp[i] == '1');

    return cnt == k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);

    cin >> n >> k;
    
    for(int i = 1; i <= n; i++)
    {
        if(check(i))
            res++;
    }
    cout << res;

    return 0;
}
