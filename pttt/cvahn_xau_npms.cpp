#include <bits/stdc++.h>
using namespace std;
string s,x,y;

int main() {
    getline(cin,s);
    while(s.length()%4>0) s='0' + s;
    while(s!="")
    {
        x=s.substr(0,4);
        s.erase(0,4);
        if(x=="0000") y+='0';
        if(x=="0001") y+='1';
        if(x=="0010") y+='2';
        if(x=="0011") y+='3';
        if(x=="0100") y+='4';
        if(x=="0101") y+='5';
        if(x=="0110") y+='6';
        if(x=="0111") y+='7';
        if(x=="1000") y+='8';
        if(x=="1001") y+='9';
        if(x=="1010") y+='A';
        if(x=="1011") y+='B';
        if(x=="1100") y+='C';
        if(x=="1101") y+='D';
        if(x=="1110") y+='E';
        if(x=="1111") y+='F';
    }
    while(y[0]=='0') y.erase(0, 1);
    cout << y;
    return 0;
}
