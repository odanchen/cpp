class Solution {
public:
void processString(stack<string> &stackTrace, string &s) {
    if (s == "." or s == "") return;
    if (s == "..") {
        if (!stackTrace.empty()) stackTrace.pop();
    } else stackTrace.push(s);
}
    string simplifyPath(string path) {
        stack<string> stackTrace;
        int left = 0, right;
        while (left < path.size()) {
            right = path.find_first_of('/', ++left);
            string s = right == -1 ? path.substr(left) : path.substr(left, right - left);
            processString(stackTrace, s);
            left = right;
        }
        vector<string> simplePath(stackTrace.size());
        for (int i = stackTrace.size() - 1; i >= 0; i--) {
            simplePath[i] = stackTrace.top();
            stackTrace.pop();
        }
        string ans;
        for (auto it = simplePath.begin(); it != simplePath.end(); it++) {
            ans.append("/");
            ans.append(*it);
        }
        return ans.empty() ? "/" : ans;
    }
};
