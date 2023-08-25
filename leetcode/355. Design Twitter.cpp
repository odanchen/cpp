class Twitter {
public:
    struct User {
        vector<pair<int, int>> posts;
        unordered_map<int, User*> follows;

        User() = default;
    };

    unordered_map<int, User> users;
    int cnt = 0;

    Twitter() = default;

    void postTweet(int userId, int tweetId) {
        if (users.find(userId) == users.end()) users[userId] = User();
        users[userId].posts.emplace_back(cnt++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        if (users.find(userId) == users.end()) users[userId] = User();
        priority_queue<pair<int, int>> q(users[userId].posts.begin(), users[userId].posts.end());
        for (auto &[id, user]: users[userId].follows) {
            for (auto &val: user->posts) q.push(val);
        }
        for (int i = 0; i < 10 and !q.empty(); i++) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end()) users[followerId] = User();
        if (users.find(followeeId) == users.end()) users[followeeId] = User();

        users[followerId].follows[followeeId] = &users[followeeId];
    }

    void unfollow(int followerId, int followeeId) {
        users[followerId].follows.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
