    struct Node
    {
        vector<Node*> directions;
        bool visited = false;
        int num;
    };
    bool safeConnections(Node *node, set<int> &safe)
    {
        for (Node *connection : node->directions) if (safe.find(connection->num) == safe.end()) return false;
        return true;
    }
    bool dfs(Node* node, set<int> &safe)
    {
        node->visited = true;
        if (node->directions.empty() || safeConnections(node, safe))
        {
            safe.insert(node->num);
            return true;
        }

        bool isSafe = true;
        for (Node *connection : node->directions)
        {
            if (connection->visited && safe.find(connection->num) == safe.end()) return false;
            else isSafe = isSafe && dfs(connection, safe);
        }
        if(isSafe)
        {
            safe.insert(node->num);
            return true;
        }
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<Node*> nodes(graph.size());
        for (int i = 0; i < nodes.size(); i++)
        {
            nodes[i] = new Node;
            nodes[i]->num = i;
        }
        for (int i = 0; i < graph.size(); i++)
        {
            for(int connection : graph[i])
            {
                nodes[i]->directions.push_back(nodes[connection]);
            }
        }

        set<int> safe;
        for (Node* node : nodes)
        {
            if (node->visited == false) dfs(node, safe);
        }
        vector<int> ans(safe.size());
        set<int>::iterator it = safe.begin();

        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = *it;
            it++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
