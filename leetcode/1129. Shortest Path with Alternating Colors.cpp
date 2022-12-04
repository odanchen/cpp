    const char red = 'R';
    const char blue = 'B';
    const char neither = 'N';

    struct Node
    {
        struct Edge
        {
            Node* finish;
            char color;
            bool visited = false;
            Edge(Node* _finish, int _color) : finish(_finish), color(_color) {}
        };
        int path = -1;
        vector<Edge*> edges;
    };

    struct pathNode
    {
        Node* node;
        char color;
        pathNode(Node* _node, char _color) : node(_node), color(_color) {}
    };

    void addNodes(pathNode cur, queue<pathNode> &nodeQueue, int &nextTurn)
    {
        for (Node::Edge* edge : cur.node->edges)
        {
            if (edge->visited == false && edge->color != cur.color)
            {
                nextTurn++;
                edge->visited = true;
                nodeQueue.push(pathNode(edge->finish, edge->color));
            }
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<Node*> nodes(n);
        queue<pathNode> nodeQueue;
        int turn = 0, toVisit = 0, nextTurn = 0;

        for (int i = 0; i < nodes.size(); i++) nodes[i] = new Node;
        for (vector<int> curEdge : redEdges) nodes[curEdge[0]]->edges.push_back(new Node::Edge(nodes[curEdge[1]], red));
        for (vector<int> curEdge : blueEdges) nodes[curEdge[0]]->edges.push_back(new Node::Edge(nodes[curEdge[1]], blue));

        nodeQueue.push(pathNode(nodes[0], neither)); toVisit = 1;

        while(not(nodeQueue.empty()))
        {
            for (int i = 0; i < toVisit; i++)
            {
                pathNode cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur.node->path == -1) cur.node->path = turn;
                addNodes(cur, nodeQueue, nextTurn);
            }
            toVisit = nextTurn;
            nextTurn = 0;
            turn++;
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = nodes[i]->path;
        return ans;
    }
