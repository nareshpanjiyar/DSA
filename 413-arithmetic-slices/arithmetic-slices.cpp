class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;

        int curr = 0;   // current slices ending here
        int total = 0;  // total slices

        for(int i = 2; i < n; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr++;           // extend previous sequence
                total += curr;    // add to result
            } else {
                curr = 0;         // reset
            }
        }

        return total;
    }
};