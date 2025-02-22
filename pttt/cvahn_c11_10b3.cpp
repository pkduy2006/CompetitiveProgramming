#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
string s[N];
int n, cnt;
vector<string> math, second_math;
vector<double> num;

double convert(string tmp)
{
    double answer = 0, factor = 1;

    for(int i = tmp.size() - 1; i >= 0; i--)
    {   
        answer += (tmp[i] - '0') * factor;
        factor *= 10;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  freopen("input.txt","r",stdin);
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);

    while (cin >> s[n])
        n++;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == "+" || s[i] == "-" || s[i] == "/" || s[i] == "*")
            math.push_back(s[i]);
        else
            num.push_back(convert(s[i]));
    }

    while (!math.empty())
    {
        if(math.front() == "*")
        {
            double x = num.front();
            num.erase(num.begin());
            double y = num.front();
            num.erase(num.begin());
            math.erase(math.begin());
            num.insert(num.begin(), (double) x * y);
        }
        else if(math.front() == "/")
        {
            double x = num.front();
            num.erase(num.begin());
            double y = num.front();
            num.erase(num.begin());
            math.erase(math.begin());
            num.insert(num.begin(), (double) x / y);
        }
        else
        {
            double tmp = num.front();
            num.erase(num.begin());
            num.push_back(tmp);
            second_math.push_back(math.front());
            math.erase(math.begin());
        }
        cnt++;
    }
    double tmp = num.front();
    num.erase(num.begin());
    num.push_back(tmp);

    //for(int i = 0; i < second_math.size(); i++)
      //  cout << second_math[i] << ' ';
    //cout << '\n';

    double res = num.front();
    num.erase(num.begin());
    for(int i = 0; i < second_math.size(); i++)
    {
        if(second_math[i] == "+")
        {
            res += num.front();
            num.erase(num.begin());
        }
        else
        {
            res -= num.front();
            num.erase(num.begin());
        }
    }

    cout << fixed << setprecision(3) << res;

    return 0;
    
}
