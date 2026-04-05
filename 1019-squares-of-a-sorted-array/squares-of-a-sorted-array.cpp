class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();
        vector<int> neg;
        vector<int> pos;
       vector<int> ans;
        for(int i = 0; i < n; i++){
           
           if(nums[i] < 0){
            neg.push_back(pow(nums[i],2));
           }

           else{
            pos.push_back(pow(nums[i],2));
           }
        }
        reverse(neg.begin(),neg.end());
        int i =0,j = 0;
        int a = neg.size();
        int b = pos.size();

        while( i < a && j < b){

            if(neg[i] < pos[j]){
                ans.push_back(neg[i]);
                i++;
            }
            else{
                ans.push_back(pos[j]);
                j++;
            }
        }

        while(i < a) {
            ans.push_back(neg[i]); 
            i++;

        }
        while(j < b) {
            ans.push_back(pos[j]); 
            j++;
        }

        return ans;
        
        
    }
};