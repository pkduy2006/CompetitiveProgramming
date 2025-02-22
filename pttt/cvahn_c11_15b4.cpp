#include <bits/stdc++.h>
using namespace std;

string s;
int res;
string answer;

bool check(string tmp)
{
    int cnt = 0;

    for(int i = 0; i < tmp.size() / 2; i++)
    {
        if(tmp[i] != tmp[tmp.size() - i - 1])
            cnt++;
    }

    return cnt <= 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai4.inp","r",stdin);
    freopen("Bai4.out","w",stdout);

    cin >> s;
    for(int i = 0; i < s.size() / 2; i++)
    {
        if(s[i] != s[s.size() - i - 1])
            res++;
    }

    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            string tmp = s.substr(j, i);

            if(check(tmp))
            {
                if(answer == "")
                    answer = tmp;
                else
                {
                    if(answer.size() < tmp.size())
                        answer = tmp;
                    else if(answer.size() == tmp.size())
                    {
                        if(answer.front() < tmp.front())
                            answer = tmp;
                    }
                }
            }
        }
    }

    cout << res << '\n' << answer.size() << '\n' << answer;

    return 0;
}
