    string interpret(string command) {
        string ans = "";
        int idx = 0;
        while(idx < command.size())
        {
            if (command[idx] == 'G') ans += "G";
            else if (command[idx] == '(' && command[idx + 1] == ')')
            {
                ans += "o"; idx++;
            }
            else
            {
                ans += "al"; idx += 3;
            }
            idx++;
        }
        return ans;
    }
