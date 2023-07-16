class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        TreeNode* node = root;
        
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) node->children[c] = new TreeNode(c);
            node = node->children[c];
        }
        node->children['*'] = new TreeNode('*');
    }
    
    bool search(string word) {
        TreeNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) return false;
            node = node->children[c];
        }
        return node->children.find('*') != node->children.end();
    }
    
    bool startsWith(string prefix) {
        TreeNode* node = root;
        for (char c :  prefix) {
            if (node->children.find(c) == node->children.end()) return false;
            node = node->children[c];
        }
        return true;
    }
private:
    struct TreeNode {
        char letter;
        unordered_map<char, TreeNode*> children;
        TreeNode(char c) : letter(c) {}
    };
    TreeNode* root = new TreeNode('*');
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
