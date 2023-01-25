class Solution {
public:
    void markNode(int &node, vector<int> &visited, vector<int> &edges, int color) {
        if (visited[node] == color) node = -1;
        else {
            visited[node] = color;
            node = edges[node];
        }
    }
    int getAns(int node1, int node2, vector<int> &visited) {
        if (node1 == node2) return node1;
        vector<int> ans;
        if (node1 != -1 && visited[node1] == 2) ans.push_back(node1);
        if (node2 != -1 && visited[node2] == 1) ans.push_back(node2);
        if (ans.size() == 0) return -1;
        if (ans.size() == 1) return ans[0];
        return min(ans[0], ans[1]);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> visited(edges.size());
        while (node1 != -1 || node2 != -1) {
            if (getAns(node1, node2, visited) != -1) return getAns(node1, node2, visited);
            if (node1 != -1) markNode(node1, visited, edges, 1);
            if (node2 != -1) markNode(node2, visited, edges, 2);
       }
       return -1;
    }
};
