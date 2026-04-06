class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;      // nums1 last valid element
        int j = n - 1;      // nums2 last element
        int k = m + n - 1;  // nums1 last position

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // agar nums2 me elements bache ho
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};