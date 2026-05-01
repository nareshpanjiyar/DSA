class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq;

         // push all elements
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        while(k > 1){
            pq.pop();
            k--;
        }

        return pq.top();

      
    }
};