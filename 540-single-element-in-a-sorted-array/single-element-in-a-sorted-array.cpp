class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {

        int low = 0, high = nums.size() -1;
        int xor1 = 0;
        while(low <= high){
            int mid = (low + high) / 2;

            xor1 ^= nums[low];

            if(nums[low] <= nums[mid]){
                low = low + 1;
            }
            else {
                if(nums[mid] <= nums[high]){
                    low = low + 1;
                }
            }

        }
        return xor1;
        
    }
};