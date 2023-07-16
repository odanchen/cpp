class Solution {
public:
typedef vector<vector<string>> eqList;

    struct Node {
        bool visited = false;
        vector<pair<Node*, double>> ratios;
    };
    void clean(queue<Node*> &revert) {
        while (!revert.empty()) {
            auto cur = revert.front();
            revert.pop();
            cur->visited = false;
        }
    }

    double findAns(Node* begin, Node* end) {
        queue<Node*> revert({begin});
        queue<pair<Node*, double>> toProcess({{begin, 1.0}});
        begin->visited = true;
        while (!toProcess.empty()) {
            int cnt = (int) toProcess.size();
            for (int i = 0; i < cnt; i++) {
                auto cur = toProcess.front();
                toProcess.pop();
                for (auto &el : cur.first->ratios) {
                    if (!el.first->visited) {
                        el.first->visited = true;
                        revert.push(el.first);
                        toProcess.push({el.first, el.second * cur.second});
                        if (el.first == end) {
                            clean(revert);
                            return el.second * cur.second;
                        }
                    }
                }
            }
        }
        clean(revert);
        return -1;
    }
    vector<double> calcEquation(eqList& equations, vector<double>& values, eqList& queries) {
        unordered_map<string, Node*> variables;
        vector<double> ans;
        for (int i = 0; i < equations.size(); i++) {
            for (auto &var : equations[i]) {
                if (variables.find(var) == variables.end()) variables[var] = new Node;
            }
            variables[equations[i][0]]->ratios.push_back({variables[equations[i][1]], values[i]});
            variables[equations[i][1]]->ratios.push_back({variables[equations[i][0]], 1 / values[i]});
        }
        for (auto &query : queries) {
            if (variables.find(query[0]) == variables.end() or variables.find(query[1]) == variables.end()) {
                ans.push_back(-1);
            } else if (query[0] == query[1]) {
                ans.push_back(1);
            } else {
                ans.push_back(findAns(variables[query[0]], variables[query[1]]));
            }
        }
        return ans;
    }
};
