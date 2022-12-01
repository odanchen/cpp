    struct Node
    {
        vector<Node*> directions;
        int num;
    };
    void dfs(Node* cur, int &cnt, set<Node*> &visited, set<pair<int, int>> &originalRoads)
    {
        visited.insert(cur);

        for (Node* next : cur->directions)
        {
            if (visited.find(next) == visited.end())
            {
                visited.insert(next);
                pair<int, int> curRoad(next->num, cur->num);
                if (originalRoads.find(curRoad) == originalRoads.end()) cnt++;
                dfs(next, cnt, visited, originalRoads);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<Node*> nodes(n);
        set<pair<int, int>> originalRoads;
        for (int i = 0; i < nodes.size(); i++) 
        {
            nodes[i] = new Node;
            nodes[i]->num = i;
        }
        for (vector<int> duo : connections) 
        {
            nodes[duo[0]]->directions.push_back(nodes[duo[1]]);
            nodes[duo[1]]->directions.push_back(nodes[duo[0]]);

            pair<int, int> curRoad(duo[0], duo[1]);
            originalRoads.insert(curRoad);
        }
        set<Node*> visited;
        int cnt = 0;

        dfs(nodes[0], cnt, visited, originalRoads);
        return cnt;
    }
