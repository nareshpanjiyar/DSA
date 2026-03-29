class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int m =accounts.size();
        int n = accounts[0].size();
        int maxi = 0;

        for(int i = 0;i < m; i++){
            int opt1 = 0;
            for(int j = 0; j < n; j++){
                opt1 += accounts[i][j];
            }

            maxi = max(maxi ,opt1);
        }
        return maxi;
    }
};