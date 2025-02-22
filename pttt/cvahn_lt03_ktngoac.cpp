#include<bits/stdc++.h>
using namespace std;
int i,dem;
string s;
int main()
{
      while(cin>>s)
      {bool kt=0;
          for(i=0;i<(int)s.length();i++)
          if(s[i]!='('&&s[i]!=')') {cout<<"KHONGHOPLE"<<endl;kt=1;break;}
          if(kt==0) 
          {
            dem=0;
            for(i=0;i<(int)s.length();i++)
            if(s[i]=='(') dem++;
            else
            {
                if(dem==0) {dem=-1;break;}
                else dem--;
            }
            if(dem==0) cout<<"DUNG"<<endl;
            else cout<<"KHONGDUNG"<<endl;
           }
           } 
           return 0;
          }
