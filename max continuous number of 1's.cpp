class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, cnt = 0;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i]==1 and nums[i+1]==1) cnt++;
            else if(nums[i]==1 and nums[i+1]!=1)
            {
                cnt++;
                if(cnt > ans) ans = cnt;
                cnt = 0;
            }
            else cnt = 0;
        }
        if(nums[n-1]==1)
        {
            cnt++;
            if(cnt > ans) ans = cnt;
        }
        return ans;
    }
};