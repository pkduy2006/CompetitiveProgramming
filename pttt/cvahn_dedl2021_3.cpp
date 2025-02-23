#include <bits/stdc++.h>
using namespace std;

string s;
bool mark[10];
vector<int> prime;
set<int> ss;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        int tmp = s[i] - '0';

        if(!mark[tmp] && (tmp == 2 || tmp == 3 || tmp == 5 || tmp == 7))
            prime.push_back(tmp);

        mark[tmp] = true;
    }

    for(int i = 0; i < prime.size(); i++)
        cout << prime[i] << ' ';

    return 0;
}
