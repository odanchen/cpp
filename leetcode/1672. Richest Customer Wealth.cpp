    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(auto customer : accounts)
        {
            int curWealth = 0;
            for (int amount : customer) curWealth += amount;
            maxWealth = max(curWealth, maxWealth);
        }
        return maxWealth;
    }
