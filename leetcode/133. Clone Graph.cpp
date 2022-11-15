    void addNode(int val, map<int, Node*> &nodeMap)
    {
        Node *nbr = new Node(val);
        nodeMap.insert(pair<int, Node*>(val, nbr));
    }
    Node* traverse(Node* node, set<int> &visitedMap, map<int, Node*> &nodeMap)
    {
        if(visitedMap.find(node->val) != visitedMap.end()) return nullptr;

        if (nodeMap.find(node->val) == nodeMap.end()) addNode(node->val, nodeMap);        

        for (Node *neighbor : node->neighbors)
        {
            if (nodeMap.find(neighbor->val) == nodeMap.end()) addNode(neighbor->val, nodeMap);
            nodeMap.at(node->val)->neighbors.push_back(nodeMap.at(neighbor->val));
        }
        visitedMap.insert(node->val);
        for (Node *neighbor : node->neighbors) traverse(neighbor, visitedMap, nodeMap);

        return nodeMap.at(1);
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL) return nullptr;

        set<int> visitedMap;
        map<int, Node*> nodeMap;
        return traverse(node, visitedMap, nodeMap);
    }
