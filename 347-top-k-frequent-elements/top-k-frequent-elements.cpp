class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        for(auto &N : nums) mp[N]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> minHeap;

        for(auto &X : mp){
            minHeap.push({X.second,X.first});

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> ans;

        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return ans;
    }
};