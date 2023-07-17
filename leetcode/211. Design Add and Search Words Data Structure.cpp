class WordDictionary {
public:
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char c : word) {
            if (node->children[c - 'a']) node = node->children[c - 'a'];
            else {
                node->children[c - 'a'] = new Node;
                node = node->children[c - 'a'];
            }
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return search(word, root, 0);
    }
private:
    struct Node {
        bool isEnd;
        vector<Node*> children;
        Node() : isEnd(false), children(26, NULL) {}
    };
    Node* root;
    
    bool search(string &word, Node* node, int idx) {
        while (idx < word.size()) {
            if (word[idx] != '.') {
                if (node->children[word[idx] - 'a'] == NULL) return false;
                else node = node->children[word[idx++] - 'a'];
            } else {
                for (char letter = 'a'; letter <= 'z'; letter++) {
                    word[idx] = letter;
                    if (search(word, node, idx)) return true;
                }
                word[idx] = '.';
                return false;
            }
        }
        return node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
