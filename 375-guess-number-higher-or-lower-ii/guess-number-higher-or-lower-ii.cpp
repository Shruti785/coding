class Solution {
public:
    int solveUsingRec(int start, int end){
        if(start > end){
            return 0; //zero penalty since range ke bahar
        }
        if(start == end){
            //ek hi number hai so without penalty jeet jaenge
            return 0;
        }
        int ans = INT_MAX;
        for(int i = start; i <= end; i++){
            //worst case me i is wrong ans manke chalo aur penalty of i-$ consider karlo i.e add karliya "i"
            ans = min(ans, i + max(solveUsingRec(start, i-1), solveUsingRec(i+1, end)));
        }
        return ans;
    }

    int solveUsingMem(int start, int end, vector<vector<int>>&dp){
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int ans = INT_MAX;

        for(int i = start; i<=end; i++){
            ans = min(ans, i + max(solveUsingMem(start, i-1, dp), solveUsingMem(i+1, end, dp)));
        }
        return dp[start][end] = ans;
    }

    int solveUsingTab(int n){
        vector<vector<int>>dp(n+2, vector<int>(n+1, 0));
        for(int start = n; start >= 1; start--){
            for(int end = 1; end <= n; end++){
                
                if(start >= end){
                    //invalid range
                    continue;
                }
                int ans = INT_MAX;

                for(int i = start; i<=end; i++){
                    ans = min(ans, i + max(dp[start][i-1] , dp[i+1][end]));
                }  
                dp[start][end] = ans; 
            }
        }
        return dp[1][n];

    }
    int getMoneyAmount(int n) {
        int start = 1; 
        int end = n;
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solveUsingRec(start, end);
        // return solveUsingMem(start, end, dp);
        return solveUsingTab(n);
    }
};