    struct Node
    {
        string gene;
        vector<Node*> adjacents;
        Node(string _gene) : gene(_gene) {}
    };
    bool isMutation(string s1, string s2)
    {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i]) cnt++;
        }
        return cnt == 1;
    }
    void addNeighbors(Node* node, queue<Node*> &nodeQueue, set<Node*> &visited, int &nextTurn)
    {
        for (Node* neighbor : node->adjacents)
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                nodeQueue.push(neighbor);
                nextTurn++;
            }
        }
    }
    int minPath(Node* start, Node* finish)
    {
        set<Node*> visited;
        queue<Node*> nodeQueue;
        int turn = 0, toVisit = 0, nextTurn = 0;
        visited.insert(start);
        addNeighbors(start, nodeQueue, visited, toVisit);
        
        while(not(nodeQueue.empty()))
        {
            turn++;
            for (int i = 0; i < toVisit; i++)
            {
                Node* cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur == finish) return turn;
                addNeighbors(cur, nodeQueue, visited, nextTurn);
            }
            toVisit = nextTurn;
            nextTurn = 0;
        }
        
        return -1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        map<string, Node*> geneNodes;
        for (string s : bank) geneNodes.insert(pair<string, Node*>(s, new Node(s)));
        if (geneNodes.find(start) == geneNodes.end()) geneNodes.insert(pair<string, Node*>(start, new Node(start)));

        if(geneNodes.find(end) == geneNodes.end()) return -1;
        map<string, Node*>::iterator left, right;
        for (left = geneNodes.begin(); left != geneNodes.end(); left++)
        {
            for (right = left; right != geneNodes.end(); right++)
            {
                if (left != right && isMutation(left->second->gene, right->second->gene))
                {
                    right->second->adjacents.push_back(left->second);
                    left->second->adjacents.push_back(right->second);
                }
            }
        }
        return minPath(geneNodes.at(start), geneNodes.at(end));
    }
