class Solution {
public:

    bool solve(vector<int>& arr, int start, vector<int>& visited) {

        // out of bound
        if(start < 0 || start >= arr.size()) {
            return false;
        }

        // already visited
        if(visited[start]) {
            return false;
        }

        // reached 0
        if(arr[start] == 0) {
            return true;
        }

        visited[start] = 1;

        // forward jump
        bool right = solve(arr, start + arr[start], visited);

        // backward jump
        bool left = solve(arr, start - arr[start], visited);

        return right || left;
    }

    bool canReach(vector<int>& arr, int start) {

        vector<int> visited(arr.size(), 0);

        return solve(arr, start, visited);
    }
};