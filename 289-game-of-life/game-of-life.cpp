class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> temp = board;

        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int live = 0;

                for(int k = 0; k < 8; k++) {

                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if(temp[ni][nj] == 1) {
                            live++;
                        }
                    }
                }

                // Current cell alive
                if(temp[i][j] == 1) {

                    // Underpopulation or Overpopulation
                    if(live < 2 || live > 3) {
                        board[i][j] = 0;
                    }
                    else {
                        board[i][j] = 1;
                    }
                }
                else {

                    // Reproduction
                    if(live == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};