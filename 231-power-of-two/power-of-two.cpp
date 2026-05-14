class Solution {
public:

    bool isPowerOfTwo(int n) {

        // negative and 0 are not powers of 2
        if(n <= 0){
            return false;
        }

        // base case
        if(n == 1){
            return true;
        }

        // if not divisible by 2
        if(n % 2 != 0){
            return false;
        }

        return isPowerOfTwo(n / 2);
    }
};