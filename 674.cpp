// Problem Link: https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

Approach: Dynamic Programming

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,0);

        dp[0] = 1;
        for(int i = 1; i < n ; i++){
            if(nums[i] > nums[i-1]){
                dp[i] = dp[i-1] + 1;
            }
            else dp[i] = 1;
        }

        int sabse_bada = dp[0];
        for(int i = 1; i < n ; i++){
            sabse_bada = max(sabse_bada,dp[i]);
        }

        return sabse_bada;
    }
};
