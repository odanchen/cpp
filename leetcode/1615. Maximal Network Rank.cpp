    struct node
    {
        int directions = 0;
        int num;
    };
    static bool comp(node a, node b)
    {
        return a.directions > b.directions;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<node> hash(n);
        for (int i = 0; i < hash.size(); i++) hash[i].num = i;
        set<vector<int>> roadCheck;
        for (vector<int> road : roads)
        {
            hash[road[0]].directions++;
            hash[road[1]].directions++;
            roadCheck.insert(road);
            swap(road[0], road[1]);
            roadCheck.insert(road);
        }
        sort(hash.begin(), hash.end(), comp);

        if(hash[0].directions != hash[1].directions)
        {
            int i = 1;
            while (i < hash.size() && hash[i].directions == hash[1].directions)
            {
                if (roadCheck.find(vector<int>{hash[0].num, hash[i].num}) == roadCheck.end())
                {
                    return hash[0].directions + hash[i].directions;
                }
                i++;
            }
            return hash[0].directions + hash[1].directions - 1;
        }
        
        int searchSize = 2;
        int idx = 2;
        while(idx < hash.size() && hash[idx].directions == hash[1].directions)
        {
            searchSize++;
            idx++;
        }

        for (int i = 0; i < searchSize - 1; i++)
        {
            for (int j = i + 1; j < searchSize; j++)
            {
                if (roadCheck.find(vector<int>{hash[i].num, hash[j].num}) == roadCheck.end())
                    return hash[i].directions + hash[j].directions;
            }
        }
        return hash[0].directions + hash[1].directions - 1;
    }
