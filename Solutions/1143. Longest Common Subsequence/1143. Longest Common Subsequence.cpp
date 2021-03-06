//bottom up
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<short>> dp(n1+1,vector<short>(n2+1));
        for(int i=1;i<=n1;++i)
            for(int j=1;j<=n2;++j){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        return dp[n1][n2];
    }
};


//two rows
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<short>> dp(2,vector<short>(1+n2));
        for(int i=1;i<=n1;++i)
            for(int j=1;j<=n2;++j){
                if(s1[i-1]==s2[j-1])
                    dp[i%2][j]=1+dp[(i-1)%2][j-1];
                else
                    dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
            }
        return dp[n1%2][n2];
    }
};

//space optimization , less space taken , but the OJ punished one the time 
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<int> dp(n2+1);
        int pre_left_up,pre_up;
        for(int i=1;i<=n1;++i){
            pre_left_up=0;
            for(int j=1;j<=n2;++j){
                pre_up=dp[j];
                dp[j]=max({dp[j-1],pre_up,pre_left_up+(s1[i-1]==s2[j-1])});
                pre_left_up=pre_up;
            }
        }
        return dp[n2];
    }
};

//top down
class Solution {
public:
    int longestCommonSubsequence(string& s1, string& s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<short>> dp(n1+1,vector<short>(n2+1,-1));
        return lcs(dp,s1,s2,n1,n2);
    }
    short lcs(vector<vector<short>>& dp,string& s1,string& s2,int i,int j){
        if(i==0 or j==0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i-1]==s2[j-1])
            return dp[i][j]=1+lcs(dp,s1,s2,i-1,j-1);
        else
            return dp[i][j]=max(lcs(dp,s1,s2,i,j-1),lcs(dp,s1,s2,i-1,j));
    }
};