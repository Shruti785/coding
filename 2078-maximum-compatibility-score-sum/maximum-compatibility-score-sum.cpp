class Solution {
public:

    vector<int> vectoint(vector<vector<int>> &v){
        int n = v.size();
        int m = v[0].size();
        vector<int> temp;
        for(int i = 0;i<n;i++){
            int num = 0;
            for(int j = m-1;j>=0;j--){
                num += v[i][j]*(1<<(m-j-1));
            }
            temp.push_back(num);
        }
        return temp;
    }

    vector<int> dp;

    int rec(int level,int n,int m,int mask,vector<int> &a,vector<int> &b){
        if(level >= n)return 0;
        if(dp[mask]!=-1)return dp[mask];
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(mask&(1<<i)){
                // untouched master
                int newmask = mask^(1<<i);
                int curr = 0;
                for(int j = 0;j<m;j++){
                    if((a[level]&(1<<j))==(b[i]&(1<<j)))curr++;
                }
                ans = max(ans,curr + rec(level+1,n,m,newmask,a,b));
            }
        }
        return dp[mask] = ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        int m = students[0].size();
        // students to int
        vector<int> a = vectoint(students);
        vector<int> b = vectoint(mentors);
        int mask = (1<<n)-1;
        dp.resize(300,-1);
        int x = rec(0,n,m,mask,a,b);
        return dp[mask];
    }
};