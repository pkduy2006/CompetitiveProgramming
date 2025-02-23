#include <bits/stdc++.h>
using namespace std;

string x, y, num, res = "0";
set<string> x_num;

string convert(int l, int r, string tmp)
{
    string answer = "";
    for(int i = l; i <= r; i++)
        answer += tmp[i];

    int idx = 0;
    string e = "";
    while (answer[idx] == '0' && idx < answer.size())
        idx++;
    for(int i = idx; i < answer.size(); i++)
        e += answer[i];
    return e;
}

bool comparison(string c, string d)
{   
    if(c.size() != d.size())
        return c.size() > d.size();
    for(int i = 0; i < d.size(); i++)
    {
        if(c[i] > d[i])
            return true;
    }

    return false;
}


void ss(string a)
{
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = i; j < a.size(); j++)
        {
            string b = convert(i, j, a);
            //cout << b << '\n';
            x_num.insert(b);
        }
    }
}

void ss2(string a)
{
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = i; j < a.size(); j++)
        {
            string b = convert(i, j, a);
            if(x_num.count(b))
            {   
               // cout << b << ' ' << res << '\n';
                if(comparison(b, res))
                {
                //    cout << b << '\n';
                    res = b;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("XAUCHUNGMAX.inp","r",stdin);
    freopen("XAUCHUNGMAX.out","w",stdout);
    //freopen("XAUCHU")

    cin >> x >> y;
    
    for(int i = 0; i < x.size(); i++)
    {
        if('0' <= x[i] && x[i] <= '9')
            num += x[i];
        else
        {
            if(num.size() != 0)
                ss(num);
           //cout << num << '\n';
            num = "";
        }
    }
    if(num.size() != 0)
        ss(num);
    num = "";
    //for(auto it = x_num.begin(); it != x_num.end(); it++)
      //  cout << (*it) << ' ';
    //cout << '\n';

    for(int i = 0; i < y.size(); i++)
    {
        if('0' <= y[i] && y[i] <= '9')
            num += y[i];
        else   
        {
            if(num.size() > 0)
                ss2(num);
            num = "";
        }
    }
    if(num.size() != 0)
        ss2(num);

    cout << res;

    //cout << '\n' << comparison("0004", "0007");

    return 0;
}
