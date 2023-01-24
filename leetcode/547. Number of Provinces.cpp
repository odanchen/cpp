class Solution {
public:
    struct Node
    {
        vector<Node*> neighbors;
        int province = 0;
    };
    bool areLeft(vector<Node*> cities)
    {
        for (Node *city : cities) if(city->province == 0) return true;
        return false;
    }
    void dfs(Node* cur, int provinceNum, vector<Node*> &cities)
    {
        cur->province = provinceNum;
        for(Node *neighbor : cur->neighbors)
        {
            if (neighbor->province == 0) dfs(neighbor, provinceNum, cities);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<Node*> cities(isConnected.size());
        for (int i = 0; i < cities.size(); i++) cities[i] = new Node;
        for(int row = 0; row < isConnected.size(); row++)
        {
            for (int col = 0; col < isConnected[row].size(); col++)
            {
                if (row != col && isConnected[row][col] == 1) 
                    cities[row]->neighbors.push_back(cities[col]); 
            }
        }

        int provinceNum = 0;
        int idx = 0;
        while(areLeft(cities))
        {
            provinceNum++;

            while(cities[idx]->province != 0) idx++;
            dfs(cities[idx], provinceNum, cities);
        }
        return provinceNum;
    }
};
