class Solution {
public:
    struct Node {
        string gene;
        vector<Node*> adjacents;
        Node(string _gene) : gene(_gene) {}
    };
    bool isMutation(string &s1, string &s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) if (s1[i] != s2[i]) cnt++;
        return cnt == 1;
    }
    void addNeighbors(Node* node, queue<Node*> &nodeQueue, set<Node*> &visited) {
        for (Node* neighbor : node->adjacents) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                nodeQueue.push(neighbor);
            }
        }
    }
    int minPath(Node* start, Node* finish) {
        set<Node*> visited({start});
        queue<Node*> nodeQueue;
        int turn = 0, toVisit;
        addNeighbors(start, nodeQueue, visited);
        
        while(not(nodeQueue.empty())) {
            turn++;
            toVisit = nodeQueue.size();
            for (int i = 0; i < toVisit; i++) {
                Node* cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur == finish) return turn;
                addNeighbors(cur, nodeQueue, visited);
            }
        }
        
        return -1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, Node*> geneNodes;
        for (string &s : bank) geneNodes[s] = new Node(s);
        if (geneNodes.find(start) == geneNodes.end()) geneNodes[start] = new Node(start);

        if(geneNodes.find(end) == geneNodes.end()) return -1;
        for (auto left = geneNodes.begin(); left != geneNodes.end(); left++) {
            for (auto right = left; right != geneNodes.end(); right++) {
                if (left != right && isMutation(left->second->gene, right->second->gene)) {
                    right->second->adjacents.push_back(left->second);
                    left->second->adjacents.push_back(right->second);
                }
            }
        }
        return minPath(geneNodes.at(start), geneNodes.at(end));
    }
};
