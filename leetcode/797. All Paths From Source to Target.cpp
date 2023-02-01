class Solution {
public:
    vector<vector<int>> ans;
    void addPermutation(vector<int> curPath, vector<vector<int>> &graph, int node)
    {
        curPath.push_back(node);
        if (node == graph.size() - 1) ans.push_back(curPath);
        for (int next : graph[node]) {
            addPermutation(curPath, graph, next);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        addPermutation(vector<int>(), graph, 0);
        return ans;
    }
};
