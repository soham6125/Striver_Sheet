class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++) {
            if(i == 0 or (i > 0 and nums[i] != nums[i-1])) {
            int sum = 0 - nums[i];
            int l = i + 1;
            int r = nums.size()-1;
            while(l < r) {
                if(nums[l] + nums[r] == sum) {
                    ans.push_back( {nums[i], nums[l], nums[r]} );
                    while(l < r and nums[l] == nums[l+1]) l++;
                    while(l < r and nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] > sum)
                    r--;
                else 
                    l++;
            }}
        }
        return ans;
    }
};