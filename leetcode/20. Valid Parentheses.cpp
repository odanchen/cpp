    bool isValid(string s) 
    {
        stack<char> braces;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') braces.push(s[i]);
            else if (braces.empty() == false &&
                    ((braces.top() == '(' && s[i] == ')') ||
                    (braces.top() == '{' && s[i] == '}') ||
                    (braces.top() == '[' && s[i] == ']'))) braces.pop();
            
            else return false;
        }
        return braces.empty();
    }
