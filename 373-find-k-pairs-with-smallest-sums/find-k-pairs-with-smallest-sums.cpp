class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>> ans;

        if(nums1.empty() || nums2.empty()) {
            return ans;
        }

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        // Push first element of nums2 with every nums1[i]
        for(int i = 0; i < nums1.size() && i < k; i++) {

            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while(k-- && !pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            // Push next pair from same row
            if(j + 1 < nums2.size()) {

                pq.push({
                    nums1[i] + nums2[j + 1],
                    {i, j + 1}
                });
            }
        }

        return ans;
    }
};