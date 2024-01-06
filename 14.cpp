// Problem Link: https://leetcode.com/problems/longest-common-prefix/description/
Approach: strings

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        int n = strs.size();
        
        sort(strs.begin(), strs.end());

        string pehla = strs[0];
        string akhiri = strs[n-1];

        int mini = min(pehla.size(),akhiri.size());
        
        for(int i = 0; i < mini; i++){
            if(pehla[i] == akhiri[i]){
                ans += pehla[i];
            }
            else {
                break;
            }
        }
      
        return ans;
    }
};
