class Solution {
public:
    struct Node {
        string word;
        vector<Node *> adj;

        explicit Node(string &word) : word(word) {}
    };

    bool isTransformation(string &s1, string &s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) cnt++;
        }
        return cnt == 1;
    }

    void addNeighbors(Node *node, queue<Node *> &nodeQueue, unordered_set<Node *> &visited) {
        for (Node *neighbor: node->adj) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                nodeQueue.push(neighbor);
            }
        }
    }

    int minPath(Node *start, Node *finish) {
        unordered_set < Node * > visited({start});
        queue<Node *> nodeQueue;
        int turn = 0;
        addNeighbors(start, nodeQueue, visited);

        while (!nodeQueue.empty()) {
            turn++;
            size_t toVisit = nodeQueue.size();
            for (int i = 0; i < toVisit; i++) {
                Node *cur = nodeQueue.front();
                nodeQueue.pop();
                if (cur == finish) return turn;
                addNeighbors(cur, nodeQueue, visited);
            }
        }

        return -1;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_map < string, Node * > wordBank;
        for (string &s: wordList) wordBank[s] = new Node(s);
        if (wordBank.find(beginWord) == wordBank.end()) wordBank[beginWord] = new Node(beginWord);

        if (wordBank.find(endWord) == wordBank.end()) return 0;
        for (auto left = wordBank.begin(); left != wordBank.end(); left++) {
            for (auto right = left; right != wordBank.end(); right++) {
                if (left != right && isTransformation(left->second->word, right->second->word)) {
                    right->second->adj.push_back(left->second);
                    left->second->adj.push_back(right->second);
                }
            }
        }
        return minPath(wordBank.at(beginWord), wordBank.at(endWord)) + 1;
    }
};
