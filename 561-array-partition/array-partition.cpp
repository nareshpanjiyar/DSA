class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());  // sort array
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i += 2){
            sum += nums[i];  // take min of each pair
        }
        
        return sum;
    }
};