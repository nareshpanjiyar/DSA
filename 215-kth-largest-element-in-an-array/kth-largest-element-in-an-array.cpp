class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,vector<int>, greater<>> minHeap;

        for(auto &X : nums){
            minHeap.push(X);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        return minHeap.top();

    }
};