class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> metals(garbage.size()), glasses(garbage.size()), papers(garbage.size());
        metals[0] = count(garbage[0].begin(), garbage[0].end(), 'M');
        glasses[0] = count(garbage[0].begin(), garbage[0].end(), 'G');
        papers[0] = count(garbage[0].begin(), garbage[0].end(), 'P');
        
        for (int i = 1; i < garbage.size(); i++) {
            metals[i] = count(garbage[i].begin(), garbage[i].end(), 'M') + metals[i - 1];
            glasses[i] = count(garbage[i].begin(), garbage[i].end(), 'G') + glasses[i - 1];
            papers[i] = count(garbage[i].begin(), garbage[i].end(), 'P') + papers[i - 1];
        }
        int ans = 0, metalTravel = -1, glassTravel = -1, paperTravel = -1;
        for (int i = 0; i < garbage.size(); i++) {
            if (metalTravel == -1 and metals[i] == metals.back()) metalTravel = i;
            if (glassTravel == -1 and glasses[i] == glasses.back()) glassTravel = i;
            if (paperTravel == -1 and papers[i] == papers.back()) paperTravel = i;
        }
        ans = metals.back() + glasses.back() + papers.back();
        if (metalTravel != 0) ans += accumulate(travel.begin(), travel.begin() + metalTravel, 0);
        if (glassTravel != 0) ans += accumulate(travel.begin(), travel.begin() + glassTravel, 0);
        if (paperTravel != 0) ans += accumulate(travel.begin(), travel.begin() + paperTravel, 0);
        return ans;
    }
};
