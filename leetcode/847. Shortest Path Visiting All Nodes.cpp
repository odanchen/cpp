class Solution {
public:
    struct Node
    {
        int num;
        vector<Node*> directions;
    };
    typedef pair<Node*, int> conf;
    int findPathFrom(Node* node, int graphSize)
    {
        int ansMask = (1 << graphSize) - 1;
        
        set<conf> achieved;
        queue<conf> nodeQueue;
        
        int mask = 1 << node->num;
        conf curConf = conf(node, mask);
        nodeQueue.push(curConf);
        achieved.insert(curConf);
        
        int turn = 0, toProcess = 1, nextTurn = 0;
        
        while (not(nodeQueue.empty()))
        {
            for (int i = 0; i < toProcess; i++)
            {
                conf cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur.second == ansMask) return turn;
                for (Node* next : cur.first->directions)
                {
                    int nextMask = cur.second |  (1 << next->num);
                    if (achieved.find(conf(next, nextMask)) == achieved.end())
                    {
                        achieved.insert(conf(next, nextMask));
                        nodeQueue.push(conf(next, nextMask));
                        nextTurn++;
                    }
                }
            }
            turn++;
            toProcess = nextTurn;
            nextTurn = 0;
        }
        
        
        return 0;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        
        vector<Node*> nodes(graph.size());
        for (int i = 0; i < nodes.size(); i++)
        {
            nodes[i] = new Node;
            nodes[i]->num = i;
        }
        
        for (int i = 0; i < nodes.size(); i++)
        {
            for (int connection : graph[i])
            {
                nodes[i]->directions.push_back(nodes[connection]);
            }
        }
        int minPath = findPathFrom(nodes[0], graph.size());
        for (int i = 1; i < nodes.size(); i++)
        {
            minPath = min(findPathFrom(nodes[i], graph.size()), minPath);

        }
        return minPath;
    }
};
