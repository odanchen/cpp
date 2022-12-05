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
    bool isBipartite(vector<vector<int>>& graph) {
        vector<node*> nodes(graph.size());
        set<node*> visited;
        for (int i = 0; i < nodes.size(); i++) nodes[i] = new node;
        for (int i = 0; i < nodes.size(); i++)
        {
            for (int direction : graph[i]) 
            {
                nodes[i]->directions.push_back(nodes[direction]);
            }
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
