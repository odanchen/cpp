    struct Node
    {
        vector<Node*> directions;
    };
    int add(int n) {return (n + 1) % 10;}
    int sub(int n) {return (n + 9) % 10;}
    string toStr(int n)
    {
        string ans; ans.resize(4);
        for (int i = 3; i >= 0; i--)
        {
            ans[i] = n % 10 + '0';
            n /= 10;
        }
        return ans;
    }
    void addDigitNeighbors(int digit, int idx, vector<Node*> &nodes, string &cur)
    {
        cur[digit] = (add(cur[digit] - '0') + '0');
        nodes[idx]->directions.push_back(nodes[stoi(cur)]);
        cur[digit] = (sub(cur[digit] - '0') + '0');
        cur[digit] = (sub(cur[digit] - '0') + '0');
        nodes[idx]->directions.push_back(nodes[stoi(cur)]);
        cur[digit] = (add(cur[digit] - '0') + '0');
    }
    void addNeighbors(vector<Node*> &nodes, int idx)
    {
        string cur = toStr(idx);
        for (int i = 0; i < 4; i++) addDigitNeighbors(i, idx, nodes, cur);
    }
    void insertNeighbors(Node* node, queue<Node*> &nodeQueue, set<Node*> &visited, int &nextTurn)
    {
        for (Node* neighbor : node->directions)
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                nodeQueue.push(neighbor);
                nextTurn++;
            }
        }
    }
    int minPath(Node* start, Node* finish, set<Node*> &visited)
    {
        queue<Node*> nodeQueue;
        int turn = 0, toVisit = 0, nextTurn = 0;
        visited.insert(start);
        insertNeighbors(start, nodeQueue, visited, toVisit);

        while(not(nodeQueue.empty()))
        {
            turn++;
            for (int i = 0; i < toVisit; i++)
            {
                Node* cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur == finish) return turn;
                insertNeighbors(cur, nodeQueue, visited, nextTurn);
            }
            toVisit = nextTurn;
            nextTurn = 0;
        }

        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        vector<Node*> nodes(10000);
        set<Node*> visited;
        for (int i = 0; i < nodes.size(); i++) nodes[i] = new Node;
        for (string deadEnd : deadends) visited.insert(nodes[stoi(deadEnd)]);
        
        if (visited.find(nodes[0]) != visited.end()) return -1;
        if (target == "0000") return 0;

        for (int i = 0; i < nodes.size(); i++) addNeighbors(nodes, i);
        return minPath(nodes[0], nodes[stoi(target)], visited);
    }
