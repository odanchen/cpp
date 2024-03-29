/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void addNode(int val, map<int, Node*> &nodeMap)
    {
        Node *nbr = new Node(val);
        nodeMap.insert(pair<int, Node*>(val, nbr));
    }
    void traverse(Node* node, set<int> &visitedMap, map<int, Node*> &nodeMap)
    {
        if(visitedMap.find(node->val) != visitedMap.end()) return;

        if (nodeMap.find(node->val) == nodeMap.end()) addNode(node->val, nodeMap);        

        for (Node *neighbor : node->neighbors)
        {
            if (nodeMap.find(neighbor->val) == nodeMap.end()) addNode(neighbor->val, nodeMap);
            nodeMap.at(node->val)->neighbors.push_back(nodeMap.at(neighbor->val));
        }
        visitedMap.insert(node->val);
        for (Node *neighbor : node->neighbors) traverse(neighbor, visitedMap, nodeMap);

        return;
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL) return nullptr;

        set<int> visitedMap;
        map<int, Node*> nodeMap;
        traverse(node, visitedMap, nodeMap);
        return nodeMap.at(node->val);
    }
};
