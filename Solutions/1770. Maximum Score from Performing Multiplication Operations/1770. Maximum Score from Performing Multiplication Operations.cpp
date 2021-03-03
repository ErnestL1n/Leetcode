class Solution {
public:
    int maximumScore(vector<int>& a, vector<int>& b) {
        const int n = a.size();
        const int m = b.size();
        static int dp[1010][1010];
        memset(dp, 0, sizeof dp);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                int k = i - j;
                dp[i][j] = dp[i+1][j+1] + b[i]*a[j];
                dp[i][j] = max(dp[i][j], dp[i+1][j] + b[i]*a[n-k-1]);
            }
        }
        return dp[0][0];
    }
};



class Solution {
public:
    int dp[1001][1001] = {};
    int dfs(vector<int>& nums, vector<int>& mults, int l, int i) {
        if (i >= mults.size())
            return 0;
        if (!dp[l][i]) {
            int r = nums.size() - 1 - (i - l);
            dp[l][i] = max(nums[l] * mults[i] + dfs(nums, mults, l + 1, i + 1), 
                nums[r] * mults[i] + dfs(nums, mults, l, i + 1));
        }
        return dp[l][i];
    }
    int maximumScore(vector<int>& nums, vector<int>& mults) {
        return dfs(nums, mults, 0, 0);
    }
};



// OJ: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
// Author: github.com/lzl124631x
// Time: O(M^2)
// Space: O(M^2)
class Solution {
    int memo[1001][1001] = {};
    int dfs(vector<int> &A, vector<int> &M, int i, int j) {
        if (j == M.size()) return 0;
        if (memo[j][i]) return memo[j][i];
        return memo[j][i] = max(A[i] * M[j] + dfs(A, M, i + 1, j + 1), A[A.size() - j + i - 1] * M[j] + dfs(A, M, i, j + 1));
    }
public:
    int maximumScore(vector<int>& A, vector<int>& M) {
        return dfs(A, M, 0, 0);
    }
};