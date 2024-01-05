// Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
Approach: Dynamic Programming (2-D dp)

class Solution {
public:

    int helper(int idx, int prev, vector<int> &nums, vector<vector<int>> &dp){
        
        if(idx == nums.size()){
            return 0;
        }

        if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        }

        int not_take  = 0 + helper(idx+1,prev,nums,dp);

        int take = 0;
        if(prev == -1 or nums[idx] > nums[prev]){
            take = 1 + helper(idx+1,idx,nums,dp);
        }

        return dp[idx][prev+1] = max(take, not_take);

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

        return helper(0,-1,nums,dp);
        
    }
};
