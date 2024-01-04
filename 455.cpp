// Problem Link: https://leetcode.com/problems/assign-cookies/
Approach : 2-pointer approach

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j = 0, cnt = 0;
        int n = g.size(), m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i < n and j < m){
            if(g[i]<=s[j]){
                cnt++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return cnt;
    }
};
