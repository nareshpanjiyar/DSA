class Solution {
public:

    void merge(vector<int>& nums, int low ,int high){
        int mid = (low + high) /2;
        int len1= mid - low + 1;
        int len2 = high  - mid;

        int *first = new int[len1];
        int *second = new int[len2];
        int k = low;

        for(int i = 0; i <len1;i++){
            first[i] = nums[k++];
        }
        k= mid +1;
        for(int i = 0; i <len2;i++){
            second[i] = nums[k++];
        }

        int i = 0, j = 0;

        k = low;

        while(i < len1 && j < len2){
            if(first[i] < second[j]){
                nums[k++] = first[i++];
            }
            else{
                nums[k++] = second[j++];
            }
        }

        while(i < len1){
            nums[k++] = first[i++];
        }

        while(j < len2){
            nums[k++] = second[j++];
        }

        delete[] first;
        delete[] second;

    }

    void mergesort(vector<int>& nums,int low,int high){

        if(low >= high){
            return;
        }
        int mid = (low + high) / 2;
        mergesort(nums,low,mid);
        mergesort(nums,mid + 1,high);

        //merge
        merge(nums,low,high);

    }
    vector<int> sortArray(vector<int>& nums) {

        mergesort(nums,0,nums.size() -1);

        return nums;
        
    }
};