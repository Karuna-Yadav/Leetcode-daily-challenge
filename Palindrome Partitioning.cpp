class Solution {
public:
    void backtrack(string s, int start, vector<string>& partition, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(partition);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                partition.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, partition, res);
                partition.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partition;
        backtrack(s, 0, partition, res);
        return res;
    }
};
