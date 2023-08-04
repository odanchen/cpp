class Solution {
public:
    struct Node {
        vector<Node *> nextNodes;
        vector<string> words;

        Node() : nextNodes(26, nullptr) {}
    };

    void addWord(string &word, Node *root) {
        for (char c: word) {
            if (root->nextNodes[c - 'a'] == nullptr) root->nextNodes[c - 'a'] = new Node;
            root = root->nextNodes[c - 'a'];
            root->words.push_back(word);
        }
    }

    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        sort(products.begin(), products.end());
        auto root = new Node, copy = root;
        vector<vector<string>> ans;
        for (string &word: products) addWord(word, root);
        for (char c: searchWord) {
            if (copy->nextNodes[c - 'a'] == nullptr) break;
            copy = copy->nextNodes[c - 'a'];
            if (copy->words.size() < 3) ans.push_back(copy->words);
            else ans.push_back({copy->words[0], copy->words[1], copy->words[2]});
        }
        while (ans.size() < searchWord.size()) ans.emplace_back();
        return ans;
    }
};
