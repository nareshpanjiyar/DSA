class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        vector<int> ans;

        // Step 1: frequency count
        for(auto x : nums){
            mp[x]++;
        }

        // Step 2: max heap
        priority_queue<pair<int,int>> pq;

        for(auto it : mp){
            pq.push({it.second, it.first}); // {freq, number}
        }

        // Step 3: get top k
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};