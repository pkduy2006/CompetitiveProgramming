#include <bits/stdc++.h>
using namespace std;
long long tongchuso(long long b)
{
    long long tong=0, r;
    while(b!=0)
    {
    r=b%10;
    b=b/10;
    tong=tong+r;
    }
    return tong;
}
long long T,N;
string S,Q;
int main()
{
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>N;
        cin>>S;
            bool kt=0;
        Q="";
        for(int s=0; s<S.length(); s++)
        {
            Q=Q+S[s];
            if(tongchuso(stoll(Q))%2==0 && stoll(Q)%2==1){cout<<Q<<endl;kt=1;break;}
        }
        if(kt==0)cout<<-1<<endl;

    }
}
