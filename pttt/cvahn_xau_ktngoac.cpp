#include <bits/stdc++.h>
using namespace std;
string s;
long long kt1,kt2, d1,d2,i,N;
int main()
{
    while(cin>>s)
    {
        d1=0; d2=0;
        kt1=0;kt2=1;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(') d1++;
            else if(s[i]==')') d2++;
            else {kt1=1;}
            if(d1<d2){kt2=0;}
        }
        if(kt1==1) cout<<"KHONGHOPLE"<<endl;
        else if(kt2==0 || d1!=d2) cout<<"KHONGDUNG"<<endl;
        else if(kt2==1 && d1==d2 ) cout<<"DUNG"<<endl;
    }
}
