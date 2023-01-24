class Solution {
public:
    int insertSign(int num, char sign)
    {
        if (sign == '+') return num;
        return -1 * num;
    }
    int myAtoi(string s) {
        char sign = '+';
        int idx = 0;
        while(s[idx] == ' ' && idx < s.size())
        {
            idx++;
        }
        if (s[idx] == '-' || s[idx] == '+')
        {
            sign = s[idx];
            idx++;
        }
        
        if(not(isdigit(s[idx]))) return 0;

        int ans = 0;
        while(idx < s.size() && isdigit(s[idx]) && idx < s.size())
        {
            if(ans < INT_MAX / 10) ans = ans * 10 + (s[idx] - '0');
            else if (ans == INT_MAX / 10)
            {
                if(s[idx] - '0' <= 7 && sign == '+') ans = ans * 10 + (s[idx] - '0');
                else if(s[idx] - '0' <= 7 && sign == '-') 
                {
                    ans = ans * 10 + (s[idx] - '0');
                }
                else if (sign == '+') return INT_MAX;
                else return INT_MIN;
            }
            else 
            {
                if (sign == '+') return INT_MAX;
                else return INT_MIN;
            }
            idx++;
        }

        return insertSign(ans, sign);
    }
};
