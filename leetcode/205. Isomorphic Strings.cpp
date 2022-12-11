class Solution {
public:
    bool isIsomorphic(string s, string t) {
       map<char, char> letterMap;
       set<char> occupiedLetters;

       for (int i = 0; i < s.size(); i++)
       {
           if(letterMap.find(s[i]) == letterMap.end()) 
           {
               if (occupiedLetters.find(t[i]) != occupiedLetters.end()) return false;
               
               letterMap.insert(pair<char, char>(s[i], t[i]));
               occupiedLetters.insert(t[i]);
           }
           else
           {
               if (letterMap.at(s[i]) != t[i]) return false;
           }
       }
       return true; 
    }
};
