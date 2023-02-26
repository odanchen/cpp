class Solution {
public:
    struct Offer {
        int capital;
        int profit;
        Offer(int capital, int profit) : capital(capital), profit(profit) {}
        Offer() : capital(0), profit(0) {}
    };
    struct OfferGroup {
        priority_queue<int> profits;
        int capital;
        void push(int profit) {
            profits.push(profit);
        }
        int take() {
            int ans = profits.top();
            profits.pop();
            return ans;
        }
        bool empty() {
            return profits.empty();
        }
        OfferGroup(int capital) : capital(capital) {}
        OfferGroup(int capital, int profit) : capital(capital) {push(profit);}
    };
    void merge(vector<OfferGroup> &groups, vector<OfferGroup>::iterator end) {
        OfferGroup group((end - 1)->capital);
        for (auto it = groups.begin(); it != end; it++) {
            while(!it->empty()) group.push(it->take());
        }
        groups.erase(groups.begin(), end);
        groups.insert(groups.begin(), group);
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<Offer> offers(profits.size());
        for (int i = 0; i < profits.size(); i++) offers[i] = Offer(capital[i], profits[i]);
        sort(offers.begin(), offers.end(), [](Offer a, Offer b){return a.capital < b.capital;});

        int prev = -1;
        vector<OfferGroup> groups;
        for (Offer offer : offers) {
            if (offer.capital != prev) {
                groups.push_back(OfferGroup(offer.capital, offer.profit));
                prev = offer.capital;
            }
            else groups.back().push(offer.profit);
        }
            
        auto comp = [](OfferGroup a, OfferGroup b){return a.capital < b.capital;};
        for (int i = 0; i < k ; i++) {
            if (groups.empty() or groups[0].capital > w) return w;
            if (groups.size() > 1 and groups[1].capital <= w) {
                auto end = upper_bound(groups.begin(), groups.end(), OfferGroup(w), comp);
                merge(groups, end);
            }
            
            w += groups[0].take();
            if (groups[0].empty()) groups.erase(groups.begin());
        }
        return w;
    }  
};
