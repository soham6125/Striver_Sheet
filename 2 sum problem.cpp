class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > v;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i = 0;
        int j = v.size()-1;
        while(i < j)
        {
            int sum = v[i].first + v[j].first;
            if(sum == target)
            {
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);
                break;
            }
            else if(sum < target) i++;
            else j--;
        }
        return ans;
    }
};