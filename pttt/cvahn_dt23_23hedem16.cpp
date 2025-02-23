#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<int> s1, s2, res;

vector<int> convert(string x)
{
    vector<int> s;

    for(int i = x.size() - 1; i >= 0; i--)
    {
        if('0' <= x[i] && x[i] <= '9')
            s.push_back(x[i] - '0');
        else if(x[i] == 'A')
            s.push_back(10);
        else if(x[i] == 'B')
            s.push_back(11);
        else if(x[i] == 'C')
            s.push_back(12);
        else if(x[i] == 'D')
            s.push_back(13);
        else if(x[i] == 'E')
            s.push_back(14);
        else
            s.push_back(15);
    }

    return s;
}

bool comparison(vector<int> x, vector<int> y)
{
    if(x.size() != y.size())
        return x.size() > y.size();
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] != y[i])
            return x[i] > y[i];
    }

    return true;
}

string calculate(vector<int> x, vector<int> y)
{
    int remember = 0;
    while (y.size() < x.size())
        y.push_back(0);
    
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] - y[i] - remember >= 0)
        {
            res.push_back(x[i] - y[i] - remember);
            remember = 0;
        }
        else
        {
            res.push_back(x[i] - y[i] - remember + 16);
            remember = 1;
        }
    }

   reverse(res.begin(), res.end());
   while (res.size() > 1 && res.front() == 0)
        res.erase(res.begin());
   
    string answer = "";
    for(int i = 0; i <= res.size() - 1; i++)
    {
        if(0 <= res[i] && res[i] <= 9)
            answer += (res[i] + '0');
        else if(res[i] == 10)
            answer += 'A';
        else if(res[i] == 11)
            answer += 'B';
        else if(res[i] == 12)
            answer += 'C';
        else if(res[i] == 13)
            answer += 'D';
        else if(res[i] == 14)
            answer += 'E';
        else
            answer += 'F';
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai2.inp","r",stdin);
    freopen("Bai2.out","w",stdout);
    //freopen("input.txt","r",stdin);

    cin >> a >> b;

    s1 = convert(a);
    s2 = convert(b);

    if(s1 == s2)
    {
        cout << 0;
        return 0;
    }

    if(comparison(s1, s2))
        cout << calculate(s1, s2);
    else
       cout << '-' << calculate(s2, s1);
    
    return 0;
}
