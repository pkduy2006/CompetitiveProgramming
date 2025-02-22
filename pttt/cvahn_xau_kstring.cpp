#include <bits/stdc++.h>
using namespace std;
int k,a[127];
string s,x;

int main()
{
    cin >> k >> s;
    for(int i =0; i< s.length(); i++)
        a[s[i]]++;
    for (int i =97; i < 123; i++)
        if(a[i] % k != 0)
    {
        cout <<-1;
        return 0;
    }
    x = "";
    for(int i = 97; i < 123; i++)
        if(a[i] > 0)
        for(int j = 1; j <= a[i]/k; j++)
            x += char(i);
    s = "";
    for (int i = 1; i<=k; i++) s = s+ x;
    cout << s;
}
