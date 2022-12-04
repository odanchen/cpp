    struct Node
    {
        string word;
        vector<Node*> adjacents;
        Node(string _word) : word(_word) {}
    };
    bool isTransformation(string s1, string s2)
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, Node*> wordBank;
        for (string s : wordList) wordBank.insert(pair<string, Node*>(s, new Node(s)));
        if (wordBank.find(beginWord) == wordBank.end()) wordBank.insert(pair<string, Node*>(beginWord, new Node(beginWord)));

        if(wordBank.find(endWord) == wordBank.end()) return 0;
        map<string, Node*>::iterator left, right;
        for (left = wordBank.begin(); left != wordBank.end(); left++)
        {
            for (right = left; right != wordBank.end(); right++)
            {
                if (left != right && isTransformation(left->second->word, right->second->word))
                {
                    right->second->adjacents.push_back(left->second);
                    left->second->adjacents.push_back(right->second);
                }
            }
        }
        return minPath(wordBank.at(beginWord), wordBank.at(endWord)) + 1;
    }
