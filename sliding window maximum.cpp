// https://leetcode.com/problems/sliding-window-maximum/ 

/* using multiset */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        int n = nums.size();
        for(int i=0;i<k;i++) s.insert(nums[i]);  
        vector<int> ans;
        ans.push_back(*s.rbegin());  
        for(int i=k;i<n;i++)
        {
            s.erase(s.find(nums[i-k]));   
            s.insert(nums[i]);
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};
