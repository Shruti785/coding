class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (m + n != l) return false;
        
        unordered_map<string, bool> memo;
        
        function<bool(int, int, int)> helper = [&](int i, int j, int k) {
            if (k == l) return true;
            
            string key = to_string(i) + "," + to_string(j);
            if (memo.find(key) != memo.end()) return memo[key];
            
            bool ans = false;
            if (i < m && s1[i] == s3[k]) {
                ans = ans || helper(i + 1, j, k + 1);
            }
            
            if (j < n && s2[j] == s3[k]) {
                ans = ans || helper(i, j + 1, k + 1);
            }
            
            return memo[key] = ans;
        };
        
        return helper(0, 0, 0);
    }
};