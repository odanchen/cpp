   bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(not(isalpha(s[i])) && not(isdigit(s[i]))) i++;
            if(not(isalpha(s[j])) && not(isdigit(s[j]))) j--;
            if ((isalpha(s[i]) || isdigit(s[i])) && (isalpha(s[j]) || isdigit(s[j])))
            {
                if (tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }
        }

        return true;
    }
