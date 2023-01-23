class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in_degree(n+1,0);
        vector<int> out_degree(n+1,0);
        for (auto &t : trust) {
            out_degree[t[0]]++;
            in_degree[t[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (out_degree[i] == 0 && in_degree[i] == n - 1) 
                return i;
        
        }

       return -1;
 
    }
};
