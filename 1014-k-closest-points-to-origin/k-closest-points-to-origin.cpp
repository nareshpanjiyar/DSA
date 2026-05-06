class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,vector<int>>> pq;

        for(auto &N : points){
            int dist = N[0] * N[0] + N[1] * N[1];
            pq.push({dist,N});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back({pq.top().second});
            pq.pop();
        }


        return ans;
    }
};