class Solution {
public:
    void backtrack(string s, string ip, int start, int count, vector<string>& res) {
    if (count == 4) {
        if (start == s.length()) {
            ip.pop_back();
            res.push_back(ip);
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (start + i > s.length()) {
            break;
        }
        string sub = s.substr(start, i);
        if (stoi(sub) <= 255 && (i == 1 || sub[0] != '0')) {
            ip += sub + '.';
            backtrack(s, ip, start + i, count + 1, res);
            ip.erase(ip.end() - i - 1, ip.end());
        }
    }
}
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
    string ip;
    backtrack(s, ip, 0, 0, res);
    return res;
    }
};
