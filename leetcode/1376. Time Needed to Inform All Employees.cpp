    struct treeNode
    {
        vector<treeNode*> childNodes;
        int num;
    };
    void dfs(treeNode *root, int curTime, int &ans, vector<int> &informTime)
    {
        if (root->childNodes.empty())
        {
            ans = max(ans, curTime);
            return;
        }

        for (treeNode *child : root->childNodes) dfs(child, curTime + informTime[root->num], ans, informTime);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<treeNode*> treeNodes(n);
        for (int i = 0; i < treeNodes.size(); i++)
        {
            treeNodes[i] = new treeNode;
            treeNodes[i]->num = i;
        }
        for (int i = 0; i < manager.size(); i++) 
            if(i != headID) treeNodes[manager[i]]->childNodes.push_back(treeNodes[i]);

        int ans = 0;
        dfs(treeNodes[headID], 0, ans, informTime);
        return ans;
    }
