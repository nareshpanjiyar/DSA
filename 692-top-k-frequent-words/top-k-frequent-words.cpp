class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;
        for(auto w : words){
            mp[w]++;
        }

        vector<string> ans;

        while(k--){
            string best = "";
            int maxFreq = 0;

            for(auto &x : mp){
                // choose highest freq
                // if tie → lexicographically smaller
                if(x.second > maxFreq || 
                  (x.second == maxFreq && x.first < best)){
                    maxFreq = x.second;
                    best = x.first;
                }
            }

            ans.push_back(best);
            mp.erase(best); // remove used
        }

        return ans;
    }
};