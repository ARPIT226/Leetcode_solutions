// Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/
Approach: Counting, Hashmap


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n  = nums.size();
        map <int,int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int ans = 0;

        for(auto i : mp){

            if(i.second == 1){
                return -1;
            }
            else if(i.second == 2){
                ans += 1;
            }
            else if(i.second>=3){
                ans += ceil(i.second/(3*1.0));
            }
        
        }

        return ans;
    }
};
