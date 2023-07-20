class Solution {
public:
    class Trie {
    public:
        Trie() : root(new Node(nullptr)), cur(root) {}

        void insert(string &addition) {
            Node *temp = root;
            for (char c: addition) {
                if (temp->next[c - 'a'] == nullptr) temp->next[c - 'a'] = new Node(temp);
                temp = temp->next[c - 'a'];
            }
            temp->isEnd = true;
        }

        bool exists(char c) {
            return cur->next[c - 'a'] != nullptr;
        }

        void move(char c) {
            if (exists(c)) cur = cur->next[c - 'a'];
            word.push_back(c);
        }

        bool isWordEnd() {
            return cur->isEnd;
        }

        void moveBack() {
            cur = cur->prev;
            word.pop_back();
        }

        string getWord() {
            return word;
        }
        
        void removeWord() {
            cur->isEnd = false;
        }

    private:
        struct Node {
            bool isEnd;
            Node *prev;
            vector<Node *> next;

            explicit Node(Node *prev) : isEnd(false), next(26, nullptr), prev(prev) {}
        };

        Node *root;
        Node *cur;
        string word;
    };

    void search(vector<vector<char>> &board, Trie &trie, vector<string> &ans, int row, int col) {
        if (row < 0 or col < 0 or row >= board.size() or col >= board[row].size()) return;
        if (board[row][col] == '*' or !trie.exists(board[row][col])) return;

        char c = board[row][col];
        trie.move(c);
        if (trie.isWordEnd()) {
            ans.push_back(trie.getWord());
            trie.removeWord();
        }
        board[row][col] = '*';
        search(board, trie, ans, row + 1, col);
        search(board, trie, ans, row - 1, col);
        search(board, trie, ans, row, col + 1);
        search(board, trie, ans, row, col - 1);
        board[row][col] = c;
        trie.moveBack();
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie trie;
        for (string &word: words) trie.insert(word);
        vector<string> ans;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) search(board, trie, ans, row, col);
        }
        return ans;
    }
};
