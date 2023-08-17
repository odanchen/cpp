class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urlMap[cnt] = longUrl;
        return prefix + to_string(cnt++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlMap[stoi(shortUrl.substr(prefix.size()))];
    }

    unordered_map<int, string> urlMap;
    int cnt = 0;
    const string prefix = "http://tinyurl.com/";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
