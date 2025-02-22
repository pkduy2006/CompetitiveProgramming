#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> Uoc;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(n==0)
    {
        cout << 0;
        return 0;
    }
    while(n>0)
    {
        Uoc.push_back(n%16);
        n/=16;
    }
    for(int i=Uoc.size()-1; i>=0; i--)
    {
        if(Uoc[i]==10)
            cout << 'A';
        else if(Uoc[i]==11)
            cout << 'B';
        else if(Uoc[i]==12)
            cout << 'C';
        else if(Uoc[i]==13)
            cout << 'D';
        else if(Uoc[i]==14)
            cout << 'E';
        else if(Uoc[i]==15)
            cout << 'F';
        else
            cout << Uoc[i];
    }
    return 0;
}
