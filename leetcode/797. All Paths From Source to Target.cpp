    struct Node
    {
        vector<Node*> neighbors;
        int num;
    };
    void addPermutation(Node *cur, set<Node*> visited, vector<int> curPath, Node *prev, vector<vector<int>> &ans, Node *end)
    {
        if (prev != NULL)
        {
            visited.insert(prev);
            curPath.push_back(prev->num);
        }

        if (cur == end)
        {
            curPath.push_back(cur->num);
            ans.push_back(curPath);
            return;
        }

        for (Node *neighbor : cur->neighbors)
        {
            addPermutation(neighbor, visited, curPath, cur, ans, end);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<Node*> nodes(graph.size());
        for (int i = 0; i < nodes.size(); i++)
        {
            nodes[i] = new Node;
            nodes[i]->num = i;
        }
        for (int i = 0; i < graph.size(); i++)
        {
            for (int direction : graph[i])
            {
                nodes[i]->neighbors.push_back(nodes[direction]);
            }
        }

        vector<vector<int>> ans;
        set<Node*> visited;
        addPermutation(nodes[0], visited, vector<int>{}, NULL, ans, nodes.back());
        return ans;
    }
