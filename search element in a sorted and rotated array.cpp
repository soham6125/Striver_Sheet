// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] == target){
            return 0;
        }
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int mid = l + (r - l) / 2;
            int leftNum = nums[l];
            int rightNum = nums[r];
            int midNum = nums[mid];
            if(leftNum == target) return l;
            if(rightNum == target) return r;
            if(midNum == target)return mid;
            if(midNum>leftNum){
                if(target<midNum && target > leftNum){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(target>midNum && target <rightNum){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }           
        }
        return -1;
    }
};