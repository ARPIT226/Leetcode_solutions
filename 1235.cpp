// Problem Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
Approach: Dynamic Programming (1-D Dp)
class Solution {
public:
     
    struct Job{
        int start, end, profit;
    };

    static int jobscomp(Job m, Job n){
        return  m.end < n.end;
    }

    int binary_search_prev_jobs( vector <Job> &jobs, int idx){
        int low = 0, high = idx-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(jobs[mid].end <= jobs[idx].start){
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return high;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        vector <Job> jobs(n);
        vector<int> dp(n,0);

        for(int i = 0; i < n; i++){
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }

        sort(jobs.begin(), jobs.end(), jobscomp);

        for(int i = 0 ; i < n; i++){
            if(i == 0){
                dp[i] = jobs[i].profit;
                continue;
            }

            int lia  = jobs[i].profit;
            int idx = binary_search_prev_jobs(jobs, i);

            if(idx != -1){
                lia += dp[idx];
            }

            int nhi_lia = dp[i-1];

            dp[i] = max(lia, nhi_lia);
        }

        return dp[n-1];
    }
};
