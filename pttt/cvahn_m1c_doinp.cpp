#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    string s="";
    cin >> n;
    while(n>0)
    {
        if(n%2==0)
            s+='0';
        else
            s+='1';
        n/=2;
    }
    for(int i=s.size()-1; i>=0; i--)
        cout << s[i];
    return 0;
}
