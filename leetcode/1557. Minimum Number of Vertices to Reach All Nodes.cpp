    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> inners(n);
        
        for(vector<int> edge : edges) inners[edge[1]] = true;
        vector<int> ans;
        for (int i = 0; i < inners.size(); i++) if (inners[i] == false) ans.push_back(i);
        return ans;
    }
