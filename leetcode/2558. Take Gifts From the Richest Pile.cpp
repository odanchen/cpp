class Solution {
public:
    long long pickGifts(vector<int> &gifts, int k) {
        long long total = reduce(gifts.begin(), gifts.end(), 0l);
        priority_queue<int> pq(gifts.begin(), gifts.end());
        for (int i = 0; i < k; i++) {
            int val = pq.top();
            pq.pop();
            int temp = floor(sqrt(val));
            total -= val - temp;
            pq.push(temp);
        }
        return total;
    }
};
