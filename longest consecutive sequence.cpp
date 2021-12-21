class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0, cnt = 0;
        for(int i=0 ; i<nums.size() ; i++) m[nums[i]] = 1;
        for(int i=0 ; i<nums.size() ; i++)
        {
            int num = nums[i];
            if(m[num-1] == 0)
            {
              cnt = 0;
              while(m[num])
              {
                  cnt++;
                  num++;
              }
              ans = max(ans , cnt);
            }
        }
        // ans = max(ans , cnt);
        return ans;
    }
};