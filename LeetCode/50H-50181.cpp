//Leetcode
//Problem No 8: String to Integer (atoi)
//Difficulty level: Medium   

#include <bits/stdc++.h>
using namespace std;

class Solution  {
public:
        int myAtoi(string s)    {
            int i = 0, n = s.size();
            while(i < n && s[i] == ' ')
                i++;
            int sign = 1;
            if(i < n && s[i] == '-' || s[i] == '+')   {
                if(s[i] == '-')
                    sign = -1;
                i++;
            }
            long long answer = 0;
            while(i < n && '0' <= s[i] && s[i] <= '9')  {
                answer = answer * 10 + (s[i] - '0');
                i++;
                if(sign * answer < INT_MIN) {
                    answer = INT_MIN;
                    break;
                }
                if(sign * answer > INT_MAX) {
                    answer = INT_MAX;
                    break;
                }
            }
            return sign * answer;
        }
}solution;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cout << solution.myAtoi("42") << '\n';
    cout << solution.myAtoi(" -042") << '\n';
    cout << solution.myAtoi("1337c0d3") << '\n';
    cout << solution.myAtoi("0-1") << '\n';
    cout << solution.myAtoi("words and 987") << '\n';
    cout << solution.myAtoi("-91283472332") << '\n';
    
    return 0;
}