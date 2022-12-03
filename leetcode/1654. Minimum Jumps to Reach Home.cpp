    const int border = 6000;
    struct node
    {   
        bool isBack;
        int idx;
        node(bool _back, int _idx) : isBack(_back), idx(_idx) {}
    };
    void addNode(node cur, int a, int b, set<int> &visited, queue<node> &nodeQueue, int &nextTurn)
    {
        if (visited.find(cur.idx + a) == visited.end() && cur.idx + a < border)
        {
            nodeQueue.push(node(true, cur.idx + a));
            visited.insert(cur.idx + a);
            nextTurn++;
        }
        if (visited.find(cur.idx - b) == visited.end() && cur.idx - b > 0 && cur.isBack)
        {
            nodeQueue.push(node(false, cur.idx - b));
            nextTurn++;
        }
    }  
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int> visited;
        for (int idx : forbidden) visited.insert(idx);
        queue<node> nodeQueue;
        if (visited.find(0) != visited.end()) return -1;
        visited.insert(0);
        if (x == 0) return 0;

        int turn = 0, toProcess = 0 , nextTurn = 0;
        addNode(node(true, 0), a, b, visited, nodeQueue, toProcess);

        while(not(nodeQueue.empty()))
        {
            turn++;
            for (int i = 0; i < toProcess; i++)
            {
                node cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur.idx == x) return turn;
                addNode(cur, a, b, visited, nodeQueue, nextTurn);
            }
            toProcess = nextTurn;
            nextTurn = 0;
        }

        return -1;
    }
