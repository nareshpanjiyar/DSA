class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        vector<int> freq(20001, 0);  // range -10000 to 10000
        
        // store frequency
        for(int num : nums){
            freq[num + 10000]++;
        }
        
        int sum = 0;
        bool take = true;  // alternate pick
        
        for(int i = 0; i < 20001; i++){
            while(freq[i] > 0){
                
                if(take){
                    sum += (i - 10000);
                }
                
                take = !take;  // flip
                freq[i]--;
            }
        }
        
        return sum;
    }
};