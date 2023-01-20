class Solution {
public:
    void dfs(vector<int>& nums, int start, vector<int>& sub, set<vector<int>>& res) {
    if (sub.size() >= 2) res.insert(sub);
    for (int i = start; i < nums.size(); i++) {
        if (sub.empty() || sub.back() <= nums[i]) {
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, res);
            sub.pop_back();
        }
    }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> sub;
        dfs(nums, 0, sub, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
