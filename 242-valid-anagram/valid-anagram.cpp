class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp;

        for(auto n : s){
            mp[n]++;
        }

        for(auto N : t){
            mp[N]--;
            if(mp[N] < 0) return false;
        }

        

        return true;
    }
};