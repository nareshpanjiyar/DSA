class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        
        unordered_map<char,int> mp;
        for(auto n: magazine){
            mp[n]++;
        }

        for(auto c : ransomNote){
           
           if(mp[c] == 0){
            return false;
           }

           mp[c]--;
           
        }

        return true;
        
    }
};