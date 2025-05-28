class Solution {
public:
    // Recursion Solution
    int recur(vector<vector<int>>& matrix, int i, int j, int n, int m,
              vector<vector<int>>& dp) {
        if (j < 0 || j >= m)
            return 1e9;
        if (i == n - 1) {
            return matrix[i][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int ld = matrix[i][j] + recur(matrix, i + 1, j - 1, n, m, dp);
        int d = matrix[i][j] + recur(matrix, i + 1, j, n, m, dp);
        int rd = matrix[i][j] + recur(matrix, i + 1, j + 1, n, m, dp);

        return dp[i][j] = min({ld, d, rd});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;
        // Memoization
        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // for(int i=0;i<m;i++){
        //     mini = min(mini, recur(matrix,0,i,n,m));
        //     mini = min(mini, recur(matrix,0,i,n,m,dp));
        // }
        // Tabulation - Bottom up
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int mini = INT_MAX;
                for (int k = -1; k < 2; k++) {
                    if (j + k >= 0 && j + k <= m - 1)
                   mini = min(mini, matrix[i][j] + dp[i - 1][j + k]);
                }
                dp[i][j] = mini;
            }
        }
        
        for (int j = 0; j < m; j++)
            mini = min(mini, dp[n - 1][j]);

        return mini;
    }
};