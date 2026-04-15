class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int totalWords = words.size();

        unordered_map<string, int> wordCount;
        for (string w : words) wordCount[w]++;

        // we try from 0 to wordLen-1
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> window;

            for (int right = i; right + wordLen <= s.length(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (wordCount.find(word) != wordCount.end()) {
                    window[word]++;
                    count++;

                    // if extra word comes → shrink window
                    while (window[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // valid window
                    if (count == totalWords) {
                        result.push_back(left);

                        // move window ahead
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    // reset window
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};