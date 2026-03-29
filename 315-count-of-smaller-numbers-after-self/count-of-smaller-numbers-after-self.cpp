class Solution {
public:
    vector<int> count;
    
    void mergeSort(vector<pair<int,int>>& v, int low, int high){
        if(low >= high) return;

        int mid = (low + high) / 2;

        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);

        vector<pair<int,int>> temp;
        int i = low, j = mid + 1;

        int rightCount = 0;

        while(i <= mid && j <= high){
            if(v[j].first < v[i].first){
                temp.push_back(v[j]);
                rightCount++;
                j++;
            } else {
                count[v[i].second] += rightCount;
                temp.push_back(v[i]);
                i++;
            }
        }

        while(i <= mid){
            count[v[i].second] += rightCount;
            temp.push_back(v[i]);
            i++;
        }

        while(j <= high){
            temp.push_back(v[j]);
            j++;
        }

        for(int k = low; k <= high; k++){
            v[k] = temp[k - low];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count.resize(n, 0);

        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({nums[i], i});
        }

        mergeSort(v, 0, n - 1);

        return count;
    }
};