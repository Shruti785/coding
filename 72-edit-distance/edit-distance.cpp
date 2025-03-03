class Solution {
public:
    int editdis(int m, int n, string &s1, string &s2, vector<vector<int>>& dp) {
        if (m == 0) return n;
        if (n == 0) return m;
        
        if (dp[m][n] != -1) return dp[m][n];
        
        if (s1[m-1] == s2[n-1]) {
            return dp[m][n] = editdis(m-1, n-1, s1, s2, dp);
        }
        
        return dp[m][n] = 1 + min({
            editdis(m, n-1, s1, s2, dp),  // Insert
            editdis(m-1, n-1, s1, s2, dp), // Replace
            editdis(m-1, n, s1, s2, dp)  // Delete
        });
    }
    
    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return editdis(m, n, s1, s2, dp);
    }
};