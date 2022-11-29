    struct Node
    {
        vector<Node*> neighbors;
    };
    void dfs(Node *cur, set<Node*> &visited)
    {
        if (visited.find(cur) != visited.end()) return;

        visited.insert(cur);
        for (Node* neighbor : cur->neighbors) dfs(neighbor, visited);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        vector<Node*> computers(n);
        for (int i = 0; i < computers.size(); i++) computers[i] = new Node;
        set<Node*> visited;

        for (vector<int> pair : connections)
        {
            computers[pair[0]]->neighbors.push_back(computers[pair[1]]);
            computers[pair[1]]->neighbors.push_back(computers[pair[0]]);
        }

        int cnt = 0;
        for (Node *computer : computers)
        {
            if (visited.find(computer) == visited.end())
            {
                cnt++;
                dfs(computer, visited);
            }
        }

        return cnt - 1;
    }
