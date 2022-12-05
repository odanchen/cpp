    struct node
    {
        bool isA = false;
        bool isB = false;
        vector<node*> directions;
    };
    void dfs(node* cur, bool isTeamA)
    {
        if ((cur->isA == false && isTeamA) || (cur->isB == false && isTeamA == false))
        {
            if (isTeamA) cur->isA = true;
            else cur->isB = true;

            for (node* neighbor : cur->directions)
            {
                dfs(neighbor, not(isTeamA));
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<node*> nodes(n);
        for (int i = 0; i < nodes.size(); i++) nodes[i] = new node;
        for (vector<int> pair : dislikes)
        {
            nodes[pair[0] - 1]->directions.push_back(nodes[pair[1] - 1]);
            nodes[pair[1] - 1]->directions.push_back(nodes[pair[0] - 1]);
        }

        for (node* cur : nodes)
        {
            if (cur->isA == false && cur->isB == false) dfs(cur, true);
        }
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i]->isA && nodes[i]->isB) return false;
        }

        return true;
    }
